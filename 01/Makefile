# Name of the target executable
TARGET := test.out

# Source files
SOURCES := $(wildcard *.cpp)

# Object files
OBJECTS := $(SOURCES:.cpp=.o)

# Google Test directory
GTEST_DIR := /opt/homebrew/opt/googletest

# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -Wall -std=c++20 -g -I$(GTEST_DIR)/include

# Linker flags
LDFLAGS := -L$(GTEST_DIR)/lib -lgtest -lgtest_main

# Valgrind options
VALGRIND_OPTS := --leak-check=full --show-leak-kinds=all --track-origins=yes

# Default make target
all: build

# Build step
build: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

test: build
	./$(TARGET)

# Compile step for source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Memory check step
memory: build
	valgrind $(VALGRIND_OPTS) ./$(TARGET)

leaks: build
	leaks -atExit -- ./$(TARGET)

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET)
	rm *.o *.out

.PHONY: all build test memory clean
