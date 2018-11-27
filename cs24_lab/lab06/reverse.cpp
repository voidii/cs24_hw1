#include <iostream>
#include "Node.h"
using namespace std;

void printList(LinkedList* list) {
    for (Node* i = list->head; i != NULL; i = i->next) {
        cout << "[" << i->data << "]->";
    }
    cout << "null" << endl;
}
void printDList(DLinkedList* dlist) {
    for (dNode* i = dlist->head; i != NULL; i = i->next) {
        cout << "[" << i->data << "]->";
    }
    cout << "null" << endl;
}

void insertToFront(LinkedList* list, int value) {
    if (list->head == 0) {        // empty list
        Node* item = new Node;
        item->data = value;
        item->next = NULL;
        list->head = item;
        list->tail = item;
    } else {             // not empty
        Node* item = new Node;
        item->data = value;
        item->next = list->head;
        list->head = item;
    }
}

void insert(DLinkedList* dlist, int value)
{
	 if (dlist->head == 0) {        // empty list
        dNode* item = new dNode;
        item->data = value;
        item->next = NULL;
		item->pre = NULL;
        dlist->head = item;
        dlist->tail = item;
    } else {             // not empty
        dNode* item = new dNode;
        item->data = value;
        item->pre = dlist->tail;
        dlist->tail->next = item;
		dlist->tail = item;
		item->next = NULL;
    }
}

//void earse_one(DLinkedList* dlist)
/*bool exists(LinkedList* list, int value) {
    for (Node* i = list->head; i != NULL; i = i->next) {
        if (i->data == value)
            return true;
    }
    return false;
}

int length(LinkedList* list) {
    int counter = 0;
    // let's use a while loop instead of a for...
    Node* temp = list->head;
    while (temp != 0) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void deleteIndex(LinkedList* list, int index) {
    if (index >= length(list) || index < 0) {
        cerr << "Invalid index: " << index << endl;
        return;
    }

    // check if first item
    if (index == 0 && list->head != 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        delete temp;
        return;
    }

    Node* prev = list->head;
    Node* curr = list->head->next;
    for (int i = 1; i < index; i++) {
        prev = prev->next;
        curr = curr->next;
    }

    // remove the current node
    prev->next = curr->next;
    delete curr;

    // re-assign list->tail if curr was the last node.
    if (index == length(list) - 1)
        list->tail = prev;

    return;
}*/
void reverse(LinkedList* list)
{
	int counter = 0;
	int x;
	int y;
    Node* temp_one = list->head;
	Node* temp_two = list -> head;
    while (temp_one != 0) {
        counter++;
        temp_one = temp_one->next;
    }
	temp_one = list -> head;
	for (int i = 0; i < (counter/2); i++)
	{
		x = temp_one -> data;
		for (int m = 0; m < (counter - i)-1; m++)
		{
			temp_two = temp_two -> next;
		}
		y = temp_two -> data;
		temp_one -> data = y;
		temp_two -> data = x;
		temp_one = temp_one -> next;
		temp_two = list -> head;
	}
	
}

void reverseDL(DLinkedList* dlist)
{
	int counter = 0;
	int x;
	int y;
    dNode* temp_one = dlist->head;
	dNode* temp_two = dlist -> head;
    while (temp_one != 0) {
        counter++;
        temp_one = temp_one->next;
    }
	temp_one = dlist -> tail;
	for (int i = 0; i < (counter/2); i++)
	{
		temp_one = dlist->tail;
		temp_two = dlist -> head;
		for (int m = 0; m < (counter-i)-1; m++)
		{
			temp_two = temp_two -> next;
			temp_one = temp_one -> pre;
		}
		x = temp_one -> data;
		y = temp_two -> data;
		temp_two -> data = x;
		temp_one -> data = y;
	}
}
	
int main() {
    LinkedList* list = new LinkedList;
	DLinkedList* dlist = new DLinkedList;
    list->head = 0;
    list->tail = 0;
	dlist->head = 0;
    dlist->tail = 0;

    /*insertToFront(list, 10);
    insertToFront(list, 20);
    insertToFront(list, 30);
	insertToFront(list, 30);
	insertToFront(list, 30);
	insertToFront(list, 30);
	insertToFront(list, 30);*/
	insert(dlist, 10);
	insert(dlist, 20);
	insert(dlist, 30);
	insert(dlist, 40);
	insert(dlist, 50);
	insert(dlist, 60);
   // printList(list);    	// 30->20->10
	printDList(dlist);

// 3

    reverseDL(dlist);
    //printList(list);
	printDList(dlist);	// 30->20->null

    return 0;
}