#include <iostream>

#include "./module.h"

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << add(a, b) << std::endl;
  return 0;
}
