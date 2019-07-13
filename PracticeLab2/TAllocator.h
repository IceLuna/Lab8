#pragma once
#include <cstdlib>
class TAllocator
{
private:
	size_t Size, Count;
	size_t FreeCount;

	char* UsedBlocks;
	void** FreeBlocks;

public:
	TAllocator(size_t NewSize, size_t NewCount);
	virtual ~TAllocator();

	void* Allocate();
	void Deallocate(void* Pointer);

	bool HasFreeBlocks() const;

};

