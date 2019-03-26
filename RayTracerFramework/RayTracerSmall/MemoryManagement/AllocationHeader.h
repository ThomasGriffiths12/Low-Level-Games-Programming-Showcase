#pragma once
#include "HeapFactory.h"
#include "Heap.h"
#include <stdio.h>
#include <assert.h>


struct AllocHeader
{
	int iSignature;
	int iAllocNum;
	Heap* pHeap;
	int iSize;
	AllocHeader* pNext;
	AllocHeader* pPrev;
};



void * operator new(size_t size, Heap * pHeap)
{
	assert(pHeap != NULL);
	return pHeap->Allocate(size);
}

void * operator new (size_t size)
{
	Heap* heap = HeapFactory::GetDefaultHeap();
	return operator new (size, heap);
}

void operator delete(void * pMem)
{
	if (pMem != NULL)
		Heap::Deallocate(pMem);
}