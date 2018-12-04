#include "list.h"
#include <iostream>

List::List()
{
	size = 0;
	front = NULL;
	rear = NULL;
}

Node List::*head()
{
	return front;
}

void List::add_in(string fname)
{
	int max = 0;//为了后续的排序，先设置一个标准
	if (size == 0)
	{
		Node *item = new Node;
		(item -> file_name).set_filename(fname);
		(item -> file_name).set_count(1);
		front = rear = item;
		size++;
	}
	else if (size == 1)
	{
		Node *item = new Node;
		(item -> file_name).set_filename(fname);
		if ((item -> file_name).filename() == (front -> file_name).filename())
		{
			(front -> file_name).set_count((front -> file_name).count() + 1);//如果已经存在，那么头文字count + 1
			delete item;
		}
		else
		{
			rear -> next = item;
			rear = item;
		}
	}
	else//当至少有两个Node之后就可以开始在adding的时候根据次数大小调整位置
	{
		Node* temp = front;
		Node* temp2 = front;//因为temp2要一直循环，所以设置temp3来记录max所在位置
		Node* temp3 = front;
		for (int i=0; i<size; i++) 
		{
			if ((temp -> file_name).filename() == fname)//检测是否已经存在
			{
				(temp -> file_name)set_count((temp -> file_name).count() + 1);
				return;
			}
			else
			{
				temp = temp -> next;
			}
		}
		Node* temp = item;//不存在就加在末尾
		(item -> filename).set_filename(fname);
		(item -> filename).set_count(1);
		rear -> next = item;
		rear = item;
		
		//开始检测count最大的那个字
		max = (temp2->file_name).count();
		for (int i = 0; i < size; i++)
		{
			temp2 = temp2 -> next;
			if ((temp2->file_name).count() > max)
			{
				max = (temp2->file_name).count();
				temp3 = temp2;
			}
		}
		temp3 -> next -> prev = temp3 -> prev;//调整temp3的位置，放入首位
		temp3 -> prev -> next = temp3 -> next;
		temp3 -> next = front;
		front -> prev = temp3;
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












