#ifndef LIST_H
#define LIST_H
#include <cstdlib>
#include "itemtype.h"

class List{
	
private:
	struct Node
	{
		itemtype file_name;
		//int count;
		Node* next;
		Node* prev;
	};
	Node *front, *rear;
	int size;
	
public:
	List();
	Node head();//return front
	void add_in(string fname);//在list末尾加入文件
	//void rearrange_file();//根据count移动文件
}；
#endif