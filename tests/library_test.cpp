#include <gtest/gtest.h>
#include <vector>
#include <stdio.h>
#include <iostream>

// https://www.codeproject.com/Tips/5249547/How-to-Unit-Test-a-Private-Function-in-Cplusplus
#define private public
#include "../include/library.h"
#undef private

using namespace std;

TEST(IngotTest, BasicConstructorTest) {
    Ingot ingot = Ingot(10, 20, 30, 19.3);
    EXPECT_EQ(ingot.height, 10);
    EXPECT_EQ(ingot.width, 20);
    EXPECT_EQ(ingot.depth, 30);
    EXPECT_EQ(ingot.density, 19.3);
}


TEST(IngotTest, AutoConstructorTest) {
    Ingot ingot = Ingot();
    EXPECT_TRUE(ingot.height >= 10 && ingot.height <= 100);
    EXPECT_TRUE(ingot.width >= 10 && ingot.width <= 100);
    EXPECT_TRUE(ingot.depth >= 10 && ingot.depth <= 500);
    EXPECT_TRUE(ingot.density >= 19.3 && ingot.density <= 19.32);
}


//TEST(UfoTest, PutIngotTest) {
//    Ingot ingot = Ingot(10, 10, 10, 19.32);
//    UFO ufo = UFO();
//    ufo.H = 10;
//    ufo.W = 10;
//    ufo.putIngot(ingot);
//    EXPECT_EQ(ufo.ingots.front().height, ingot.height);
//    EXPECT_EQ(ufo.ingots.front().width, ingot.width);
//    EXPECT_EQ(ufo.ingots.front().depth, ingot.depth);
//    EXPECT_EQ(ufo.ingots.front().density, ingot.density);
//}


TEST(UfoTest, RotateIngotTest) {
    UFO ufo = UFO();
    ufo.ingots.emplace_back(Ingot(1, 2, 3, 0));
    ufo.rotateIngot();
    EXPECT_EQ(ufo.ingots.front().height, 2);
    EXPECT_EQ(ufo.ingots.front().width, 1);
}


TEST(UfoTest, TurnIngotTest) {
    UFO ufo = UFO();
    ufo.ingots.emplace_back(Ingot(1, 2, 3, 0));
    ufo.turnIngot();
    EXPECT_EQ(ufo.ingots.front().width, 3);
    EXPECT_EQ(ufo.ingots.front().depth, 2);
}


TEST(UfoTest, SpinIngotTest) {
    UFO ufo = UFO();
    ufo.ingots.emplace_back(1, 2, 3, 0);
    ufo.spinIngot();
    EXPECT_EQ(ufo.ingots.front().height, 3);
    EXPECT_EQ(ufo.ingots.front().depth, 1);
}


TEST(UfoTest, CalculateIngotPositionTest) {
    UFO ufo = UFO();
    bool success;
    double *slots = new double[3];
    double h, w, d;
    std::vector<COMMAND> commands;


    // CASE 1 - initially correct values (rectangular opening)
    ufo.H = 20;
    ufo.W = 50;
    ufo.ingots.emplace_back(Ingot(20, 50, 40, 0));
    success = ufo.calculateIngotPosition(&ufo.ingots.front(), &slots[0], &commands);
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_TRUE(success);
    EXPECT_EQ(h, 20);
    EXPECT_EQ(w, 50);
    EXPECT_EQ(d, 40);
    EXPECT_EQ(commands, vector<COMMAND>({}));
    commands.clear();
    ufo.ingots.clear();

    // CASE 2 - rotation (rectangular opening)
    ufo.H = 50;
    ufo.W = 20;
    ufo.ingots.emplace_back(Ingot(20, 50, 40, 0));
    success = ufo.calculateIngotPosition(&ufo.ingots.front(), &slots[0], &commands);
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_TRUE(success);
    EXPECT_EQ(h, 50);
    EXPECT_EQ(w, 20);
    EXPECT_EQ(d, 40);
    EXPECT_EQ(commands, vector<COMMAND>({ROTATE}));
    commands.clear();
    ufo.ingots.clear();

    // CASE 3 - spin (rectangular opening)
    ufo.H = 20;
    ufo.W = 50;
    ufo.ingots.emplace_back(Ingot(30, 50, 20, 0));
    success = ufo.calculateIngotPosition(&ufo.ingots.front(), &slots[0], &commands);
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_TRUE(success);
    EXPECT_EQ(h, 20);
    EXPECT_EQ(w, 50);
    EXPECT_EQ(d, 30);
    EXPECT_EQ(commands, vector<COMMAND>({SPIN}));
    commands.clear();
    ufo.ingots.clear();

    // CASE 4 - turn (rectangular opening)
    ufo.H = 20;
    ufo.W = 30;
    ufo.ingots.emplace_back(Ingot(20, 50, 30, 0));
    success = ufo.calculateIngotPosition(&ufo.ingots.front(), &slots[0], &commands);
    ASSERT_TRUE(success);
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_EQ(h, 20);
    EXPECT_EQ(w, 30);
    EXPECT_EQ(d, 50);
    EXPECT_EQ(commands, vector<COMMAND>({TURN}));
    commands.clear();
    ufo.ingots.clear();

    // CASE 5 - rotation+spin (rectangular opening)
    ufo.H = 20;
    ufo.W = 30;
    ufo.ingots.emplace_back(Ingot(50, 20, 30, 0));
    success = ufo.calculateIngotPosition(&ufo.ingots.front(), &slots[0], &commands);
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_TRUE(success);
    EXPECT_EQ(h, 20);
    EXPECT_EQ(w, 30);
    EXPECT_EQ(d, 50);
    EXPECT_EQ(commands, vector<COMMAND>({ROTATE, TURN}));
    commands.clear();
    ufo.ingots.clear();

    // TODO: create more complex test cases

    // CASE 6 - spin (square opening)
    ufo.H = 20;
    ufo.W = 20;
    ufo.ingots.emplace_back(Ingot(30, 15, 20, 0));
    success = ufo.calculateIngotPosition(&ufo.ingots.front(), &slots[0], &commands);
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_TRUE(success);
    EXPECT_EQ(h, 20);
    EXPECT_EQ(w, 15);
    EXPECT_EQ(d, 30);
    EXPECT_EQ(commands, vector<COMMAND>({SPIN}));
    commands.clear();
    ufo.ingots.clear();

    // CASE 7 - turn (square opening)
    ufo.H = 20;
    ufo.W = 20;
    ufo.ingots.emplace_back(Ingot(15, 30, 20, 0));
    success = ufo.calculateIngotPosition(&ufo.ingots.front(), &slots[0], &commands);
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_TRUE(success);
    EXPECT_EQ(h, 15);
    EXPECT_EQ(w, 20);
    EXPECT_EQ(d, 30);
    EXPECT_EQ(commands, vector<COMMAND>({TURN}));
    commands.clear();
    ufo.ingots.clear();
}


TEST(UfoTest, IsIngotValidTest) {
    UFO ufo = UFO();
    ufo.H = 20;
    ufo.W = 30;
    ufo.ingots.emplace_back(Ingot(50, 20, 30, 19.32));

    bool valid = ufo.isIngotValid(&ufo.ingots.front());
    ASSERT_TRUE(valid);
    EXPECT_EQ(ufo.ingots.front().height, 20);
    EXPECT_EQ(ufo.ingots.front().width, 30);
    EXPECT_EQ(ufo.ingots.front().depth, 50);
}


TEST(UfoTest, CalculateEnergyCostTest) {
    UFO ufo = UFO();
    ufo.ingots.emplace_back(Ingot(20, 20, 1, 19.32));
    double costs = ufo.calculateEnergyCosts(&ufo.ingots.front());
    ASSERT_EQ(costs, 1.55215195296000008085002264124341309070587158203125);
}


TEST(UfoTest, CalculateDepthTest) {
    UFO ufo = UFO();
    ufo.ingots.emplace_back(Ingot(20, 20, 1, 19.32));
    double depth = ufo.calculateDepth(
        &ufo.ingots.front(),
        1.55215195296000008085002264124341309070587158203125
    );
    ASSERT_LE(depth, 1.00001);
    ASSERT_GE(depth, 0.99999);
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
