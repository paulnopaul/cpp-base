#include <stdlib.h>

class Allocator {
 public:
  char* allocPtr = nullptr;
  int memSize;
  int offset;

 public:
  void makeAllocator(size_t maxSize);
  char* alloc(size_t size);
  void reset();
  ~Allocator();
};