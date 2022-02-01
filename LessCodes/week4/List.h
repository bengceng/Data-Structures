#pragma once

class List
{
private:
	int *A;
	int capacity;
	int NOElement;

	// Initialize function
	void initialize(int initCapacity) {
		if (initCapacity <= 0) initCapacity = 5;
		this->capacity = initCapacity;
		this->A = new int[this->capacity];
		this->NOElement = 0;
	}

public:
	// Default constructor
	List() {
		initialize(5);
	}

	// Parametrized Constructor
	List(int initCapacity) {
		initialize(initCapacity);
	}

	// Destructor
	~List() {
		delete[] this->A;
	}

	int Get(int index) {
		if (index < 0 || index >= this->NOElement) throw std::exception("List::Get: Index out of range");
		return this->A[index];
	}

	void Set(int index, int item) {
		if (index < 0 || index >= this->NOElement) throw std::exception("List::Get: Index out of range");
		this->A[index] = item;
	}

	// Add a new item at a given index
	void Add(int index, int item) {
		// Verify validity of the index
		if (index < 0 || index > this->NOElement) throw std::exception("List::Add: Index out of range");

		// If the array is full, allocate a new array with double capacity
		if (this->NOElement == this->capacity) {
			this->capacity = this->capacity * 2;
			int *B = new int[this->capacity];
			for (int i = 0; i < this->NOElement; i++) B[i] = this->A[i];
			delete[] this->A;
			this->A = B;
		}

		// Shift all elements one cell to the right starting from the index
		for (int i = this->NOElement-1; i >= index; i--) {
			this->A[i + 1] = this->A[i];
		}

		this->A[index] = item;
		this->NOElement++;
	}

	// Add a new item at the end of the list
	void Append(int item) {
		Add(this->NOElement, item);
	}

	// Removes the item at the given index 
	void Remove(int index) {
		// Verify validity of the index
		if (index < 0 || index >= this->NOElement) throw std::exception("List::Add: Index out of range");
		for (int i = index; i < this->NOElement - 1; i++) this->A[i] = this->A[i + 1];
		this->NOElement--;
	}

	// Forward search and return index of given item 
	int IndexOf(int item) {
		for (int i = 0; i < this->NOElement; i++) {
			if (this->A[i] == item) return i;
		}
		return -1;
	}

	// Backward search and return index of given item 
	int LastIndexOf(int item) {
		for (int i = this->NOElement - 1; i >= 0; i--) {
			if (this->A[i] == item) return i;
		}
		return -1;
	}

	// Returns true if the list contains given element
	bool Contains(int item) {
		if (IndexOf(item) < 0) return false;
		else return true;
	}

	// Returns true if the list is empty
	bool IsEmpty() { return this->NOElement == 0; }

	// Returns the number of elements in the list
	int Size() { return this->NOElement; }

	// Clears up the list
	void Clear() { this->NOElement = 0; }

	// Prints elements of the list
	void Print() {
		printf("List = [");
		for (int i = 0; i < this->NOElement; i++) {
			printf("%d, ", this->A[i]);
		}
		if (this->NOElement != 0) printf("\b\b");
		printf("]\n");
	}
};