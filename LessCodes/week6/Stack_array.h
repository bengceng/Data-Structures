#pragma once

template <class T>
class Stack {
private:
	T *A;
	int capacity;
	int top;
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
	printf("USING ARRAY!!!\n");
	this->capacity = 10;
	this->A = new T[this->capacity];
	this->top = -1;
	this->NOElement = 0;
}

// Destructor
template <class T>
Stack<T>::~Stack() {
	delete[] this->A;
}

// Push on top of the stack
template <class T>
void Stack<T>::Push(T const &item) {
	if (this->top == this->capacity - 1) {
		this->capacity = this->capacity * 2;
		T *B = new T[this->capacity];
		for (int i = 0; i <= this->top; i++) B[i] = this->A[i];
		delete[] this->A;
		this->A = B;
	}

	this->top++;
	this->A[this->top] = item;
	this->NOElement++;
}

// Return the value on top of the stack
template <class T>
T Stack<T>::Top() {
	if (this->top < 0) throw std::exception("Stack<>::Top(): Empty stack");
	return this->A[this->top];
}

// Pop and return the value on top of the stack
template <class T>
T Stack<T>::Pop() {
	if (this->top < 0) throw std::exception("Stack<>::Top(): Empty stack");
	T item = this->A[this->top];
	this->top--;
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