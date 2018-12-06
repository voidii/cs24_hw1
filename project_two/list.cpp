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
	return wordCount;
}

void List::add_in(string fname)
{
	int max = 0;//为了后续的排序，先设置一个标准
	FileNode *item = NULL;
	(item -> file_name) = fname;
	if (size == 0)
	{
		item -> wordCount = 1;
		front = rear = item;
		size++;
	}
	else if (size == 1)
	{
		if ((item -> file_name) == (front -> file_name))
		{
			front -> wordCount = front -> wordCount + 1;//如果已经存在，那么头文字count + 1
			delete item;
		}
		else
		{
			item -> prevNode = front;
			front -> nextNode = item;
			rear = item;
			size++;
		}
	}
	else//当至少有两个Node之后就可以开始在adding的时候根据次数大小调整位置
	{
		FileNode* temp1 = front;
		FileNode* temp2 = front;//因为temp2要一直循环，所以设置temp3来记录max所在位置
		FileNode* temp3 = front;
		for (int i=0; i<size; i++) 
		{
			if ((temp1 -> file_name) == fname)//检测是否已经存在
			{
				(temp1 -> file_name)->wordCount++;
				return;
			}
			else
			{
				temp1 = temp1 -> nextNode;
			}
		}
		Node* temp = item;//不存在就加在末尾
		item -> file_name = fname;
		item -> wordCount++;
		rear -> nextNode = item;
		item -> prevNode = rear;
		rear = item;
		
		//开始检测count最大的那个字
		max = temp2 -> wordCount;
		for (int i = 0; i < size; i++)
		{
			temp2 = temp2 -> nextNode;
			if (temp2->wordCount > max)
			{
				max = temp2->wordCount;
				temp3 = temp2;
			}
		}
		temp3 -> nextNode -> prevNode = temp3 -> prevNode;//调整temp3的位置，放入首位
		temp3 -> prevNode -> nextNode = temp3 -> nextNode;
		temp3 -> nextNode = front;
		front -> prevNode = temp3;
		front = temp3;
    }
}

/*void List::rearrange_file()
{
	Node* temp_one = front;
	Node* temp_two = front;
	while(true)
	{
		temp_two = temp_two -> next;
		if((temp_one -> file_name).count() < (temp_two -> file_name).count())
		{
			temp_one -> next -> prev = temp_two;
			temp_one -> prev -> next = temp_two;
			temp_two -> next -> prev = temp_one;
			temp_two -> next -> prev = temp_one;
		}
		if(temp_two == NULL)
		{
			break;
		}
	}
}
*/












