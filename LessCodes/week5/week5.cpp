// week5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkList.h"
#include <list>

using namespace std;

void PrintList(list<int>& list) {
    printf("List = [");
    for (int x : list) {
        cout << x << ", ";
    }
    if (list.size() != 0) printf("\b\b");
    printf("]\n");
}

int main()
{
#if 1  // Integer Example
    List<int> mylist;
    printf("Printing empty list\n");
    mylist.Print();
    printf("Appending 10\n");
    mylist.Append(10);
    mylist.Print();
    printf("Appending 5\n");
    mylist.Append(5);
    mylist.Print();
    printf("Adding 7 @ position 1\n");
    mylist.Add(1, 7);
    mylist.Print();
    printf("Adding 9 @ position 2\n");
    mylist.Add(2, 9);
    mylist.Print();
    printf("Appending 10\n");
    mylist.Append(10);
    mylist.Print();
    printf("Appending 66\n");
    mylist.Append(66);
    mylist.Print();
    printf("Index of 10 is %d\n", mylist.IndexOf(10));
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

#if 0 // String Example
    List<string> mylist;
    printf("Printing empty list\n");
    mylist.Print();
    printf("Appending Omer\n");
    mylist.Append("Omer");
    mylist.Print();
    printf("Appending Ali\n");
    mylist.Append("Ali");
    mylist.Print();
    printf("Adding Hakan @ position 1\n");
    mylist.Add(1, "Hakan");
    mylist.Print();
    printf("Adding Fatma @ position 2\n");
    mylist.Add(2, "Fatma");
    mylist.Print();
    printf("Appending Ali\n");
    mylist.Append("Ali");
    mylist.Print();
    printf("Appending Ebru\n");
    mylist.Append("Ebru");
    mylist.Print();
    printf("Index of Ali is %d\n", mylist.IndexOf("Ali"));
    printf("Last index of Ali is %d\n", mylist.LastIndexOf("Ali"));
    cout << "Value of index 4 is "<< mylist.Get(4) << endl;
    printf("Removing value @ index 3\n");
    mylist.Remove(3);
    mylist.Print();
    cout << "Value of index 4 is " << mylist.Get(4)<< endl;
    printf("Setting the value @ index 2 --> Kemal\n");
    mylist.Set(2, "Kemal");
    mylist.Print();
    printf("List contains Ali: %d\n", mylist.Contains("Ali"));
    printf("List contains Elif: %d\n", mylist.Contains("Elif"));
    printf("Number of element on the list is %d\n", mylist.Size());
    printf("List is empty: %d\n", mylist.IsEmpty());
    printf("Clearing the list\n");
    mylist.Clear();
    printf("List is empty: %d\n", mylist.IsEmpty());
#endif 

#if 0 // C++ List class example
    std::list<int> mylist;
    printf("Printing empty list\n");
    PrintList(mylist);

    printf("Appending 10\n");
    mylist.push_back(10);
    PrintList(mylist);

    printf("Appending 5\n");
    mylist.push_back(5);
    PrintList(mylist);

    printf("Adding 7 @ position 1\n");
    auto iter = mylist.begin();
    iter++;
    mylist.insert(iter,7);
    PrintList(mylist);

    printf("Adding 9 @ position 2\n");
    iter = mylist.begin();
    iter++; iter++;
    mylist.insert(iter,9);
    PrintList(mylist);

    printf("Appending 10\n");
    mylist.push_back(10);
    PrintList(mylist);

    printf("Appending 66\n");
    mylist.push_back(66);
    PrintList(mylist);

    iter = mylist.begin();
    iter++; iter++; iter++; iter++;
    printf("Value of index 4 is %d\n", *iter);

    printf("Removing value @ index 3\n");
    iter = mylist.begin();
    iter++; iter++; iter++;
    mylist.erase(iter);
    PrintList(mylist);

    iter = mylist.begin();
    iter++; iter++; iter++; iter++;
    printf("Value of index 4 is %d\n", *iter);

    printf("Setting the value @ index 2 --> 99\n");
    iter = mylist.begin();
    iter++; iter++;
    *iter = 99;
    PrintList(mylist);

    printf("Number of element on the list is %d\n", mylist.size());

    printf("Clearing the list\n");
    mylist.clear();
    PrintList(mylist);

#endif


    printf("\n");
    system("pause");
    return 0;
}