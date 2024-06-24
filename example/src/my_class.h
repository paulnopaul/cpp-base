#pragma once

#include <memory>

class Allocator {
 private:
    std::unique_ptr<char[]> ptr;
    size_t offset = 0;
    size_t maxSize;

 public:
    void makeAllocator(size_t maxSize);

    char* alloc(size_t size);

    void reset();
};
