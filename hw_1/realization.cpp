#include "interface.hpp"
// Имплементим методы класса Allocator
void Allocator::makeAllocator(size_t maxSize) {
  if (allocPtr != nullptr) delete[] allocPtr;
  allocPtr = new char[maxSize];
  this->allocPtr;
  offset = 0;
  memSize = maxSize;
}
char* Allocator::alloc(size_t size) {
  if (offset + size <= memSize) {
    int tempOffset = offset;
    offset += size;
    return allocPtr + tempOffset;
  } else {
    return nullptr;
  }
}
void Allocator::reset() { offset = 0; }

Allocator::~Allocator() { delete allocPtr; }
