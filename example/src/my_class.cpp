#include "my_class.h"

void Allocator::makeAllocator(size_t maxSize) {
    // Smart pointer to avoid possible memory leaks
    ptr = std::make_unique<char[]>(maxSize);
    this->maxSize = maxSize;
    offset = 0;
}

char* Allocator::alloc(size_t size) {
    if (!ptr || size + offset > maxSize) {
        return nullptr;
    } else {
        // Here, we only set pointers to some value. We do not need
        // to free the memory, since we haven't allocated new memory
        char* newPtr = ptr.get() + offset;
        offset += size;
        return newPtr;
    }
}

void Allocator::reset() {
    offset = 0;
}
