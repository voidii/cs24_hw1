#ifndef LIST_H
#define LIST_H
#include <cstdlib>
#include "itemtype.h"
struct Node
	{
		itemtype file_name;
		//int count;
		Node* next;
		Node* prev;
	};
class List{
public:
	Node *front, *rear;
	List();
	//Node *head();//return front
	void add_in(string fname);//在list末尾加入文件
	int get_count(Node *item_to_got_count);
	int size;
};
#endif