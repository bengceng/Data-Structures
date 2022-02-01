// week3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SortedLinkedList.h"
using namespace std;

void ContiguousAllocation() 
{
#if 0
    // One-Dimentional Array
#define ARRAY_SIZE 5

    char A[ARRAY_SIZE];
    int* B = new int[ARRAY_SIZE];
    double C[ARRAY_SIZE];

    printf("--------CHAR-------------\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("A[%d] = %p\n", i, &(A[i]));
    }

    printf("--------INT-------------\n");

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("B[%d] = %p\n", i, &(B[i]));
    }

    printf("--------DOUBLE-------------\n");

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("C[%d] = %p\n", i, &(C[i]));
    }

    cout << "-------------------------------" << endl;

#endif

#if 0
    // Two-Dimentional Arrays
#define ROWS 3
#define COLUMNS 4

    char D[ROWS][COLUMNS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int k = 0; k < COLUMNS; k++)
        {
            printf("D[%d][%d] = %p\n", i, k, &D[i][k]);
        }
        printf("\n");
    }
    printf("--------------------\n");
#endif

#if 0
    // Multi-Dimentional Arrays
#define D1 3
#define D2 4
#define D3 5

    char D[D1][D2][D3];

    for (int i = 0; i < D1; i++)
    {
        for (int k = 0; k < D2; k++)
        {
            for (int j = 0; j < D3; j++)
            {
                printf("D[%d][%d][%d] = %p\n", i, k, j, &D[i][k][j]);
            }
            printf("................\n");
        }
        printf("****************\n");
    }
    printf("==================\n");
#endif

#if 0
    // Unordered variables in a struct
    struct ST1 {
        int a;
        char b;
        float c;
        char d;
    };

    ST1 st1;
    
    printf("\n=====UNORDERED STRUCT========\n");
    printf("Size of st1.a: %d\tAddress:%p\n", sizeof(st1.a), &(st1.a));
    printf("Size of st1.b: %d\tAddress:%p\n", sizeof(st1.b), &(st1.b));
    printf("Size of st1.c: %d\tAddress:%p\n", sizeof(st1.c), &(st1.c));
    printf("Size of st1.d: %d\tAddress:%p\n", sizeof(st1.d), &(st1.d));
    printf("--------------------\n");
    printf("Size of st1: %d\n", sizeof(st1));    

    printf("\n=====UNORDERED ARRAY OF STRUCT========\n");
    ST1 sta[5];
    for (int i = 0; i < 5; i++) {
        printf("Address of sta[%d]: %p\n", i, &(sta[i]));
    }
#endif

#if 1
    // Ordered variables in a struct
    struct ST2 {
        int a;
        float c;
        char b;        
        char d;
    };

    ST2 st2;

    printf("\n========ORDERED STRUCT========\n");
    printf("Size of st2.a: %d\tAddress:%p\n", sizeof(st2.a),&(st2.a));
    printf("Size of st2.c: %d\tAddress:%p\n", sizeof(st2.c), &(st2.c));
    printf("Size of st2.b: %d\tAddress:%p\n", sizeof(st2.b), &(st2.b));    
    printf("Size of st2.d: %d\tAddress:%p\n", sizeof(st2.d), &(st2.d));
    printf("--------------------\n");
    printf("Size of st2: %d\n", sizeof(st2));

    printf("\n=====ORDERED ARRAY OF STRUCT========\n");
    ST2 stb[5];
    for (int i = 0; i < 5; i++) {
        printf("Address of stb[%d]: %p\n", i, &(stb[i]));
    }
#endif
}

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

#if 1
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
