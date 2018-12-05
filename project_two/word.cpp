#include <iostream>
#include <string>
//#include "itemtype.h"
#include "word.h"
#include "list.h"
using namespace std;

word::word(){
    used = 0;
	front_word = rear_word = NULL;
}

string word::wordname(int n)
{
	Node *item;
	item = front_word;
	for (int i = 0; i < n; i++)
	{
		item = item->next;
	}
	return item->stored_word;
}

void set_ptr_to_dll()
{
	file_that_count_most = list::head();//这个地方就是不知道怎么写玛德
}

int number_of_word()
{
	return used;
}

void word::input_word(string input_word_name)//根据单词开头字母来合理插入到list的正确位置
{
	Node *item = new Node;
	item -> stored_word = input_word_name;
	while(used < 2)
	{
		if(used == 0)
		{
			front_word = last_word = item;
		}
		else
		{
			last_word -> next = item;
			last_word = item;
		}
	used = used + 1;
	return;
	}
	Node *temp1 = front_word;
	Node *temp2 = front_word -> next;
	while(temp2 != NULL)//如果单词头字母大于前者但是小于后者，那么就插入在这里
	{
		if (inFront(temp1->stored_word, item->stored_word) && inFront(item->stored_word, temp2->stored_word))
		{
			temp1 -> next = item;
			temp2 -> prev = item;
			item -> next = temp2;
			item -> prev = temp1;
			return;
		}
		else
		{
			temp1 = temp1 -> next;
			temp2 = temp2 -> next;
		}
	}
	last_word -> next = item;
	item ->prev = last_word;
	last_word = item;
}

bool word::inFront(string input1, string input2)//检测1是否在2前面
{
	for(int i = 0; i < input1.length(); i++)
	{
		if (input1[i] > input2[i])
		{
			return false;
		}
	}
	return true;
}

/*void wordddd::bag_file_add_one(string fname)
{
	file_contain_word.add(fname);
}

void wordddd::get_file_name()
{
	file_contain_word.print();
}
*/
//int word::size()
//{
//	return used;
//}S