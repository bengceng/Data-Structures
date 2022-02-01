#pragma once
#include <stdlib.h>

struct LinkedListNode {
	int value;
	LinkedListNode* next;
};

class SortedLinkedList {
private:
	LinkedListNode* head;
public:
// Constructor
	SortedLinkedList() { head = NULL; }	

// Returns true if given element exists in the list
	bool find(int x) {
		LinkedListNode* p = head;
		while (p != NULL) {
			if (p->value == x) return true;
			p = p->next;
		}
		return false;
	}

	// Prints elements of the list
	void print() {
		printf("Elements = [");

		LinkedListNode* p = head;
		while (p != NULL) {
			printf("%d, ", p->value);
			p = p->next;
		}

		printf("]\n");
	}

	// Adds given element to the sorted list
	void add(int X) {
		// Allocate new node
		LinkedListNode* node = new LinkedListNode();
		node->value = X;
		node->next = NULL;

		// Initialize pointers to traverse on the list
		LinkedListNode* q = NULL;  // q trails p
		LinkedListNode* p = head;

		while (p != NULL && X > p->value) {
			q = p;
			p = p->next;
		} // end-while

		// Condition: Insert beginning of the list
		if (q == NULL) {
			node->next = head;
			head = node;
		}
		else { // Condition: Insert middle or end of the list
			node->next = q->next;
			q->next = node;
		} // end-else
	} // end-add

	void remove(int x) {
		// Initialize pointers to traverse on the list
		LinkedListNode* q = NULL;  // q trails p
		LinkedListNode* p = head;

		while (p != NULL && p->value != x) {
			q = p;
			p = p->next;
		} // end-while

		if (p == NULL) return; // Given value does not exist

		// Remove p from the list
		if (q == NULL) head = p->next;
		else q->next = p->next;

		delete p; // Avoid memory leak

	}
};