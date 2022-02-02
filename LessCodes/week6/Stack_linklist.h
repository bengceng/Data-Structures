#pragma once

template <class T>
struct StackNode {
	T item;
	StackNode *next;

	StackNode(T const &item) {
		this->item = item;
		this->next = NULL;
	}
};

template <class T>
class Stack {
private:
	StackNode<T> *head;
	int NOElement;
public:
	Stack();
	~Stack();
	void Push(T const &item);
	T Top();
	T Pop();
	bool IsEmpty();
	int Size();
};

// Constructor
template <class T>
Stack<T>::Stack() {
	printf("USING LINKLIST!!!\n");
	this->head = NULL;
	this->NOElement = 0;
}

// Destructor
template <class T>
Stack<T>::~Stack() {
	while (this->head) {
		StackNode<T> *node = this->head;
		this->head = this->head->next;
		delete node;
	}
}

// Push on top of the stack
template <class T>
void Stack<T>::Push(T const& item) {
	StackNode<T> *node = new StackNode<T>(item);

	node->next = this->head;
	this->head = node;
	this->NOElement++;
}

// Return the value on top of the stack
template <class T>
T Stack<T>::Top() {
	if (this->head == NULL) throw std::exception("Stack<>::Top(): Empty stack");
	return this->head->item;
}

// Pop and return the value on top of the stack
template <class T>
T Stack<T>::Pop() {
	if (this->head == NULL) throw std::exception("Stack<>::Top(): Empty stack");

	T item = this->head->item;
	StackNode<T> *node = this->head;
	this->head = this->head->next;
	delete node;
	this->NOElement--;
	return item;
}

// Check if the stack is empty
template <class T>
bool Stack<T>::IsEmpty() {
	if (this->NOElement == 0) return true;
	else return false;
}

// Returns the number of element in the stack
template <class T>
int Stack<T>::Size() {
	return this->NOElement;
}