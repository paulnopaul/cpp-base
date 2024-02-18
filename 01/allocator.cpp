#include "allocator.h"

Allocator::Allocator() {
  memory = nullptr;
  offset = 0;
  size = 0;
}
Allocator::~Allocator() { delete[] memory; }

void Allocator::makeAllocator(size_t maxSize) {
  delete[] memory;
  memory = new char[maxSize];
  offset = 0;
  size = maxSize;
}

void Allocator::reset() { offset = 0; }

char* Allocator::alloc(size_t blockSize) {
  if (memory == nullptr || offset + blockSize > size) {
    return nullptr;
  }
  char* block = memory + offset;
  offset += blockSize;
  return block;
}
