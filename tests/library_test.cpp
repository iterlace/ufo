#include <gtest/gtest.h>

// https://www.codeproject.com/Tips/5249547/How-to-Unit-Test-a-Private-Function-in-Cplusplus
#define private public
#include "../include/library.h"
#undef private

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


TEST(UfoTest, PutIngotTest) {
    Ingot ingot = Ingot();
    UFO ufo = UFO();
    ufo.putIngot(ingot);
    EXPECT_EQ(ufo.currentIngot.height, ingot.height);
    EXPECT_EQ(ufo.currentIngot.width, ingot.width);
    EXPECT_EQ(ufo.currentIngot.depth, ingot.depth);
    EXPECT_EQ(ufo.currentIngot.density, ingot.density);
}


TEST(UfoTest, RotateIngotTest) {
    UFO ufo = UFO();
    ufo.putIngot(Ingot(1, 2, 3, 0));
    ufo.rotateIngot();
    EXPECT_EQ(ufo.currentIngot.height, 2);
    EXPECT_EQ(ufo.currentIngot.width, 1);
}


TEST(UfoTest, TurnIngotTest) {
    UFO ufo = UFO();
    ufo.putIngot(Ingot(1, 2, 3, 0));
    ufo.turnIngot();
    EXPECT_EQ(ufo.currentIngot.width, 3);
    EXPECT_EQ(ufo.currentIngot.depth, 2);
}


TEST(UfoTest, SpinIngotTest) {
    UFO ufo = UFO();
    ufo.putIngot(Ingot(1, 2, 3, 0));
    ufo.spinIngot();
    EXPECT_EQ(ufo.currentIngot.height, 3);
    EXPECT_EQ(ufo.currentIngot.depth, 1);
}


TEST(UfoTest, CalculateIngotPositionTest) {
    UFO ufo = UFO();
    double *slots;
    double h, w, d;

    // CASE 1 - initially correct values (rectangular opening)
    ufo.H = 20;
    ufo.W = 50;
    ufo.putIngot(Ingot(20, 50, 40, 0));
    slots = ufo.calculateIngotPosition();
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_EQ(h, 20);
    EXPECT_EQ(w, 50);
    EXPECT_EQ(d, 40);

    // CASE 2 - rotation (rectangular opening)
    ufo.H = 50;
    ufo.W = 20;
    ufo.putIngot(Ingot(20, 50, 40, 0));
    slots = ufo.calculateIngotPosition();
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_EQ(h, 50);
    EXPECT_EQ(w, 20);
    EXPECT_EQ(d, 40);

    // CASE 3 - spin (rectangular opening)
    ufo.H = 20;
    ufo.W = 50;
    ufo.putIngot(Ingot(30, 50, 20, 0));
    slots = ufo.calculateIngotPosition();
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_EQ(h, 20);
    EXPECT_EQ(w, 50);
    EXPECT_EQ(d, 30);

    // CASE 4 - turn (rectangular opening)
    ufo.H = 20;
    ufo.W = 30;
    ufo.putIngot(Ingot(20, 50, 30, 0));
    slots = ufo.calculateIngotPosition();
    h = slots[0], w = slots[1], d = slots[2];
    EXPECT_EQ(h, 20);
    EXPECT_EQ(w, 30);
    EXPECT_EQ(d, 50);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
