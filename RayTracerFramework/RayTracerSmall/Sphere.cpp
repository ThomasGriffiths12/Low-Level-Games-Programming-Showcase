#include "Sphere.h"
#include "MemoryManagement/AllocationHeader.h"
Heap * Sphere::s_pHeap = NULL;

void * Sphere::operator new(size_t size)
{
	if (s_pHeap == NULL)
	{
		s_pHeap = HeapFactory::CreateHeap("Sphere");
	}
	return ::operator new(size, s_pHeap);
}

void Sphere::operator delete(void * p, size_t size)
{
	::operator delete(p);
}