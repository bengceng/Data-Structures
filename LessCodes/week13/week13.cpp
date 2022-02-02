// week13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "hashset.h"

using namespace std;

int main()
{
    hashSet HSet;

    cout << "Adding 1" << endl; HSet.add(1);
    cout << "Adding 2" << endl; HSet.add(2);
    cout << "HSet contains 1: " << HSet.contains(1) << endl;
    cout << "HSet contains 3: " << HSet.contains(3) << endl;
    cout << "Adding 2" << endl; HSet.add(2);
    cout << "HSet contains 2: " << HSet.contains(2) << endl;
    cout << "Removing 2" << endl; HSet.remove(2);
    cout << "HSet contains 2: " << HSet.contains(2) << endl;



    printf("\n");
    system("pause");
    return 0;
}


