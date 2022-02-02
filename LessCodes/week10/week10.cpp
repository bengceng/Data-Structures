// week10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    BST bst; 

    bst.add(75); cout << "Adding 75" << endl;
    bst.add(14); cout << "Adding 14" << endl;
    bst.add(10); cout << "Adding 10" << endl;
    bst.add(108); cout << "Adding 108" << endl;
    bst.add(77); cout << "Adding 77" << endl;
    bst.add(76); cout << "Adding 76" << endl;
    bst.add(97); cout << "Adding 97" << endl;
    bst.add(280); cout << "Adding 280" << endl;
    bst.add(100); cout << "Adding 100" << endl;
    bst.print();

    cout << "------------------------------------\n";
    cout << "min key: " << bst.min() << endl;
    cout << "max key :" << bst.max() << endl;
    cout << "Does 75 exist? " << (bst.find(75) ? "YES" : "NO") << endl;
    cout << "Does 15 exist? " << (bst.find(15) ? "YES" : "NO") << endl;

    cout << "------------------------------------\n";
    cout << "Deleting 108" << endl;
    bst.remove(108);
    bst.print();

    cout << "------------------------------------\n";
    cout << "Deleting 14" << endl;
    bst.remove(14);
    bst.print();

    cout << "------------------------------------\n";
    cout << "Deleting 10" << endl;
    bst.remove(10);
    bst.print();

    cout << "------------------------------------\n";
    cout << "Deleting 75" << endl;
    bst.remove(75);
    bst.print();

    cout << "------------------------------------\n";
    cout << "Deleting 33" << endl;
    bst.remove(33);
    bst.print();

    cout << "------------------------------------\n";
    cout << "Deleting 97" << endl;
    bst.remove(97);
    bst.print();

    cout << "------------------------------------\n";
    cout << "Deleting 100" << endl;
    bst.remove(100);
    bst.print();

    cout << "------------------------------------\n";
    cout << "Deleting 77" << endl;
    bst.remove(77);
    bst.print();

    cout << "------------------------------------\n";
    cout << "Deleting 76" << endl;
    bst.remove(76);
    bst.print();

    cout << "------------------------------------\n";
    cout << "Deleting 280" << endl;
    bst.remove(280);
    bst.print();

    printf("\n");
    system("pause");
    return 0;
}

