#include <iostream>
#include <algorithm>
#include <vector>

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


void UFO::putIngot(Ingot ingot) {
    // TODO: log
    fprintf(stderr, "Got new ingot: H=%.02f, W=%.02f, D=%.02f\n", ingot.height, ingot.width, ingot.depth);
    currentIngot = ingot;
}

void UFO::rotateIngot() {
    // TODO: log
    fprintf(stderr, "Rotate\n");
    E -= 10;
    swap(currentIngot.width, currentIngot.height);
}

void UFO::turnIngot() {
    // TODO: log
    fprintf(stderr, "Turn\n");
    E -= 10;
    swap(currentIngot.width, currentIngot.depth);
}

void UFO::spinIngot() {
    // TODO: log
    fprintf(stderr, "Spin\n");
    E -= 10;
    swap(currentIngot.height, currentIngot.depth);
}

bool UFO::calculateIngotPosition(double *slots, std::vector<char> *commands) {
    Ingot &i = currentIngot;
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

bool UFO::verifyIngot() {
    bool success;
    double *slots = new double[3];
    std::vector<char> commands;

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
    acceptIngot();
    return true;
}


void UFO::cutIngot() {
    E -= 20;
    fprintf(stderr, "Ingot cut\n");

}


void UFO::dropIngot() {
    E -= 5;
    fprintf(stderr, "Ingot dropped\n");
    // TODO: delete it somehow
}


void UFO::acceptIngot() {
    E -= 5;
    fprintf(stderr, "Ingot accepted\n");
}


void UFO::flyAway() {
    fprintf(stderr, "yankee go home\n");
}

