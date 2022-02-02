// week14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;


void PrintSet(std::set<int>& myset) {
#if 1
    cout << "Set elements: ";
    for (auto iter : myset) {
        cout << iter << ", ";
    }
    cout << endl;
#elif 0
    // Forward walk using explicit iterators
    cout << "Set elements: ";
    for (auto iter = myset.begin(); iter != myset.end(); iter++) {
        cout << *iter << ", ";
    }
    cout << endl;
#elif 0
    // Backward walk using explicit forward iterators and -- operator
    cout << "Set elements in reverse order: ";
    for (auto iter = --myset.end(); iter != myset.end(); iter--) {
        cout << *iter << ", ";
    }
    cout << endl;
#else
    // Backward walk using explicit reverse iterators
    // Note: reverse iterators are NOT compatible with forward iterators!!
    cout << "Set elements in reverse order: ";
    for (auto iter = myset.rbegin(); iter != myset.rend(); iter++) {
        cout << *iter << ", ";
    }
    cout << endl;

#endif
}

void PrintMultiSet(std::multiset<int>& myset) {
    cout << "Set elements: ";
    for (auto iter : myset) {
        cout << iter << ", ";
    }
    cout << endl;
}

void PrintUOSet(unordered_set<int>& myset) {
    cout << "Set elements: ";
    for (auto iter : myset) {
        cout << iter << ", ";
    }
    cout << endl;
}

void PrintUOMultiSet(unordered_multiset<int>& myset) {
    cout << "Set elements: ";
    for (auto iter : myset) {
        cout << iter << ", ";
    }
    cout << endl;
}

//==========================================

void PrintMap(std::map<int, string>& mymap) {
    cout << "Map elements: ";
    for (auto iter : mymap) {
        cout << "[" << iter.first << ", "<< iter.second << "], ";
    }
    cout << endl;
}

void PrintMultiMap(std::multimap<int, string>& mymap) {
    cout << "Map elements: ";
    for (auto iter : mymap) {
        cout << "[" << iter.first << ", " << iter.second << "], ";
    }
    cout << endl;
}

void PrintUOMap(std::unordered_map<int, string>& mymap) {
    cout << "Map elements: ";
    for (auto iter : mymap) {
        cout << "[" << iter.first << ", " << iter.second << "], ";
    }
    cout << endl;
}

void PrintUOMiltiMap(std::unordered_multimap<int, string>& mymap) {
    cout << "Map elements: ";
    for (auto iter : mymap) {
        cout << "[" << iter.first << ", " << iter.second << "], ";
    }
    cout << endl;
}

//==========================================

void OrderedSetExample() {
    cout << "Ordered Set Example " << endl;

    set<int> myset;

    cout << "Insert(5)" << endl;
    myset.insert(5);

    cout << "Insert(7)" << endl;
    myset.insert(7);

    cout << "Insert(9)" << endl;
    myset.insert(9);

    cout << "Insert(1)" << endl;
    myset.insert(1);

    cout << "Insert(3)" << endl;
    myset.insert(3);

    cout << "Number of elements in the set: " << myset.size() << endl;
    PrintSet(myset);

    printf("Min key is: %d\n", *myset.begin());
    printf("Max key is: %d\n", *myset.rbegin());

    auto iter = myset.find(7);
    if (iter != myset.end()) {
        printf("Key is: %d\n", *iter);
        auto prev = iter;
        prev--;
        if (prev != myset.end()) printf("Previous key is: %d\n", *prev);

        auto next = iter;
        next++;
        if (next != myset.end()) printf("Next key is: %d\n", *next);
    }
    else printf("7 does not exist in the set\n");

    iter = myset.find(13);
    if (iter != myset.end()) printf("The key is: %d\n", *iter);
    else printf("13 does not exist in the set\n");

    PrintSet(myset);
    cout << "Erasing 7" << endl;
    myset.erase(7);
    PrintSet(myset);

    cout << "Erasing 3" << endl;
    iter = myset.find(3);
    myset.erase(iter);
    PrintSet(myset);

    cout << "Insert(11)" << endl;
    myset.insert(11);
    PrintSet(myset);

    cout << "Insert(11) again !!" << endl;
    myset.insert(11);
    PrintSet(myset);
}

void OrderedMultisetExample() {
    cout << "Ordered Multiset Example " << endl;

    multiset<int> myset;

    cout << "Insert(5)" << endl;
    myset.insert(5);

    cout << "Insert(7)" << endl;
    myset.insert(7);

    cout << "Insert(9)" << endl;
    myset.insert(9);

    cout << "Insert(1)" << endl;
    myset.insert(1);

    cout << "Insert(3)" << endl;
    myset.insert(3);

    cout << "Number of elements in the set: " << myset.size() << endl;
    PrintMultiSet(myset);

    printf("Min key is: %d\n", *myset.begin());
    printf("Max key is: %d\n", *myset.rbegin());

    auto iter = myset.find(7);
    if (iter != myset.end()) {
        printf("Key is: %d\n", *iter);
        auto prev = iter;
        prev--;
        if (prev != myset.end()) printf("Previous key is: %d\n", *prev);

        auto next = iter;
        next++;
        if (next != myset.end()) printf("Next key is: %d\n", *next);
    }
    else printf("7 does not exist in the set\n");

    iter = myset.find(13);
    if (iter != myset.end()) printf("The key is: %d\n", *iter);
    else printf("13 does not exist in the set\n");

    PrintMultiSet(myset);
    cout << "Erasing 7" << endl;
    myset.erase(7);
    PrintMultiSet(myset);

    cout << "Erasing 3" << endl;
    iter = myset.find(3);
    myset.erase(iter);
    PrintMultiSet(myset);

    cout << "Insert(11)" << endl;
    myset.insert(11);
    PrintMultiSet(myset);

    cout << "Insert(11) again !!" << endl;
    myset.insert(11);
    PrintMultiSet(myset);

    cout << "Insert(11) again !!" << endl;
    myset.insert(11);
    PrintMultiSet(myset);

    cout << "Insert(11) again !!" << endl;
    myset.insert(11);
    PrintMultiSet(myset);
}

void UnorderedSetExample() {
    cout << "Unordered Set Example " << endl;

    unordered_set<int> myset;

    cout << "Insert(5)" << endl;
    myset.insert(5);

    cout << "Insert(7)" << endl;
    myset.insert(7);

    cout << "Insert(9)" << endl;
    myset.insert(9);

    cout << "Insert(1)" << endl;
    myset.insert(1);

    cout << "Insert(3)" << endl;
    myset.insert(3);

    cout << "Number of elements in the set: " << myset.size() << endl;
    PrintUOSet(myset);

    cout << "Erasing 7" << endl;
    myset.erase(7);
    PrintUOSet(myset);

    cout << "Erasing 3" << endl;
    auto iter = myset.find(3);
    myset.erase(iter);
    PrintUOSet(myset);

    cout << "Insert(11)" << endl;
    myset.insert(11);
    PrintUOSet(myset);

    cout << "Insert(11) again !!" << endl;
    myset.insert(11);
    PrintUOSet(myset);
}

void UnorderedMultiSetExample() {
    cout << "Unordered Multiset Example " << endl;

    unordered_multiset<int> myset;

    cout << "Insert(5)" << endl;
    myset.insert(5);

    cout << "Insert(7)" << endl;
    myset.insert(7);

    cout << "Insert(9)" << endl;
    myset.insert(9);

    cout << "Insert(1)" << endl;
    myset.insert(1);

    cout << "Insert(3)" << endl;
    myset.insert(3);

    cout << "Number of elements in the set: " << myset.size() << endl;
    PrintUOMultiSet(myset);

    cout << "Erasing 7" << endl;
    myset.erase(7);
    PrintUOMultiSet(myset);

    cout << "Erasing 3" << endl;
    auto iter = myset.find(3);
    myset.erase(iter);
    PrintUOMultiSet(myset);

    cout << "Insert(11)" << endl;
    myset.insert(11);
    PrintUOMultiSet(myset);

    cout << "Insert(11) again !!" << endl;
    myset.insert(11);
    PrintUOMultiSet(myset);

    cout << "Insert(11) again !!" << endl;
    myset.insert(11);
    PrintUOMultiSet(myset);

    cout << "Insert(11) again !!" << endl;
    myset.insert(11);
    PrintUOMultiSet(myset);
}

//===========================================

void OrderedMapExample() {
    cout << "Ordered Map Example " << endl;

    map<int, string> mymap;

    cout << "Insert(5, Omer)" << endl;
    mymap.insert(make_pair(5, "Omer"));

    cout << "Insert(7, Ali)" << endl;
    mymap.insert(make_pair(7, "Ali"));

    cout << "Insert(9, Ayse)" << endl;
    mymap.insert(make_pair(9, "Ayse"));

    cout << "Insert(1, Fatma)" << endl;
    mymap.insert(make_pair(1, "Fatma"));

    cout << "Insert(3, Emine)" << endl;
    mymap.insert(make_pair(3, "Emine"));

    cout << "Number of elements in the set: " << mymap.size() << endl;
    PrintMap(mymap);

    printf("Min key/value is: <%d, %s>\n", mymap.begin()->first, mymap.begin()->second.c_str());
    printf("Max key/value is: <%d, %s>\n", mymap.rbegin()->first, mymap.rbegin()->second.c_str());

    auto iter = mymap.find(7);
    printf("Key/Value is: <%d, %s>\n", iter->first, iter->second.c_str());

    auto prev = iter; prev--;
    printf("Previous key is: <%d, %s>\n", prev->first, prev->second.c_str());

    auto next = iter; next++;
    printf("Next key is: <%d, %s>\n", next->first, next->second.c_str());


    PrintMap(mymap);
    cout << "Erasing 7" << endl;
    mymap.erase(7);
    PrintMap(mymap);

    cout << "Erasing 3" << endl;
    iter = mymap.find(3);
    mymap.erase(iter);
    PrintMap(mymap);

    cout << "Insert(11, Mustafa)" << endl;
    mymap.insert(make_pair(11, "Mustafa"));
    PrintMap(mymap);

    cout << "Insert(11, Hasan) again !!" << endl;
    mymap.insert(make_pair(11, "Mustafa"));
    PrintMap(mymap);

    cout << "Does the map contain 1?";
    auto it = mymap.find(1);
    if (it == mymap.end()) cout << "No" << endl;
    else cout << "Yes [1, " << it->second << "]" << endl;
}

void OrderedMultiMapExample() {
    cout << "Ordered Multimap Example " << endl;

    multimap<int, string> mymap;

    cout << "Insert(5, Omer)" << endl;
    mymap.insert(make_pair(5, "Omer"));

    cout << "Insert(7, Ali)" << endl;
    mymap.insert(make_pair(7, "Ali"));

    cout << "Insert(9, Ayse)" << endl;
    mymap.insert(make_pair(9, "Ayse"));

    cout << "Insert(1, Fatma)" << endl;
    mymap.insert(make_pair(1, "Fatma"));

    cout << "Insert(3, Emine)" << endl;
    mymap.insert(make_pair(3, "Emine"));

    cout << "Number of elements in the set: " << mymap.size() << endl;
    PrintMultiMap(mymap);

    printf("Min key/value is: <%d, %s>\n", mymap.begin()->first, mymap.begin()->second.c_str());
    printf("Max key/value is: <%d, %s>\n", mymap.rbegin()->first, mymap.rbegin()->second.c_str());

    auto iter = mymap.find(7);
    printf("Key/Value is: <%d, %s>\n", iter->first, iter->second.c_str());

    auto prev = iter; prev--;
    printf("Previous key is: <%d, %s>\n", prev->first, prev->second.c_str());

    auto next = iter; next++;
    printf("Next key is: <%d, %s>\n", next->first, next->second.c_str());


    PrintMultiMap(mymap);
    cout << "Erasing 7" << endl;
    mymap.erase(7);
    PrintMultiMap(mymap);

    cout << "Erasing 3" << endl;
    iter = mymap.find(3);
    mymap.erase(iter);
    PrintMultiMap(mymap);

    cout << "Insert(11, Mustafa)" << endl;
    mymap.insert(make_pair(11, "Mustafa"));
    PrintMultiMap(mymap);

    cout << "Insert(11, Hasan) again !!" << endl;
    mymap.insert(make_pair(11, "Hasan"));
    PrintMultiMap(mymap);

    cout << "Insert(11, Huseyin) again !!" << endl;
    mymap.insert(make_pair(11, "Huseyin"));
    PrintMultiMap(mymap);

    cout << "Insert(11, Murat) again !!" << endl;
    mymap.insert(make_pair(11, "Murat"));
    PrintMultiMap(mymap);

    cout << "Does the map contain 1?";
    auto it = mymap.find(1);
    if (it == mymap.end()) cout << "No" << endl;
    else cout << "Yes [1, " << it->second << "]" << endl;
}

void UnorderedMapExample() {
    cout << "Unordered Map Example " << endl;

    unordered_map<int, string> mymap;
    
    cout << "Insert(5, Omer)" << endl;
    mymap.insert(make_pair(5, "Omer"));

    cout << "Insert(7, Ali)" << endl;
    mymap.insert(make_pair(7, "Ali"));

    cout << "Insert(9, Ayse)" << endl;
    mymap.insert(make_pair(9, "Ayse"));

    cout << "Insert(1, Fatma)" << endl;
    mymap.insert(make_pair(1, "Fatma"));

    cout << "Insert(3, Emine)" << endl;
    mymap.insert(make_pair(3, "Emine"));

    cout << "Number of elements in the set: " << mymap.size() << endl;
    PrintUOMap(mymap);

    cout << "Erasing 7" << endl;
    mymap.erase(7);
    PrintUOMap(mymap);

    cout << "Erasing 3" << endl;
    auto iter = mymap.find(3);
    mymap.erase(iter);
    PrintUOMap(mymap);

    cout << "Insert(11, Mustafa)" << endl;
    mymap.insert(make_pair(11, "Mustafa"));
    PrintUOMap(mymap);

    cout << "Insert(11, Hasan) again !!" << endl;
    mymap.insert(make_pair(11, "Mustafa"));
    PrintUOMap(mymap);

    cout << "Does the map contain 1?";
    auto it = mymap.find(1);
    if (it == mymap.end()) cout << "No" << endl;
    else cout << "Yes [1, " << it->second << "]" << endl;
}

void UnorderedMultiMapExample() {
    cout << "Unordered Multimap Example " << endl;

    unordered_multimap<int, string> mymap;

    cout << "Insert(5, Omer)" << endl;
    mymap.insert(make_pair(5, "Omer"));

    cout << "Insert(7, Ali)" << endl;
    mymap.insert(make_pair(7, "Ali"));

    cout << "Insert(9, Ayse)" << endl;
    mymap.insert(make_pair(9, "Ayse"));

    cout << "Insert(1, Fatma)" << endl;
    mymap.insert(make_pair(1, "Fatma"));

    cout << "Insert(3, Emine)" << endl;
    mymap.insert(make_pair(3, "Emine"));

    cout << "Number of elements in the set: " << mymap.size() << endl;
    PrintUOMiltiMap(mymap);

    cout << "Erasing 7" << endl;
    mymap.erase(7);
    PrintUOMiltiMap(mymap);

    cout << "Erasing 3" << endl;
    auto iter = mymap.find(3);
    mymap.erase(iter);
    PrintUOMiltiMap(mymap);

    cout << "Insert(11, Mustafa)" << endl;
    mymap.insert(make_pair(11, "Mustafa"));
    PrintUOMiltiMap(mymap);

    cout << "Insert(11, Hasan) again !!" << endl;
    mymap.insert(make_pair(11, "Hasan"));
    PrintUOMiltiMap(mymap);

    cout << "Insert(11, Huseyin) again !!" << endl;
    mymap.insert(make_pair(11, "Huseyin"));
    PrintUOMiltiMap(mymap);

    cout << "Insert(11, Murat) again !!" << endl;
    mymap.insert(make_pair(11, "Murat"));
    PrintUOMiltiMap(mymap);

    cout << "Does the map contain 1?";
    auto it = mymap.find(1);
    if (it == mymap.end()) cout << "No" << endl;
    else cout << "Yes [1, " << it->second << "]" << endl;

    cout << "Listing pairs for key = 11: ";
    for (auto it = mymap.find(11); it != mymap.end(); it++) {
        if (it->first != 11) break;
        cout << "[11, " << it->second << "], ";
    }
    cout << endl;
}

int main()
{
    //OrderedSetExample();
    //OrderedMultisetExample();
    //UnorderedSetExample();
    //UnorderedMultiSetExample();
    // ============================
    //OrderedMapExample();
    //OrderedMultiMapExample();
    //UnorderedMapExample();
    UnorderedMultiMapExample();

    printf("\n");
    system("pause");
    return 0;
}

