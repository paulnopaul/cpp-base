#include <iostream>

#include "interface.hpp"

int main() {
  Allocator* allocator = new Allocator();
  int n;
  std::cin >> n;  // кол-во команд
  char* ptr;
  for (int i = 0; i < n; i++) {
    std::string cmd;
    std::cin >> cmd;
    if (cmd == "makeAllocator") {
      int size;
      std::cin >> size;
      allocator->makeAllocator(size);
    }
    if (cmd == "alloc") {
      int size;
      std::cin >> size;
      ptr = allocator->alloc(size);
      if (ptr == nullptr)
        std::cout << "nullptr\n";
      else
        std::cout << "true\n";
    }
    if (cmd == "reset") {
      allocator->reset();
    }
  }
  delete allocator;
  return 0;
}
