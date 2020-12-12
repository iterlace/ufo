#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "include/library.h"
#include "include/logger.h"
#include "utils.h"
#include "constants.h"

using namespace std;


Ingot::Ingot() {
    this->height = randomNumber(10, 100);
    this->width = randomNumber(10, 100);
    this->depth = randomNumber(10, 500);
    this->density = randomNumber(19.3, 19.32);
}

Ingot::Ingot(double height, double width, double depth, double density) {
    this->height = height;
    this->width = width;
    this->depth = depth;
    this->density = density;
}

string Ingot::to_string() {
    return format("<Ingot(height=%.02f, width=%.02f, depth=%.02f, density=%.02f)>", height, width, depth, density);
}

double Ingot::getWeight() {
    return height/100 * width/100 * depth/100 * density;
}



void UFO::putIngot(Ingot ingot) {
    // TODO: log
    fprintf(stderr, "Got new ingot: %s\n", ingot.to_string().c_str());
    ingots.emplace_back(ingot);
    if (isIngotValid(&ingots.front())) {
        if (E-calculateEnergyCosts(&ingots.front())-ACCEPT_COST >= _EF)
            acceptIngot();
        else {
            double newDepth;
            // Energy, which will be used in the future
            const double energyToRemain = _EF - CUT_COST - ACCEPT_COST - DROP_COST;
            while((newDepth = calculateDepth(&ingots.front(), E-energyToRemain)) > 0.001) {
                cutIngot(newDepth);
                acceptIngot();
            }
            dropIngot();
            flyAway();
        }
    } else {
        dropIngot();
    }
}

void UFO::rotateIngot() {
    // TODO: log
    fprintf(stderr, "Rotate\n");
    E -= ROTATE_COST;
    swap(ingots.front().width, ingots.front().height);
}

void UFO::turnIngot() {
    // TODO: log
    fprintf(stderr, "Turn\n");
    E -= TURN_COST;
    swap(ingots.front().width, ingots.front().depth);
}

void UFO::spinIngot() {
    // TODO: log
    fprintf(stderr, "Spin\n");
    E -= SPIN_COST;
    swap(ingots.front().height, ingots.front().depth);
}

bool UFO::calculateIngotPosition(Ingot *i, double *slots, std::vector<COMMAND> *commands) const {
    slots[0] = i->height;
    slots[1] = i->width;
    slots[2] = i->depth;

    // indexes of the largest and the smallest sides of the UFO's ingot port
    // 0 stands for height, 1 stands for width
    int minSideIdx, maxSideIdx;
    // values of these sides
    double minSide, maxSide;
    if (H < W) {
        minSideIdx = 0;
        minSide = H;
        maxSideIdx = 1;
        maxSide = W;
    } else if (H > W) {
        minSideIdx = 1;
        minSide = W;
        maxSideIdx = 0;
        maxSide = H;
    } else {
        minSideIdx = 0;
        minSide = H;
        maxSideIdx = 1;
        maxSide = W;
    }

    if (slots[minSideIdx] > minSide) {
        if (slots[2] <= minSide) {
            swap(slots[minSideIdx], slots[2]);
            commands->push_back(minSideIdx == 0 ? SPIN : TURN);
        } else if (slots[maxSideIdx] <= minSide) {
            commands->push_back(ROTATE);
            swap(slots[minSideIdx], slots[maxSideIdx]);
        }
        else {
            return false;
        }
    }

    if (slots[maxSideIdx] > maxSide) {
        if (slots[2] <= maxSide) {
            swap(slots[maxSideIdx], slots[2]);
            commands->push_back(maxSideIdx == 0 ? SPIN : TURN);
        } else {
            return false;
        }
    }
    return true;
}

bool UFO::isIngotValid(Ingot *i) {
    bool success; // is ingot valid
    double *slots = new double[3];  // h, w, d of the ingot
    std::vector<COMMAND> commands;  // commands register

    success = calculateIngotPosition(i, &slots[0], &commands);
    if (!success) {
        dropIngot();
        return false;
    }

    while (!commands.empty()) {
        switch (*commands.begin()) {
            case TURN:
                turnIngot();
                break;
            case SPIN:
                spinIngot();
                break;
            case ROTATE:
                rotateIngot();
                break;
        }
        commands.erase(commands.begin());
    }
    return true;
}

double UFO::calculateEnergyCosts(Ingot *i) {
    return -(i->getWeight()*(F_C*(F_T0-F_TM)-F_L));
}

double UFO::calculateDepth(Ingot *i, double energyLimit) {
    double h = i->height/100;
    double w = i->width/100;
    double density = i->density;

    double d = -(100*energyLimit)/((h*w*density)*(F_C*(F_T0-F_TM)-F_L));
    if (d > i->depth)
        d = i->depth;
    return d;
}


void UFO::cutIngot(double newDepth) {
    Ingot *i = &ingots.front();
    E -= 5;
    ingots.emplace(ingots.begin()+1, Ingot(i->height, i->width, i->depth-newDepth, i->density));
    i->depth = newDepth;

    fprintf(stderr, "Ingot cut to %.2f cm\n", i->depth);
}


void UFO::dropIngot() {
    E -= DROP_COST;
    fprintf(stderr, "Ingot dropped\n");
    // TODO: delete it somehow
}


void UFO::acceptIngot() {
    Ingot *i = &ingots.front();
    E -= calculateEnergyCosts(i);
    E -= 2;
    E += F_EFFICIENCY*(F_L*i->getWeight()+(F_C*i->getWeight()*(F_TM-F_TR)));
    ingots.pop_front();

    fprintf(stderr, "Ingot accepted. Energy left: %.0f\n", E);
}


void UFO::flyAway() {
    fprintf(stderr, "yankee go home\n");
}

