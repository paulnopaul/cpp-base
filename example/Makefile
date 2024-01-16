# Name of the target executable
TARGET := myapp.out

# Source files
SOURCES := $(wildcard *.cpp)

# Object files
OBJECTS := $(SOURCES:.cpp=.o)

# Input file
INPUT := input.txt

# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -Wall -g

# Linker flags
LDFLAGS :=

# Valgrind options
VALGRIND_OPTS := --leak-check=full --show-leak-kinds=all --track-origins=yes

# Default make target
all: build

# Build step
build: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compile step for source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run step
run: build
	./$(TARGET)

# Memory check step
memory: build
	valgrind $(VALGRIND_OPTS) ./$(TARGET) < $(INPUT)

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all build run memory clean
