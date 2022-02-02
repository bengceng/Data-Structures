#pragma once
#include <vector>
#include <list>

using namespace std;

#define TABLE_SIZE 1013 // Random prime number

class hashSet {	
	vector<list<int>> T;

public:
	hashSet() { T.resize(TABLE_SIZE); }
	void add(int key);
	void remove(int key);
	bool contains(int key);
};

void hashSet::add(int key) {
	int index = key % TABLE_SIZE;
	for (auto no: T[index]) {
		if (no == key) return; // No duplicates
	}
	T[index].push_back(key);
}

void hashSet::remove(int key) {
	int index = key % TABLE_SIZE;
	for (auto iter = T[index].begin(); iter != T[index].end(); iter++) {
		if (*iter == key) {
			T[index].erase(iter);
			return;
		}
	}
}

bool hashSet::contains(int key) {
	int index = key % TABLE_SIZE;
	for (auto no : T[index]) {
		if (no == key) return true; // Key exists
	}
	return false; // Key does not exist
}