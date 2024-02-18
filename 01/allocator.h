#ifndef HSE_CPP_SPRING_2024_ALLOCATOR_H
#define HSE_CPP_SPRING_2024_ALLOCATOR_H
#include <iostream>

class Allocator {
 private:
  char* memory;
  size_t offset;
  size_t size;

 public:
  Allocator();
  void makeAllocator(size_t maxSize);
  char* alloc(size_t size);
  void reset();
  // Это деструктор!
  ~Allocator();
};

#endif  // HSE_CPP_SPRING_2024_ALLOCATOR_H
