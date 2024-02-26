#include <iostream>
#include <gtest/gtest.h>

#include "allocator.h"

TEST(EntryDataTest1, SubTest1) {
	Allocator obj1;
	obj1.makeAllocator(10);
	char* plc1 = obj1.alloc(3);
	*plc1 = 'h';
	*(plc1 + 1) = 's';
	*(plc1 + 2) = 'e';
	
	ASSERT_TRUE(*(plc1 + 1) == 's');
	ASSERT_FALSE(*(plc1 + 2) == 's');
	ASSERT_TRUE(*plc1 == 'h');
};

TEST(EntryDataTest1, SubTest2) {
	Allocator obj1;
	obj1.makeAllocator(10);
	char* error_test_var = obj1.alloc(11);

	ASSERT_TRUE(NULL == error_test_var);
};

TEST(EntryDataTest1, SubTest3) {
	Allocator obj1;
	obj1.makeAllocator(1000);
	char* ukz1 = obj1.alloc(2);
	char* ukz2 = obj1.alloc(3);

	*ukz1 = 's';
	*(ukz1 + 1) = 's';
	*ukz2 = 'f';
	*(ukz2 + 1) = 'f';

	ASSERT_TRUE(*(ukz1 + 1) == 's');
	ASSERT_TRUE(*ukz2 == 'f');
	ASSERT_TRUE(*(ukz1 + 2) == 'f');
};

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
