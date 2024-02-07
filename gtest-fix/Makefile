TARGET := main.out
TESTS := test.out
CXX := g++
FLAGS := -std=c++20 -Wall -Wextra -Werror -g

all: build

module:
	$(CXX) $(FLAGS) -c module.cpp

build: module
	$(CXX) main.cpp $(FLAGS) -lpthread module.o -o $(TARGET)

build_test: module
	$(CXX) module_test.cpp $(FLAGS) -lgtest_main -lgtest -lpthread module.o -o $(TESTS)

clean:
	rm ./$(TESTS)

memory:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TESTS)

run:
	./$(TESTS)

test: build_test
	./$(TESTS)