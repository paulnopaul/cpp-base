#include <iostream>
#include <gtest/gtest.h>
#include <sstream>
#include "realization.cpp"
TEST(TestAssig1, maxMemTest) {
    Allocator allocator;
    allocator.makeAllocator(10);
    int s = allocator.memSize;
    EXPECT_EQ (10,s);
}

TEST(TestAssig1, allocFitTest1) {
    Allocator allocator;
    allocator.makeAllocator(10);
    
    EXPECT_NE (allocator.alloc(10), nullptr);
}

TEST(TestAssig1, allocFitTest2) {
    Allocator allocator;
    allocator.makeAllocator(10);
    allocator.alloc(0);
    EXPECT_NE (allocator.alloc(10), nullptr);
}

TEST(TestAssig1, allocErrorTest1) {
    Allocator allocator;
    allocator.makeAllocator(10);
    allocator.alloc(1);
    EXPECT_EQ (allocator.alloc(10), nullptr);
}

TEST(TestAssig1, ResetTest1) {
    Allocator allocator;
    allocator.makeAllocator(10);
    allocator.alloc(10);
    allocator.reset();
    EXPECT_NE (allocator.alloc(10), nullptr);
}

int main(int argc,char **argv) {

    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}