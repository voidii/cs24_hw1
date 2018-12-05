#include <iostream>
#include <string>
#include "word.h"
using namespace std;

word::word(){
    used = 0;
	front_word = last_word = NULL;
}

string word::wordname(int n)
{
	wordNode *item;
	item = front_word;
	for (int i = 0; i < n; i++)
	{
		item = item->nextword;
	}
	return item->stored_word;
}

int word::number_of_word()
{
	return used;
}

void word::input_word(string input_word_name, string fname)//根据单词开头字母来合理插入到list的正确位置
{
	wordNode *item = new wordNode;
	item -> stored_word = input_word_name;
	wordNode *temp_check = front_word;
	for (int i = 0; i < used; i++)
	{
		if (item -> stored_word == temp_check -> stored_word)//如果已经有了单词，就让其file count + 1
		{
			(temp_check->head_of_list).add_in(fname);
			return;
		}
		temp_check = temp_check -> nextword;
	}
	while(used < 2)
	{
		if(used == 0)
		{
			front_word = last_word = item;
			List l;
			l.add_in(fname);
			(item -> head_of_list).front = l.front;
		}
		else
		{
			last_word -> nextword = item;
			last_word = item;
			List l;
			l.add_in(fname);
			(item -> head_of_list).front = l.front;
		}
	used = used + 1;
	return;
	}
	wordNode *temp1 = new wordNode;
	wordNode *temp2 = new wordNode;
	temp1 = front_word;
	temp2 = front_word->nextword;
	while(temp2 != NULL)//如果单词头字母大于前者但是小于后者，那么就插入在这里
	{
		if (inFront(temp1->stored_word, item->stored_word) && inFront(item->stored_word, temp2->stored_word))
		{
			temp1 -> nextword = item;
			temp2 -> prevword = item;
			item -> nextword = temp2;
			item -> prevword = temp1;
			List l;
			l.add_in(fname);
			(item -> head_of_list).front = l.front;
			return;
		}
		else
		{
			temp1 = temp1 -> nextword;
			temp2 = temp2 -> nextword;
		}
	}
	last_word -> nextword = item;
	item ->prevword = last_word;
	last_word = item;
	List l;
	l.add_in(fname);
	(item -> head_of_list).front = l.front;
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