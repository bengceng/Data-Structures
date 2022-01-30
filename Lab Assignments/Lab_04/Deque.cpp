#include "Deque.h"
#include <iostream>
//BENGÝSU ÞAHÝN || HOMEWORK 4 ||152120191064
using namespace std;

///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	// Fill this in
	//cONSTRUCTOR
	this->head = this->tail = NULL;
	this->noOfItems = 0;

} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	// Fill this in

	//Tek tek node larýn üzerinde gezinerek silme iþlemi yapýlýr.
	
	while (this->head != NULL)
	{
		DequeNode *node = new DequeNode(0);
		node = this->head;
		this->head = this->head->next;
		this->head->next->prev;
		delete node;
	}
	//noOfItems reset edilir.
	this->noOfItems = 0;
	this->tail= this->head = NULL;

} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	// Fill this in

	DequeNode *p=new DequeNode(item); 
	
	if (this->IsEmpty() != true)
	{
		
		p->next = this->head;
		this->head->prev = p;
		this->head = p;
		
	}
	else
	{
		this->head = this->tail = p;
	}
	
	this->noOfItems++;

} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	// Fill this in

	DequeNode *p = new DequeNode(item);

	if (this->IsEmpty() != true)
	{
		p->prev = this->tail;
		this->tail->next = p;
		p->next = NULL;
		this->tail = p;
	

	}
	else
	{
		//AddFront(item);
		this->tail = this->head = p;

	}

	this->noOfItems++;

} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	// Fill this in
	
	if (this->noOfItems == 0) throw std::exception("Deque is empty !");
	else
	{
		DequeNode *node;
		int deletedFront;
		deletedFront = this->head->item;
		node=this->head;
		this->head = this->head->next;
		if (this->head == NULL)
			this->tail = NULL;
		else
			this->head->prev = NULL;
		delete node;

		this->noOfItems--;
		return deletedFront;
	}



	
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	// Fill this in

	int deletedRear=this->tail->item;
	if (this->noOfItems == 0) throw std::exception("Deque is empty !");
	else
	{
		DequeNode *node;
		node = this->tail;
		this->tail =this->tail->prev;
		if (this->tail == NULL)
			this->head = NULL;
		else
			this->tail->next = NULL;

		delete node;
	}


	this->noOfItems--;

	return deletedRear;
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	// Fill this in

	if (this->noOfItems == 0) 
		throw std::exception("Deque is empty !");
	else
		return this->head->item;

} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	// Fill this in

	if (this->noOfItems == 0)
		throw std::exception("Deque is empty !");
	else
		return this->tail->item;

} //end-Rear