#pragma once
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

#define NAMELENGTH 20

struct AllocHeader;

class Heap
{
public:
	void Initialize();

	//Heap(const char * name);
	const char * GetName() const;
	void SetName(const char * name);

	void Activate(const char * name);
	void Deactivate();

	void * Allocate(size_t bytes);
	static void Deallocate(void * pMem);
	bool IsActive() const { return active; }

	void PrintInfo(int indentlevel = 0) const;

	void SetAllocation(size_t size);
	void AddAllocation(size_t size);
	void RemoveAllocation(size_t size);
	size_t TotalAllocation() { return allocatedBytes; }

	int ReportMemoryLeaks(int bookmark1, int bookmark2);
	static int GetMemoryBookmark();

private:
	void Deallocate(AllocHeader * pHeader);

	char heapName[NAMELENGTH];
	bool active;
	AllocHeader * headAlloc;
	static int nextAllocNum;
	size_t bytesPeak;
	size_t allocatedBytes;
	int instances;
};