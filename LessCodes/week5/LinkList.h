#pragma once
#include <string>

template <class T>
struct ListNode {
	T item;
	ListNode* prev;
	ListNode* next;

	ListNode(T const& item) {
		this->item = item;
		this->next = this->prev = NULL;
	}
};


template <class T>
class List {
private:
	ListNode<T> *head;
	ListNode<T> *tail;
	int NOElement;	// Number of element on the list

	void AddNode(ListNode<T>* prev, T const& item);

public:
	List();
	~List();
	T Get(int index);
	void Set(int index, T const &item);
	void Append(T const &item);
	void Add(int index, T const &item);
	void Remove(int index);
	int IndexOf(T const &item);
	int LastIndexOf(T const& item);
	bool Contains(T const& item);
	bool IsEmpty();
	int Size();
	void Clear();
	void Print();
};

// Constructor
template <class T>
List<T>::List() {
	this->head = this->tail = NULL;
	this->NOElement = 0;
}

// Destructor
template <class T>
List<T>::~List() {
	Clear();
}

// Add Node auxilary function
template <class T>
void List<T>::AddNode(ListNode<T> *curr, T const &item) {
	ListNode<T> *node = new ListNode<T>(item);

	if (this->head == NULL) {
		// First node
		this->head = this->tail = node;

	}
	else if (curr == this->head) {
		// Insert @ the beginning of the list (Non empty list)
		node->next = this->head;
		this->head->prev = node;
		this->head = node;

	}
	else if (curr == NULL) {
		// Append @ the end of the list (Non empty list)
		node->prev = this->tail;
		this->tail->next = node;
		this->tail = node;

	}
	else {
		// Add in-between nodes
		node->next = curr;
		node->prev = curr->prev;
		curr->prev->next = node;
		curr->prev = node;

	}

	this->NOElement++;
}

// Add new node to given index
template <class T>
void List<T>::Add(int index, T const &item) {
	// Check index
	if (index < 0 || index > this->NOElement) throw std::exception("List<T>::Add: Index out of range");

	ListNode<T> *curr = this->head;
	while (index > 0) {
		curr = curr->next;
		index--;
	}

	AddNode(curr, item);
}

// Add new node at the end of the list
template <class T>
void List<T>::Append(T const &item) {
	AddNode(NULL, item);
}

// Remove a node from the given index
template <class T>
void List<T>::Remove(int index) {
	// Check index
	if (index < 0 || index > this->NOElement) throw std::exception("List<T>::Add: Index out of range");

	// Find requested node
	ListNode<T> *curr = this->head;
	while (index > 0) {
		curr = curr->next;
		index--;
	}

	if (curr == this->head) {
		// Remove the first node
		this->head = this->head->next;
		if (this->head == NULL) this->tail = NULL;
		else this->head->prev = NULL;
	}

	else if (curr == this->tail) {
		// Remove the last node
		this->tail = this->tail->prev;
		this->tail->next = NULL;
	}

	else {
		// Remove node in-between nodes
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
	}

	delete curr;
	this->NOElement--;
}

// Returns the value of given index
template <class T>
T List<T>::Get(int index) {
	// Check index
	if (index < 0 || index >= this->NOElement) throw std::exception("List<T>::Add: Index out of range");

	ListNode<T> *node = this->head;
	while (index > 0) {
		node = node->next;
		index--;
	}
	return node->item;
}

// Set the value of given index with given item
template <class T>
void List<T>::Set(int index, T const &item) {
	// Check index
	if (index < 0 || index >= this->NOElement) throw std::exception("List<T>::Add: Index out of range");

	ListNode<T>* node = this->head;
	while (index > 0) {
		node = node->next;
		index--;
	}
	node->item = item;
}

// Return the first index of given item (if exists)
template <class T>
int List<T>::IndexOf(T const &item) {
	ListNode<T> *curr = this->head;

	int index = 0;
	while (curr != NULL) {
		if (curr->item == item) return index;
		index++;
		curr = curr->next;
	}

	return -1;
}

// Return the last index of given item (if exists)
template <class T>
int List<T>::LastIndexOf(T const& item) {
	ListNode<T>* curr = this->tail;

	int index = this->NOElement-1;
	while (curr != NULL) {
		if (curr->item == item) return index;
		index--;
		curr = curr->prev;
	}

	return -1;
}

// Returns True if the given item exists on the list
template <class T>
bool List<T>::Contains(T const &item) {
	if (IndexOf(item) < 0) return false;
	else return true;
}

// Returns True if the list is empty
template <class T>
bool List<T>::IsEmpty() {return this->NOElement == 0;}

// Returns the number of element in the list
template <class T>
int List<T>::Size() { return this->NOElement; }

// Clears up the list
template <class T>
void List<T>::Clear() {
	while (this->head != NULL) {
		ListNode<T> *node = this->head;
		this->head = this->head->next;
		delete node;
	}

	this->NOElement = 0;
	this->tail = NULL;
}

// Prints elements of the list
template <class T>
void List<T>::Print() {
	int index = this->NOElement - 1;
	ListNode<T> *node = this->head;
	printf("List = [");
	while (index >= 0) {
		std::cout << node->item << ", ";
		node = node->next;
		index--;
	}
	if (this->NOElement != 0) printf("\b\b");
	printf("]\n");
}