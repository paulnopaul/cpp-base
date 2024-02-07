#include <gtest/gtest.h>
#include <iostream>
#include "./module.h"

TEST(ModuleTest, Simple) {
    ASSERT_EQ(add(1, 2), 3);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
