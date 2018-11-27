// arrayQ.cpp - implements queue as array
// Frank Zhang, 11/18

#include "arrayQ.h"

Queue::Queue() { 
	size = 0;
}  // IMPLEMENT CONSTRUCTOR

void Queue::enqueue(int n) {
	if (isFull())
	{
        throw FullQueue();
	}
	else if(isEmpty())
	{
		data[0] = n;
		rear = 0;
		front = 0;
		size++;
	}
	else
	{
		rear = (rear + 1)%10;
		data[rear] = n;
		size++;
	}
    // COMPLETE THIS IMPLEMENTATION
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
	 
	int a = data[front];
	front = (front + 1)%10;
	size--;

    // COMPLETE THIS IMPLEMENTATION
    return a; // AND REPLACE THIS RETURN STATEMENT
}

void Queue::clear() {
	front = 0;
	rear = 0;
	size = 0;
    // IMPLEMENT
}

bool Queue::isEmpty() const {
	if (size == 0)
		return true;
	else 
		return false;
	// AND REPLACE THIS RETURN STATEMENT
}

bool Queue::isFull() const {
    // IMPLEMENT
	if (size == 10)
		return true;
	return false;
}

int Queue::getSize() const {
    // IMPLEMENT

    return size; // AND REPLACE THIS RETURN STATEMENT
}












