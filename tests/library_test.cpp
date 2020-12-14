#include <gtest/gtest.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

// https://www.codeproject.com/Tips/5249547/How-to-Unit-Test-a-Private-Function-in-Cplusplus
#define private public
#include "../include/library.h"
#undef private

using namespace std;


TEST(UfoTest, PutIngot2Test) {
    UFO ufo = UFO();

    srand(time(nullptr));
    ufo.putIngot(Ingot(0.32, 0.11, 1.13, 19314.29));
}

//TEST(IngotTest, BasicConstructorTest) {
//    Ingot ingot = Ingot(10, 20, 30, 19300);
//    EXPECT_EQ(ingot.height, 10);
//    EXPECT_EQ(ingot.width, 20);
//    EXPECT_EQ(ingot.depth, 30);
//    EXPECT_EQ(ingot.density, 19300);
//
//    Ingot *i = &ingot;
//    ASSERT_EQ((*i).height, i->height);
//}
//
//
//TEST(IngotTest, AutoConstructorTest) {
//    Ingot ingot = Ingot();
//    EXPECT_TRUE(ingot.height >= 0.1 && ingot.height <= 1);
//    EXPECT_TRUE(ingot.width >= 0.1 && ingot.width <= 1);
//    EXPECT_TRUE(ingot.depth >= 0.1 && ingot.depth <= 5);
//    EXPECT_TRUE(ingot.density >= 19300 && ingot.density <= 19320);
//}
//
//
//TEST(UfoTest, PutIngotTest) {
//    std::fprintf(stderr, "======\n");
//    Ingot ingot = Ingot(10, 10, 10000000, 19320);
//    UFO ufo = UFO();
//    ufo.H = 10;
//    ufo.W = 10;
//    // TODO: mock cutIngot to count iterations
//    ufo.putIngot(ingot);
//    std::fprintf(stderr, "=====\n");
//    EXPECT_GE(ufo.E, 100);
//}
//
//
//TEST(UfoTest, RotateIngotTest) {
//    UFO ufo = UFO();
//    ufo.ingots.emplace_back(Ingot(1, 2, 3, 0));
//    ufo.rotateIngot();
//    EXPECT_EQ(ufo.ingots.front().height, 2);
//    EXPECT_EQ(ufo.ingots.front().width, 1);
//}
//
//
//TEST(UfoTest, TurnIngotTest) {
//    UFO ufo = UFO();
//    ufo.ingots.emplace_back(Ingot(1, 2, 3, 0));
//    ufo.turnIngot();
//    EXPECT_EQ(ufo.ingots.front().width, 3);
//    EXPECT_EQ(ufo.ingots.front().depth, 2);
//}
//
//
//TEST(UfoTest, SpinIngotTest) {
//    UFO ufo = UFO();
//    ufo.ingots.emplace_back(1, 2, 3, 0);
//    ufo.spinIngot();
//    EXPECT_EQ(ufo.ingots.front().height, 3);
//    EXPECT_EQ(ufo.ingots.front().depth, 1);
//}
//
//
//TEST(UfoTest, CalculateIngotDimensionsTest) {
//    UFO ufo = UFO();
//    bool success;
//    double *slots = new double[3];
//    double h, w, d;
//    std::vector<COMMAND> commands;
//
//
//    // CASE 1 - initially correct values (rectangular opening)
//    ufo.H = 20;
//    ufo.W = 50;
//    ufo.ingots.emplace_back(Ingot(20, 50, 40, 0));
//    success = ufo.calculateIngotDimensions(&ufo.ingots.front(), &slots[0], &commands);
//    h = slots[0], w = slots[1], d = slots[2];
//    EXPECT_TRUE(success);
//    EXPECT_EQ(h, 20);
//    EXPECT_EQ(w, 50);
//    EXPECT_EQ(d, 40);
//    EXPECT_EQ(commands, vector<COMMAND>({}));
//    commands.clear();
//    ufo.ingots.clear();
//
//    // CASE 2 - rotation (rectangular opening)
//    ufo.H = 50;
//    ufo.W = 20;
//    ufo.ingots.emplace_back(Ingot(20, 50, 40, 0));
//    success = ufo.calculateIngotDimensions(&ufo.ingots.front(), &slots[0], &commands);
//    h = slots[0], w = slots[1], d = slots[2];
//    EXPECT_TRUE(success);
//    EXPECT_EQ(h, 50);
//    EXPECT_EQ(w, 20);
//    EXPECT_EQ(d, 40);
//    EXPECT_EQ(commands, vector<COMMAND>({ROTATE}));
//    commands.clear();
//    ufo.ingots.clear();
//
//    // CASE 3 - spin (rectangular opening)
//    ufo.H = 20;
//    ufo.W = 50;
//    ufo.ingots.emplace_back(Ingot(30, 50, 20, 0));
//    success = ufo.calculateIngotDimensions(&ufo.ingots.front(), &slots[0], &commands);
//    h = slots[0], w = slots[1], d = slots[2];
//    EXPECT_TRUE(success);
//    EXPECT_EQ(h, 20);
//    EXPECT_EQ(w, 50);
//    EXPECT_EQ(d, 30);
//    EXPECT_EQ(commands, vector<COMMAND>({SPIN}));
//    commands.clear();
//    ufo.ingots.clear();
//
//    // CASE 4 - turn (rectangular opening)
//    ufo.H = 20;
//    ufo.W = 30;
//    ufo.ingots.emplace_back(Ingot(20, 50, 30, 0));
//    success = ufo.calculateIngotDimensions(&ufo.ingots.front(), &slots[0], &commands);
//    ASSERT_TRUE(success);
//    h = slots[0], w = slots[1], d = slots[2];
//    EXPECT_EQ(h, 20);
//    EXPECT_EQ(w, 30);
//    EXPECT_EQ(d, 50);
//    EXPECT_EQ(commands, vector<COMMAND>({TURN}));
//    commands.clear();
//    ufo.ingots.clear();
//
//    // CASE 5 - rotation+spin (rectangular opening)
//    ufo.H = 20;
//    ufo.W = 30;
//    ufo.ingots.emplace_back(Ingot(50, 20, 30, 0));
//    success = ufo.calculateIngotDimensions(&ufo.ingots.front(), &slots[0], &commands);
//    h = slots[0], w = slots[1], d = slots[2];
//    EXPECT_TRUE(success);
//    EXPECT_EQ(h, 20);
//    EXPECT_EQ(w, 30);
//    EXPECT_EQ(d, 50);
//    EXPECT_EQ(commands, vector<COMMAND>({ROTATE, TURN}));
//    commands.clear();
//    ufo.ingots.clear();
//
//    // TODO: create more complex test cases
//
//    // CASE 6 - spin (square opening)
//    ufo.H = 20;
//    ufo.W = 20;
//    ufo.ingots.emplace_back(Ingot(30, 15, 20, 0));
//    success = ufo.calculateIngotDimensions(&ufo.ingots.front(), &slots[0], &commands);
//    h = slots[0], w = slots[1], d = slots[2];
//    EXPECT_TRUE(success);
//    EXPECT_EQ(h, 20);
//    EXPECT_EQ(w, 15);
//    EXPECT_EQ(d, 30);
//    EXPECT_EQ(commands, vector<COMMAND>({SPIN}));
//    commands.clear();
//    ufo.ingots.clear();
//
//    // CASE 7 - turn (square opening)
//    ufo.H = 20;
//    ufo.W = 20;
//    ufo.ingots.emplace_back(Ingot(15, 30, 20, 0));
//    success = ufo.calculateIngotDimensions(&ufo.ingots.front(), &slots[0], &commands);
//    h = slots[0], w = slots[1], d = slots[2];
//    EXPECT_TRUE(success);
//    EXPECT_EQ(h, 15);
//    EXPECT_EQ(w, 20);
//    EXPECT_EQ(d, 30);
//    EXPECT_EQ(commands, vector<COMMAND>({TURN}));
//    commands.clear();
//    ufo.ingots.clear();
//}
//
//
//TEST(UfoTest, PlaceIngotCorrectlyTest) {
//    UFO ufo = UFO();
//    ufo.H = 20;
//    ufo.W = 30;
//    ufo.ingots.emplace_back(Ingot(50, 20, 30, 19320));
//
//    bool valid = ufo.placeIngotCorrectly(&ufo.ingots.front());
//    ASSERT_TRUE(valid);
//    EXPECT_EQ(ufo.ingots.front().height, 20);
//    EXPECT_EQ(ufo.ingots.front().width, 30);
//    EXPECT_EQ(ufo.ingots.front().depth, 50);
//}
//
//
//TEST(UfoTest, CalculateEnergyCostTest) {
//    UFO ufo = UFO();
//    ufo.ingots.emplace_back(Ingot(0.2, 0.2, 0.01, 19320));
//    double costs = ufo.calculateEnergyCosts(&ufo.ingots.front());
//    ASSERT_EQ(costs, 1536.986371200000348835601471364498138427734375);
//}
//
//
//TEST(UfoTest, CalculateDepthTest) {
//    UFO ufo = UFO();
//    double depth;
//
//    // Calculate depth by energy limit  (values taken from CalculateEnergyCostTest)
//    ufo.ingots.emplace_back(Ingot(0.2, 0.2, 0.01, 19320));
//    depth = ufo.calculateDepth(
//            &ufo.ingots.front(),
//            1536.986371200000348835601471364498138427734375,
//            1000000
//    );
//    EXPECT_LE(depth, 0.0100001);
//    EXPECT_GE(depth, 0.0099999);
//    ufo.ingots.clear();
//
//    // Calculate depth by capacity
//    ufo.ingots.emplace_back(Ingot(10, 10,  10, 19320));
//    depth = ufo.calculateDepth(
//            &ufo.ingots.front(),
//            10000000000,
//            50
//    );
//    EXPECT_EQ(depth, 0.5);
//    ufo.ingots.clear();
//}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
