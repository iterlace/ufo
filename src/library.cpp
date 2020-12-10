#include <iostream>
#include <algorithm>

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
    currentIngot = ingot;
}

void UFO::rotateIngot() {
    // TODO: log
    swap(currentIngot.width, currentIngot.height);
}

void UFO::turnIngot() {
    // TODO: log
    swap(currentIngot.width, currentIngot.depth);
}

void UFO::spinIngot() {
    // TODO: log
    swap(currentIngot.height, currentIngot.depth);
}

double *UFO::calculateIngotPosition() {
    Ingot &i = currentIngot;
    double *slots = new double[3];
    slots[0] = i.height;
    slots[1] = i.width;
    slots[2] = i.depth;

    if (H != W) {
        // indexes of the largest and the smallest sides of the UFO's ingot port
        // 0 stands for height, 1 stands for width
        int min_side_idx, max_side_idx;
        // values of these sides
        double min_side, max_side;
        if (H < W) {
            min_side_idx = 0;
            min_side = H;
            max_side_idx = 1;
            max_side = W;
        } else {
            min_side_idx = 1;
            min_side = W;
            max_side_idx = 0;
            max_side = H;
        }

        if (slots[min_side_idx] <= min_side) {

        } else {
            if (slots[2] <= min_side)
                swap(slots[min_side_idx], slots[2]);
            else
            if (slots[max_side_idx] <= min_side)
                swap(slots[min_side_idx], slots[max_side_idx]);
            else {
                dropIngot();
                // TODO: exception
                return nullptr;
            }
        }

        if (slots[max_side_idx] <= max_side) {

        } else {
            if (slots[2] <= max_side) {
                swap(slots[max_side_idx], slots[2]);
            }
            else {
                dropIngot();
                // TODO: exception
                return nullptr;
            }
        }
    }
    return slots;
}

void UFO::verifyIngot() {
//    double sortedIngotParams[] = {this->currentIngot.height, this->currentIngot.width, this->currentIngot.depth};
//    sort(sortedIngotParams, sortedIngotParams + sizeof(sortedIngotParams) / sizeof(sortedIngotParams[0]));
//
//    if (H == W) {
//        // TODO
//    } else {
//        Ingot &ingot = this->currentIngot;
//        double minSide = min({H, W});
//        double maxSide = max({H, W});
//        char minSideName = minSide == H ? 'h' : 'w';
//
//        if (minSide <=)
//
//    }


}


void UFO::cutIngot() {

}


void UFO::dropIngot() {

}


void UFO::acceptIngot() {

}


void UFO::flyAway() {

}

