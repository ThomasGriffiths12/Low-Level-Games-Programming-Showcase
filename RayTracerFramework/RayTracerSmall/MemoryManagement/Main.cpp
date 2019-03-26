#include "GameObject.h"

int main()
{
	//HeapFactory::CreateHeap("default");
	Heap* h = HeapFactory::GetDefaultHeap();
	GameObject * testObject = new GameObject(16);
	GameObject * testObject2 = new GameObject(17);
	GameObject * testObject3 = new GameObject(18);
	Heap* h2 = HeapFactory::CreateHeap("SecondHeap");
	HeapFactory::PrintInfo();
	//delete testObject;
	return 0;
}