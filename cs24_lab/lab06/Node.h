#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
	public:
    int data;
    Node* next;
};

class dNode
{
	public:
	int data;
	dNode* next;
	dNode* pre;
};

class LinkedList {
	public:
    Node* head;
    Node* tail;
};
class DLinkedList {
	public:
    dNode* head;
    dNode* tail;
};

void printList(LinkedList* list);
void insertToFront(LinkedList* list, int value);
void insert(DLinkedList* list, int value);
void reverseDL(DLinkedList* dlist);
void printDList(DLinkedList* dlist);

#endif