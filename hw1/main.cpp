#include "allocator.h"

#include <iostream>

int main()
{
	Allocator obj1;
	obj1.makeAllocator(10);
	char* plc1 = obj1.alloc(3);
	plc1[0] = 'a';
	plc1[1] = 'b';
	plc1[2] = 'c';

	std::cout << *plc1 << std::endl;

	obj1.reset();
	obj1.makeAllocator(1000000000);
	if (NULL == obj1.alloc(1000000000000000)) {
		std::cout << "OK" << std::endl;
	}

	return 0;
}
