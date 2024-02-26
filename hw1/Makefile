CC=g++
STANDARD=-std=c++20
TEST_PARAMS=-lgtest -lgmock -pthread

test:
	$(CC) $(STANDARD) allocator.cpp test.cpp -o test.out $(TEST_PARAMS)
