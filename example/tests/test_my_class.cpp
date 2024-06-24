#include <gtest/gtest.h>

#include "my_class.h"

// Test case for basic allocation
TEST(AllocatorTest, BasicAllocation) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr = allocator.alloc(100);
    ASSERT_NE(ptr, nullptr);
}

// Test case for allocation beyond the limit
TEST(AllocatorTest, AllocationBeyondLimit) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr = allocator.alloc(101);
    ASSERT_EQ(ptr, nullptr);
}

// Test case for multiple small allocations
TEST(AllocatorTest, MultipleSmallAllocations) {
    Allocator allocator;
    allocator.makeAllocator(100);

    for (int i = 0; i < 10; ++i) {
        char* ptr = allocator.alloc(10);
        ASSERT_NE(ptr, nullptr);
    }
}

// Test case for allocation after reset
TEST(AllocatorTest, AllocationAfterReset) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr1 = allocator.alloc(50);
    ASSERT_NE(ptr1, nullptr);

    allocator.reset();

    char* ptr2 = allocator.alloc(100);
    ASSERT_NE(ptr2, nullptr);
}

// Test case for reset functionality
TEST(AllocatorTest, ResetFunctionality) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr1 = allocator.alloc(60);
    ASSERT_NE(ptr1, nullptr);

    allocator.reset();

    char* ptr2 = allocator.alloc(60);
    ASSERT_NE(ptr2, nullptr);
}

// Test case for repeated allocations
TEST(AllocatorTest, RepeatedAllocations) {
    Allocator allocator;
    allocator.makeAllocator(100);

    for (int i = 0; i < 10; ++i) {
        allocator.reset();
        char* ptr = allocator.alloc(100);
        ASSERT_NE(ptr, nullptr);
    }
}

// Test case for allocator reuse
TEST(AllocatorTest, AllocatorReuse) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr1 = allocator.alloc(50);
    ASSERT_NE(ptr1, nullptr);

    allocator.makeAllocator(100);

    char* ptr2 = allocator.alloc(100);
    ASSERT_NE(ptr2, nullptr);
}

// Test case for null allocation
TEST(AllocatorTest, NullAllocation) {
    Allocator allocator;

    char* ptr = allocator.alloc(10);
    ASSERT_EQ(ptr, nullptr);
}

// Test case for edge case allocation
TEST(AllocatorTest, EdgeCaseAllocation) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr = allocator.alloc(99);
    ASSERT_NE(ptr, nullptr);

    char* ptr2 = allocator.alloc(1);
    ASSERT_NE(ptr2, nullptr);

    char* ptr3 = allocator.alloc(1);
    ASSERT_EQ(ptr3, nullptr);
}

// Test case for minimum allocation
TEST(AllocatorTest, MinimumAllocation) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr = allocator.alloc(1);
    ASSERT_NE(ptr, nullptr);
}

// Test case for complete deallocation
TEST(AllocatorTest, CompleteDeallocation) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr1 = allocator.alloc(50);
    ASSERT_NE(ptr1, nullptr);

    allocator.reset();

    char* ptr2 = allocator.alloc(100);
    ASSERT_NE(ptr2, nullptr);

    allocator.reset();

    char* ptr3 = allocator.alloc(100);
    ASSERT_NE(ptr3, nullptr);
}

// Test case for mixed allocations
TEST(AllocatorTest, MixedAllocations) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr1 = allocator.alloc(10);
    ASSERT_NE(ptr1, nullptr);

    char* ptr2 = allocator.alloc(20);
    ASSERT_NE(ptr2, nullptr);

    char* ptr3 = allocator.alloc(30);
    ASSERT_NE(ptr3, nullptr);

    char* ptr4 = allocator.alloc(40);
    ASSERT_NE(ptr4, nullptr);
}

// Test case for oversized reset allocation
TEST(AllocatorTest, OversizedResetAllocation) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr1 = allocator.alloc(50);
    ASSERT_NE(ptr1, nullptr);

    allocator.reset();

    char* ptr2 = allocator.alloc(101);
    ASSERT_EQ(ptr2, nullptr);
}

// Test case for checking offset after allocation
TEST(AllocatorTest, OffsetAfterAllocation) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr1 = allocator.alloc(10);
    ASSERT_NE(ptr1, nullptr);

    char* ptr2 = allocator.alloc(10);
    ASSERT_EQ(ptr1 + 10, ptr2);
}

// Test case for consecutive allocations
TEST(AllocatorTest, ConsecutiveAllocations) {
    Allocator allocator;
    allocator.makeAllocator(100);

    char* ptr1 = allocator.alloc(20);
    ASSERT_NE(ptr1, nullptr);

    char* ptr2 = allocator.alloc(20);
    ASSERT_NE(ptr2, nullptr);

    char* ptr3 = allocator.alloc(60);
    ASSERT_NE(ptr3, nullptr);

    char* ptr4 = allocator.alloc(1);
    ASSERT_EQ(ptr4, nullptr);
}
