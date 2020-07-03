#pragma once
// Minimalistic example code to use as reference for the Project!
#include <iostream>

template <class X>
class Allocator {
public:
	Allocator(int s = 0);
	X* allocate();

private:
	X* memBlock;
	X* minFree; // we find the first free space using a pointer to store the first free address in the block.
	size_t capacity;
	size_t freeSize;
	size_t allocatedSize;
	int noOfBlocks;
	int freeBlocks;
	void* operator new (size_t);
	void* operator new[](size_t);
	void operator delete(void*);
	void operator delete[](void*);
	
};

template <class X>
Allocator<X>::Allocator(int s) : memBlock(nullptr), minFree(nullptr)
{
	capacity = s;
	freeSize = s;
	allocatedSize = 0;
	noOfBlocks = 0;
	freeBlocks = 0;
	memBlock = (X*)operator new[](s/sizeof(X));
	minFree = memBlock;
}

template <class X>
void* Allocator<X>::operator new(size_t size)
{
	printf("Allocated using overloaded operator new");
	void* ptr = malloc(size);
	if (!ptr) throw std::bad_alloc;
	return ptr;
}

template <class X>
void* Allocator<X>::operator new[](size_t s)
{
	printf("Allocated using overloaded operator new");
	void* ptr = malloc(s);
	return ptr;
}

template <class X>
void Allocator<X>::operator delete(void* ptr)
{
	if (ptr)
	{
		free(ptr);
	}
}

template <class X>
void Allocator<X>::operator delete[](void * ptr)
{
	for (--i, i >= 0; --i)
	{ 
		ptr[i].~ptr();
	}
}

template <class X>
X* Allocator<X>::allocate()
{
	X* ptr = minFree;
	minFree++;
	return ptr;
}
