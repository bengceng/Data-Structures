#pragma once

template <class T>
class Queue {
private:
	T *A;
	int capacity;
	int NOElement;
	int front, rear;
public:
	Queue();
	~Queue();
	void Enqueue(T const &item);
	T Front();
	T Dequeue();
	bool IsEmpty();
	int Size();
};

// Constructor
template <class T>
Queue<T>::Queue() {
	printf("ARRAY BASED QUEUE!!!\n");
	this->capacity = 10;
	this->A = new T[this->capacity];
	this->front = this->rear = 0;
	this->NOElement = 0;
}

// Destructor
template <class T>
Queue<T>::~Queue() {
	delete [] this->A;
}

// Add an item to the queue
template <class T>
void Queue<T>::Enqueue(T const &item) {
	// If the queue is full
	if(this->NOElement == this->capacity) {
		this->capacity *= 2;
		T *B = new T[this->capacity];

		int index = this->front;
		for (int i = 0; i < this->NOElement; i++) {
			B[i] = this->A[index];
			index = (index + 1) % this->NOElement;
		}

		delete [] this->A;
		this->A = B;

		this->front = 0;
		this->rear = this->NOElement;
	}

	this->A[this->rear] = item;
	this->rear = (this->rear + 1) % this->capacity;
	this->NOElement++;
}

// Return value of the first item
template <class T>
T Queue<T>::Front() {
	if (this->NOElement == 0) throw std::exception("Queue<T>::Front: Empty queue");
	return this->A[this->front];
}

// Remove & Return value of the first item
template <class T>
T Queue<T>::Dequeue() {
	if (this->NOElement == 0) throw std::exception("Queue<T>::Front: Empty queue");

	T item = this->A[this->front];
	this->front = (this->front + 1) % this->capacity;

	this->NOElement--;
	return item;
}

// Check if the queue is empty
template <class T>
bool Queue<T>::IsEmpty() {
	if (this->NOElement == 0) return true;
	else return false;
}

// Returns size of the queue
template <class T>
int Queue<T>::Size() {
	return this->NOElement;
}