// week12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "splay.h"
#include "tries.h"

using namespace std;

int main()
{
#if 1 // Splay Test
    BST bst;

    bst.add(15); cout << "Adding 15" << endl;
    bst.add(6); cout << "Adding 6" << endl;
    bst.add(18); cout << "Adding 18" << endl;
    bst.add(3); cout << "Adding 3" << endl;
    bst.add(12); cout << "Adding 12" << endl;
    bst.add(10); cout << "Adding 10" << endl;
    bst.add(14); cout << "Adding 14" << endl;

    bst.printLevelByLevel();
    bst.print();

    cout << "------------------------------\n";
    bst.find(12);
    cout << "Searching 12. (Zig Zag Splay)" << endl; // Zig Zag Splay
    bst.printLevelByLevel();
    bst.print();

    cout << "------------------------------\n";
    bst.find(3);
    cout << "Searching 3. (Zig Zig Splay)" << endl; // Zig Zig Splay
    bst.printLevelByLevel();
    bst.print();

    cout << "------------------------------\n";
    bst.find(6);
    cout << "Searching 6. (Zag Splay)" << endl; // Zag Splay
    bst.printLevelByLevel();
    bst.print();

    cout << "------------------------------\n";
    bst.find(14);
    cout << "Searching 14. (Zag Zig Splay & Then Zag)" << endl; // Zag Zig Splay & Then Zag
    bst.printLevelByLevel();
    bst.print();

    cout << "------------------------------\n";
    bst.find(18);
    cout << "Searching 18. (Zag Zag Splay )" << endl; // Zag Zag Splay 
    bst.printLevelByLevel();
    bst.print();

    cout << "------------------------------\n";
    bst.find(12);
    cout << "Searching 12. (Zig Zag Splay & Then Zig Zig Splay)" << endl; // Zig Zag Splay & Then Zig Zig Splay
    bst.printLevelByLevel();
    bst.print();
#elif 0 // Tries Test
    Trie trie;

    trie.insert("apple");
    cout << "Added 'apple' to the trie." << endl;

    bool ret = trie.search("apple");
    cout << "Searching apple: " << ret << endl;

    ret = trie.search("app");
    cout << "Searching app: " << ret << endl;

    ret = trie.startsWith("app");
    cout << "Searching words starts with app: " << ret << endl;

    trie.insert("app");
    cout << "Added 'app' to the trie." << endl;

    ret = trie.search("app");
    cout << "Searching app: " << ret << endl;

#endif

    printf("\n");
    system("pause");
    return 0;
}

