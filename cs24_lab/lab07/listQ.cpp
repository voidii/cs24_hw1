// listQ.cpp - implements queue as linked list
// Frank Zhang, 11/18

#include "listQ.h"
#include <iostream>

Queue::Queue() { 
	size = 0;
}  // IMPLEMENT CONSTRUCTOR

Queue::~Queue() {
	clear();
	size = 0;
    // IMPLEMENT DESTRUCTOR (delete all the nodes)
}

void Queue::enqueue(int n) {
	if (isEmpty())
	{
		node* item = new node(n);
		front = rear = item;
		size++;
	}
	else 
	{
		node* item = new node(n);
		rear -> next = item;
		rear = item;
		size++;
	}
    // IMPLEMENT (remember to consider special cases)
}

int Queue::dequeue() {
    if (isEmpty())
	{
        throw EmptyQueue();
	}
	node *temp = front;
	int a = temp -> data;
	front = front -> next;
	temp -> data = 0;
	temp -> next = 0;
	delete temp;
	size--;
	
    // COMPLETE THIS IMPLEMENTATION (remember to delete node)
    return a; // AND REPLACE THIS RETURN STATEMENT
}

void Queue::clear() {
    // IMPLEMENT (delete all nodes and reset variables)
	for (int i = 0; i < size; i++)
	{
		node* temp;
		temp = front;
		front - front -> next;
		delete temp;
	}
	front = rear;
	size = 0;
}

bool Queue::isEmpty() const {
    // IMPLEMENT
	if (size == 0)
	{
		return true;
	}
    return false; // AND REPLACE THIS RETURN STATEMENT
}

int Queue::getSize() const {
	
    return size; // AND REPLACE THIS RETURN STATEMENT
}