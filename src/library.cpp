#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "include/library.h"
#include "include/logger.h"
#include "utils.h"

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


void UFO::putIngot(Ingot ingot) {
    // TODO: log
    fprintf(stderr, "Got new ingot: %s\n", ingot.to_string().c_str());
    ingots.emplace_back(ingot);
    if (isIngotValid()) {
        Ingot *i = &this->ingots.front();
        if (E-calculateEnergyCosts() > _EF)
            acceptIngot(); // TODO: move accept/drop to the 'put' method
        else {
//            TODO: E-_EF-2-5
//            while() {
//
//            }
        }
    } else {
        dropIngot();
    }

}

void UFO::rotateIngot() {
    // TODO: log
    fprintf(stderr, "Rotate\n");
    E -= 10;
    swap(ingots.front().width, ingots.front().height);
}

void UFO::turnIngot() {
    // TODO: log
    fprintf(stderr, "Turn\n");
    E -= 10;
    swap(ingots.front().width, ingots.front().depth);
}

void UFO::spinIngot() {
    // TODO: log
    fprintf(stderr, "Spin\n");
    E -= 10;
    swap(ingots.front().height, ingots.front().depth);
}

bool UFO::calculateIngotPosition(double *slots, std::vector<char> *commands) {
    Ingot &i = ingots.front();
    slots[0] = i.height;
    slots[1] = i.width;
    slots[2] = i.depth;

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
            commands->push_back(minSideIdx == 0 ? 'S' : 'T');
        } else if (slots[maxSideIdx] <= minSide) {
            commands->push_back('R');
            swap(slots[minSideIdx], slots[maxSideIdx]);
        }
        else {
            return false;
        }
    }

    if (slots[maxSideIdx] > maxSide) {
        if (slots[2] <= maxSide) {
            swap(slots[maxSideIdx], slots[2]);
            commands->push_back(maxSideIdx == 0 ? 'S' : 'T');
        } else {
            return false;
        }
    }
    return true;
}

bool UFO::isIngotValid() {
    bool success; // is ingot valid
    double *slots = new double[3];  // h, w, d of the ingot
    std::vector<char> commands;  // commands register

    success = calculateIngotPosition(&slots[0], &commands);
    if (!success) {
        dropIngot();
        return false;
    }

    while (!commands.empty()) {
        switch (*commands.begin()) {
            case 'T':
                turnIngot();
                break;
            case 'S':
                spinIngot();
                break;
            case 'R':
                rotateIngot();
                break;
        }
        commands.erase(commands.begin());
    }
    return true;
}

double UFO::calculateEnergyCosts() {
    // t0 - initial temperature of golden ingot
    // tm - heating temperature
    // tr - cooling by recuperator temperature
    // c  - specific heat of gold
    // l  - specific heat of fusion of gold
    // m  - weight of the ingot
    // efficiency - efficiency of the recuperator
    // total - calculation result
    Ingot *i = &ingots.front();

    double t0, tm, tr, c, l, m, efficiency, total;
    t0 = 300;
    tm = 1337.58;
    tr = 4;
    c = 0.129;
    l = 67;
    m = i->height/100 * i->width/100 * i->depth/100 * i->density;
    efficiency = 0.7;

    total = -m*(l-(efficiency-1)+c*(t0+tr*efficiency-tm*(efficiency+1)));
    total += 2;  // accept cost
    return total;
}

double UFO::calculateDepth(double energyCost) {
    Ingot *i = &ingots.front();

    double t0, tm, tr, c, l, h, w, d, density, efficiency;
    t0 = 300;
    tm = 1337.58;
    tr = 4;
    c = 0.129;
    l = 67;
    efficiency = 0.7;
    h = i->height/100;
    w = i->width/100;
    density = i->density;

    d = -(100*energyCost)/((h*w*density)*(l-(efficiency-1)+c*(t0+tr*efficiency-tm*(efficiency+1))));
    if (d > i->depth)
        d = i->depth;
    return d;
}


void UFO::cutIngot() {
    E -= 5;
    fprintf(stderr, "Ingot cut\n");

}


void UFO::dropIngot() {
    E -= 2;
    fprintf(stderr, "Ingot dropped\n");
    // TODO: delete it somehow
}


void UFO::acceptIngot() {
    E -= calculateEnergyCosts();
    fprintf(stderr, "Ingot accepted. Energy left: %.0f\n", E);
}


void UFO::flyAway() {
    fprintf(stderr, "yankee go home\n");
}

