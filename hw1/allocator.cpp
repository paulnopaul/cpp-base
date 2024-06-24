#include "allocator.h"

void Allocator::makeAllocator(size_t size) {
	if (this->total_memory != nullptr) {
		delete[] this->total_memory;		
	}

	this->size_of_allocator = size;
	this->total_memory = new int8_t[size];
}

char* Allocator::alloc(size_t size) {
	if (size > this->size_of_allocator - offset) {
		return nullptr;
	}

	int8_t* place = (this->total_memory + offset);
	this->offset += size;

	return (char*)place;
}

void Allocator::reset() {
	this->offset == 0;
}

Allocator::~Allocator() {
	delete[] this->total_memory;
}
