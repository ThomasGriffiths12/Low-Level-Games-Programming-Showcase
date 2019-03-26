#include "GameObject.h"
#include "AllocationHeader.h"

Heap * GameObject::s_pHeap = NULL;

GameObject::GameObject(int id)
{
	m_id = id;
}

void * GameObject::operator new(size_t size)
{
	if (s_pHeap == NULL)
	{
		s_pHeap = HeapFactory::CreateHeap("Sphere");
	}
	return ::operator new(size, s_pHeap);
}

void GameObject::operator delete(void * p, size_t size)
{
	::operator delete(p);
}