#include "HeapFactory.h"
#include <malloc.h>

Heap HeapFactory::heaps[];
Heap * HeapFactory::defaultHeap = NULL;

void HeapFactory::Initialize()
{
	for (int i = 0; i < MAXHEAPS; ++i)
	{
		heaps[i].Initialize();
	}
	defaultHeap = CreateHeap("Default");
}

void HeapFactory::PrintInfo()
{
	printf("MEMORY INFORMATION\n");
	printf("                            Local                 Total\n");
	printf("Name                  Memory  Peak  Inst   Memory  Peak  Inst\n");
	for (int i = 0; i < MAXHEAPS; ++i)
	{
		if (heaps[i].IsActive())
			heaps[i].PrintInfo();
	}
}

Heap* HeapFactory::CreateHeap(const char* szName)
{
	for (int i = 0; i < MAXHEAPS; i++)
	{
		Heap * pHeap = &heaps[i];
		if (!pHeap->IsActive())
		{
			pHeap->Activate(szName);
			return pHeap;
		}
	}

	return NULL;
}

Heap* HeapFactory::GetDefaultHeap()
{
	if (defaultHeap == NULL)
	{
		Initialize();
		//CreateDefaultHeap();
	}
	return defaultHeap;
}
