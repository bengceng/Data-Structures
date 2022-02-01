// week4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
#if 1 // ADT ArrayList
    List mylist(3);
    printf("Printing empty list\n");
    mylist.Print();
    printf("Appending 10\n");
    mylist.Append(10);
    mylist.Print();
    printf("Appending 5\n");
    mylist.Append(5);
    mylist.Print();
    printf("Adding 7 @ position 1\n");
    mylist.Add(1,7);
    mylist.Print();
    printf("Adding 9 @ position 2\n");
    mylist.Add(2,9);
    mylist.Print();
    printf("Appending 10\n");
    mylist.Append(10);
    mylist.Print();
    printf("Appending 66\n");
    mylist.Append(66);
    mylist.Print();
    printf("Index of 10 is %d\n",mylist.IndexOf(10));
    printf("Last index of 10 is %d\n", mylist.LastIndexOf(10));
    printf("Value of index 4 is %d\n", mylist.Get(4));
    printf("Removing value @ index 3\n");
    mylist.Remove(3);
    mylist.Print();
    printf("Value of index 4 is %d\n", mylist.Get(4));
    printf("Setting the value @ index 2 --> 99\n");
    mylist.Set(2, 99);
    mylist.Print();
    printf("List contains 10: %d\n", mylist.Contains(10));
    printf("List contains 100: %d\n", mylist.Contains(100));
    printf("Number of element on the list is %d\n", mylist.Size());
    printf("List is empty: %d\n", mylist.IsEmpty());
    printf("Clearing the list\n");
    mylist.Clear();
    printf("List is empty: %d\n", mylist.IsEmpty());   

#endif

    printf("\n");
    system("pause");
    return 0;
}

