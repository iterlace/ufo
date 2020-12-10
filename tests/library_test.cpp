#include <gtest/gtest.h>

TEST(SquareRootTest, PositiveNos) {
    EXPECT_EQ (18.0, (12+6,0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
