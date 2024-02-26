#include <stdint.h>
#include <cstddef>

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

class Allocator
{
	public:
		void makeAllocator(size_t maxSize);
		char *alloc(size_t size);
		void reset();

		~Allocator();
	
	private:
		int8_t* total_memory{nullptr};
		int8_t offset{0};
		int size_of_allocator{0};
};

#endif
