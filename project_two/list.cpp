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
		if (size == 2)//当只有两个文件在list里面的时候，因为只有一头一尾，所以单独拿出来order
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
	FileNode* temp2 = front;
	FileNode* temp3 = front;
	max = temp2 -> wordCount;
	if (size > 1)
	{
		while (temp2->nextNode != NULL)//调整位置
		{
			temp2 = temp2->nextNode;
			if (temp2->wordCount > temp3->wordCount)
			{
				FileNode* temp4 = new FileNode;
				temp4->file_name = temp2->file_name;
				temp4->wordCount = temp2->wordCount;
				temp2->file_name = temp3->file_name;
				temp2->wordCount = temp3->wordCount;
				temp3->file_name = temp4->file_name;
				temp3->wordCount = temp4->wordCount;
				delete temp4;
			}
			temp3 = temp3->nextNode;
		}
	}
}











