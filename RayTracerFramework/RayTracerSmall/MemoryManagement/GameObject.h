#pragma once
#include "HeapFactory.h"
class GameObject
{
public:
	GameObject(int id);
	static void * operator new(size_t size);
	static void operator delete(void * p, size_t size);

private:

	static Heap* s_pHeap;
	int m_id;
};

