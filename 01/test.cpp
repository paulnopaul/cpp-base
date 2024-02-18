#include <gtest/gtest.h>

#include "allocator.h"

TEST(AllocatorTest, MakeAllocator) {
  Allocator allocator;

  allocator.makeAllocator(100);
  EXPECT_NE(allocator.alloc(10), nullptr);

  allocator.makeAllocator(50);
  EXPECT_NE(allocator.alloc(5), nullptr);
}

TEST(AllocatorTest, Alloc) {
  Allocator allocator;
  allocator.makeAllocator(50);

  char* block1 = allocator.alloc(20);
  EXPECT_NE(block1, nullptr);

  char* block2 = allocator.alloc(40);
  EXPECT_EQ(block2, nullptr);  // Insufficient space

  allocator.makeAllocator(100);
  char* block3 = allocator.alloc(30);
  EXPECT_NE(block3, nullptr);  // Should allocate in the new memory

  char* block4 = allocator.alloc(80);
  EXPECT_EQ(block4, nullptr);  // Insufficient space in the new memory
}

TEST(AllocatorTest, Reset) {
  Allocator allocator;
  allocator.makeAllocator(50);

  char* block1 = allocator.alloc(20);
  EXPECT_NE(block1, nullptr);

  allocator.reset();

  char* block2 = allocator.alloc(30);
  EXPECT_NE(block2, nullptr);  // Should allocate after reset

  EXPECT_EQ(block1, block2);  // Allocated memory should be reused after reset
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
