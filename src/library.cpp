#include <iostream>
#include <algorithm>

#include "include/library.h"
#include "utils.h"
#include "logger.h"

using namespace std;


Ingot::Ingot() {
    this->width = randomNumber(10, 100);
    this->height = randomNumber(10, 100);
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
    this->currentIngot = ingot;
}

void UFO::rotateIngot() {
    // TODO: log
    swap(this->currentIngot.width, this->currentIngot.height);
}

void UFO::turnIngot() {
    // TODO: log
    swap(this->currentIngot.width, this->currentIngot.depth);
}

void UFO::spinIngot() {
    // TODO: log
    swap(this->currentIngot.height, this->currentIngot.depth);
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

    Ingot &i = this->currentIngot;

    if (H != W) {
        double slots[] = {i.height, i.width, i.depth};
        // indexes of the largest and the smallest sides of the UFO's ingot port
        // 0 stands for height, 1 stands for width
        int min_side_idx, max_side_idx;
        // values of these sides
        double min_side, max_side;
        if (H < M) {
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
                    this->dropIngot();
                    return;
                }
        }

        if (slots[max_side_idx] < max_side) {

        } else {
            if (slots[2] <= max_side) {
                swap(slots[max_side_idx], slots[2]);
            }
            else {
                this->dropIngot();
                return;
            }
        }
    }

}



