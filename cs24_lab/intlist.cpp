// intlist.cpp
// Implements class IntList
// Frank Zhang, 11/02
#include "intlist.h"

#include <iostream>
using std::cout;

// return sum of values in list
int IntList::sum() const {
	Node *n = first;
	int sum = 0;
	while(true)
	{
        if (n == NULL)
        {
			break;
		}
		else
		{
			sum = sum + n->info;
			n = n->next;
		}
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
	Node *m = first;
	if (m == NULL)
	{
		return false;
	}
	while(true)
	{
        if (m -> info == value)
        {
			return true;
		}
		if (m -> next == NULL)
		{
			return false;
		}
		else
		{
			m = m->next;
		}
    }

}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    
	Node *n = first;
	if (n == NULL)
	{
		return 0;
	}
	int max = n->info;
	if (n == 0)
        {
			return 0;
		}
	while(true)
	{
        if (n->next == NULL)
        {
			return max;
		}
		if (n -> next -> info > max)
		{
			max = n -> next -> info;
		}
		n = n->next;
    }  
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
	double result = 0.0;
	if (count() == 0)
	{
		return 0;
	}
	result = double(sum())/double(count());
    return result;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
	Node *n = new Node;
	n -> next = first;
	n->info = value;
	first = n;
	
    // IMPLEMENT
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }

// destructor deletes all nodes
IntList::~IntList() {
    Node *n = first;
    while (n) {
        Node *garbage = n;
        n = n->next;
        delete garbage;
    }
}

// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
