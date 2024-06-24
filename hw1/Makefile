CC=g++
STANDARD=-std=c++20 -g
TEST_PARAMS=-lgtest -lgmock -pthread

build:
	$(CC) $(STANDARD) allocator.cpp main.cpp -o main.out
run:
	./main.out

test:
	$(CC) $(STANDARD) allocator.cpp test.cpp -o test.out $(TEST_PARAMS)

memory:
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main.out
