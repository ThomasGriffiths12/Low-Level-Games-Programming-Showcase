#include "Heap.h"

#define MEMSYSTEM_SIGNATURE 0xDEADC0DE
#define MEMSYSTEM_ENDMARKER 0xDEADBEEF

int Heap::nextAllocNum = 1;

struct AllocHeader
{
	int iSignature;
	int iAllocNum;
	Heap* pHeap;
	int iSize;
	AllocHeader* pNext;
	AllocHeader* pPrev;
};

void Heap::Initialize()
{
	active = false;
	allocatedBytes = 0;
	bytesPeak = 0;
	instances = 0;
	headAlloc = NULL;
}
//Heap::Heap(const char * name)
//{
//	strcpy_s(heapName, NAMELENGTH, name);
//}

const char * Heap::GetName() const
{
	return heapName;
}

void * Heap::Allocate(size_t bytes)
{
	size_t nRequestedBytes = bytes + sizeof(AllocHeader) + sizeof(int);
	char * pMem = (char *)malloc(nRequestedBytes);
	AllocHeader * pHeader = (AllocHeader *)pMem;
	pHeader->iSignature = MEMSYSTEM_SIGNATURE;
	pHeader->pHeap = this;
	pHeader->iSize = bytes;
	pHeader->pNext = headAlloc;
	pHeader->pPrev = NULL;
	pHeader->iAllocNum = nextAllocNum++;

	if (headAlloc != NULL)
	{
		headAlloc->pPrev = pHeader;
	}
	headAlloc = pHeader;

	if (this != NULL)
	{
		this->AddAllocation(bytes);
	}
	if (allocatedBytes > bytesPeak)
	{
		bytesPeak = allocatedBytes;
	}
	instances++;

	void * pStartMemBlock = pMem + sizeof(AllocHeader);
	int * pEndMarker = (int*)((char*)pStartMemBlock + bytes);
	*pEndMarker = MEMSYSTEM_ENDMARKER;
	return pStartMemBlock;

}

void Heap::Deallocate(void * pMem)
{
	AllocHeader * pHeader = (AllocHeader *)((char *)pMem - sizeof(AllocHeader));
	assert(pHeader->iSignature == MEMSYSTEM_SIGNATURE);
	int * pEndMarker = (int*)((char*)pMem + pHeader->iSize);
	assert(*pEndMarker == MEMSYSTEM_ENDMARKER);
	pHeader->pHeap->Deallocate(pHeader);
}

void Heap::Deallocate(AllocHeader * pHeader)
{
	if (pHeader->pPrev == NULL)
	{
		assert(pHeader == headAlloc);
		headAlloc = pHeader->pNext;
	}
	else
	{
		pHeader->pPrev->pNext = pHeader->pNext;
	}

	if (pHeader->pNext != NULL)
	{
		pHeader->pNext->pPrev = pHeader->pPrev;
	}

	if (pHeader != NULL)
	{
		if (pHeader->pHeap != NULL)
		{
			pHeader->pHeap->RemoveAllocation(pHeader->iSize);
		}
	}
	instances--;
	free(pHeader);
}

void Heap::PrintInfo(int indentLevel) const
{
	for (int i = 0; i < indentLevel; ++i)
	{
		printf("  ");
	}
	size_t totalBytes = 0;
	size_t totalPeakBytes = 0;
	int totalInstances = 0;

	totalBytes += allocatedBytes;
	totalPeakBytes += bytesPeak;
	totalInstances += instances;


	int spacing = 20 - indentLevel * 2;
	printf("%-*s %6d %6d %5d  %6d %6d %5d\n", spacing, heapName, allocatedBytes, bytesPeak, instances, totalBytes, totalPeakBytes, totalInstances);

}
void Heap::Activate(const char * name)
{
	assert(name != NULL);
	assert(strlen(name) < NAMELENGTH);
	strcpy_s(heapName, name);
	allocatedBytes = 0;
	bytesPeak = 0;
	instances = 0;
	active = true;
}

void Heap::Deactivate()
{
	strcpy_s(heapName, "");
	allocatedBytes = 0;
	bytesPeak = 0;
	instances = 0;
	active = false;
}

int Heap::GetMemoryBookmark()
{
	return nextAllocNum;
}

int Heap::ReportMemoryLeaks(int bookmark1, int bookmark2)
{
	int leaks = 0;
	AllocHeader * pHeader = headAlloc;
	while (pHeader != NULL)
	{
		if (pHeader->iAllocNum >= bookmark1 && pHeader->iAllocNum < bookmark2)
		{
			printf("Leak in %s. Size: %d, address: 0x%0Xd\n", heapName, pHeader->iSize, (char *)pHeader + sizeof(AllocHeader));
			leaks++;
		}
		pHeader = pHeader->pNext;
	}
	return leaks;
}

void Heap::SetName(const char * name)
{
	strcpy_s(heapName, sizeof(heapName), name);
}

void Heap::SetAllocation(size_t size)
{
	allocatedBytes = size;
}

void Heap::AddAllocation(size_t size)
{
	allocatedBytes += size;
}

void Heap::RemoveAllocation(size_t size)
{
	allocatedBytes -= size;
	
}
