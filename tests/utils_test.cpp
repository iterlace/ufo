#include <gtest/gtest.h>

#include "../src/utils.h"


TEST(RandomNumberTest, EntireTest) {
    EXPECT_EQ(randomNumber(10, 10), 10);
    for (int i=0; i<10000; i++) {
        ASSERT_GE(randomNumber(10, 100), 10);
        ASSERT_LE(randomNumber(10, 100), 100);
    }
}
