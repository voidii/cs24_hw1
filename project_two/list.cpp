#include <iostream>
#include <string>
#include "list.h"
using namespace std;

List::List()
{
	size = 0;
	front = NULL;
	rear = NULL;
}

FileNode* List::head()
{
	return front;
}

int List::get_count(FileNode *item_to_got_count)
{
	return item_to_got_count->wordCount;
}

void List::add_in(string fname)
{
	int max = 0;//为了后续的排序，先设置一个标准
	FileNode *item = new FileNode();
	(item -> file_name) = fname;
	if (size == 0)
	{
		item -> wordCount ++;
		front = rear = item;
		size++;
	}
	else if (size == 1)
	{
		if ((item -> file_name) == (front -> file_name))
		{
			(front -> wordCount) ++;//如果已经存在，那么头文字count + 1
			delete item;
		}
		else
		{
			item -> prevNode = front;
			front -> nextNode = item;
			rear = item;
			item->wordCount++;
			size++;
		}
	}
	else//当至少有两个Node之后就可以开始在adding的时候根据次数大小调整位置
	{	
		FileNode* temp1 = front;
		for (int i = 0; i < size; i++)
		{
			if ((temp1->file_name) == fname)//检测是否已经存在
			{
				(temp1->wordCount)++;
				break;
			}
			else
			{
				temp1 = temp1->nextNode;
			}
		}
		if (temp1 == NULL)
		{
			FileNode* temp = item;//不存在就加在末尾
			item->file_name = fname;
			(item->wordCount)++;
			rear->nextNode = item;
			item->prevNode = rear;
			rear = item;
			size++;
		}
		if (size == 2)
		{
			if (rear->wordCount > front->wordCount)
			{
				rear->nextNode = front;
				front->prevNode = rear;
				front->nextNode = NULL;
				rear->prevNode = NULL;
				rear = rear->nextNode;
				front = front->prevNode;
				return;
			}
		}
	}
	
		//开始检测count最大的那个字
	FileNode* temp2 = front;//因为temp2要一直循环，所以设置temp3来记录max所在位置
	FileNode* temp3 = front;
	max = temp2 -> wordCount;
	if (size > 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (temp2->wordCount > max)
			{
				max = temp2->wordCount;
				temp3 = temp2;
			}
			temp2 = temp2->nextNode;
		}
	}
	if (temp3 != front)
	{
		if (temp3 != rear)
		{
			FileNode* temp4 = front;
			temp3->nextNode->prevNode = front;//调整temp3的位置，放入首位
			temp3->prevNode->nextNode = front;
			front->nextNode = temp3->nextNode;
			front->prevNode = temp3->prevNode;
			temp3->nextNode = temp4->nextNode;
			temp4->nextNode->prevNode = temp3;
			temp3->prevNode = NULL;
			front = temp3;

		}
		else
		{
			temp3->nextNode = front->nextNode;
			front -> prevNode = temp3->prevNode;
			temp3->prevNode->nextNode = front;
			front->nextNode->prevNode = temp3;
			temp3->prevNode = NULL;
			front->nextNode = NULL;
			rear = front;
			front = temp3;
		}
	}
}











