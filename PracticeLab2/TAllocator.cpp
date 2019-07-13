#include "pch.h"
#include "TAllocator.h"
#include <iostream>

TAllocator::TAllocator(size_t NewSize, size_t NewCount) : Size(NewSize), Count(NewCount)
{
	FreeCount = Count;
	UsedBlocks = (char*)malloc(Size * Count);
	FreeBlocks = (void**)malloc(sizeof(void*) * Count);
	
	for (size_t i = 0; i < Count; ++i)
	{
		FreeBlocks[i] = UsedBlocks + i * Size;
		//std::cout << "#" << i+1 << "/" << Count << " - " << FreeBlocks[i] << std::endl;
	}
	std::cout << "Memoty Init!\n";
}

TAllocator::~TAllocator()
{
	if (Count > FreeCount)
	{
		std::cout << "Memory Leak!\n";
	}
	std::cout << "Deleting Allocator!\n";
	//free(FreeBlocks);
	//free(UsedBlocks);
}

void * TAllocator::Allocate()
{
	void* ResultPtr = nullptr;

	if (!FreeCount)
	{
		std::cout << "Empty!\n";
		return nullptr;
		//TAllocator(Size, Count);
		std::cout << "Reallocated!\n";
	}

	ResultPtr = FreeBlocks[FreeCount - 1];
	--FreeCount;
	//std::cout << "Allocated!\n";

	return ResultPtr;
}

void TAllocator::Deallocate(void * Pointer)
{
	FreeBlocks[FreeCount] = Pointer;
	++FreeCount;
}

bool TAllocator::HasFreeBlocks() const
{
	return FreeCount;
}
