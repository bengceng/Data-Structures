#pragma once
#include<stdlib.h>
#include<iostream>
#include<iomanip>

using namespace std;

struct LinkedListNode 
{
	int value;
	LinkedListNode *next;
};

class SortedLinkedList
{
private:

	LinkedListNode *head;

public:

	//Constructor
	SortedLinkedList() { head = NULL; } 

	//Returns true if the given element exist in the list
	bool find(int x)
	{
		LinkedListNode *p = head;//strcut'ýn adresini tutan p pointer ý.
		while (p != NULL)
		{
			if (p->value == x) return true;
			p = p->next;
		}
		return false;
	}

	//prints elements in the list
	void print()
	{
		cout << "Elements = [";
		LinkedListNode *p = head;
		while (p != NULL)
		{
			cout << " " <<p->value;
			p = p->next;
		}
		cout << "]\n";
	}

	//Adds given element to the sorted list
	void add(int x)
	{
		//Allocate new node
		LinkedListNode *node=new LinkedListNode();
		node->value = x;
		node->next = NULL;

		//Initialize pointers to traverse list
		LinkedListNode *q = NULL;
		LinkedListNode *p = head;

		while (p != NULL && x > p->value)
		{
			q = p;
			p = p->next;
		}

		//Condition: Insert beginning of the list
		if (q == NULL)
		{
			node->next = head;
			head = node;
		}
		else //Insert middle or end of the list
		{
			node->next = q->next;
			q->next = node;
		}
	}
};