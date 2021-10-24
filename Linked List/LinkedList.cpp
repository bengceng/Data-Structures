#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include "LinkedList.h"

using namespace std;
void NonContiguousAllocation()
{
	SortedLinkedList myList;

	printf("Printing empty list\n");
	myList.print();
#if 1   // Add element
	printf("Adding 3\n ");
	myList.add(3);
	myList.print();

	printf("Adding 12\n ");
	myList.add(12);
	myList.print();

	printf("Adding 2\n ");
	myList.add(2);
	myList.print();

	printf("Adding 8\n ");
	myList.add(8);
	myList.print();
#endif

#if 1  // Find element
	printf(myList.find(12) ? "true" : "false");  // TRUE CASE 
	printf("\n");
	printf(myList.find(99) ? "true" : "false");  // FALSE CASE 
	printf("\n");
#endif

#if 0
	printf("Deleting 2\n ");
	myList.remove(2);
	myList.print();

	printf("Deleting 8\n ");
	myList.remove(8);
	myList.print();

	printf("Deleting 12\n ");
	myList.remove(12);
	myList.print();

	printf("Deleting 99\n ");
	myList.remove(99);
	myList.print();

	printf("Deleting 3\n ");
	myList.remove(3);
	myList.print();
#endif


}


int main()
{
#if 0 // Contiguous Allocation Memory Locations
	ContiguousAllocation();
#endif

#if 1 // Non-Contiguous Allocation 
	NonContiguousAllocation();
#endif

	printf("\n");
	system("pause");
	return 0;
}
