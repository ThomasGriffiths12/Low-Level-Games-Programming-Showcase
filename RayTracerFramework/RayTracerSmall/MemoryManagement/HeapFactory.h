#pragma once
#include "Heap.h"
#include <vector>


class HeapFactory
{

public:
	static Heap* CreateHeap(const char* szName);
	static Heap* GetDefaultHeap();
	static void PrintInfo();

private:

	static void Initialize();
	enum { MAXHEAPS = 512};
	static Heap heaps[MAXHEAPS];
	static Heap * defaultHeap;

};

