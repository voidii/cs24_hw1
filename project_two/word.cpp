#include <iostream>
#include <string>
#include "word.h"
using namespace std;

word_list::word_list(){
}

string word_list::wordname(int n)
{
	WordNode *item;
	item = front_word;
	for (int i = 0; i < n; i++)
	{
		item = item->nextNode;
	}
	return item->stored_word;
}

int word_list::number_of_word()
{
	return used;
}

FileNode* List::head()
{
	return front;
}

void word_list::input_word(string input_word_name, string fname)//根据单词开头字母来合理插入到list的正确位置
{
	WordNode *item = NULL;
	item -> stored_word = input_word_name;
	WordNode *temp_check = front_word;
	for (int i = 0; i < used; i++)
	{
		if (item -> stored_word == temp_check -> stored_word)//如果已经有了单词，就让其file count + 1
		{
			(temp_check->fileListHead).add_in(fname);
			return;
		}
		temp_check = temp_check -> nextNode;
	}
	while(used < 2)
	{
		if(used == 0)
		{
			front_word = last_word = item;
			List l;
			l.add_in(fname);
			(item->fileListHead) = l.head();
		}

		else
		{
			item -> prevNode = front_word;
			front_word -> nextNode = item;
			last_word = item;
			List l;
			l.add_in(fname);
			(item->fileListHead) = l.head();
		}
	used = used + 1;
	return;
	}
	WordNode *temp1 = new WordNode;
	WordNode *temp2 = new WordNode;
	temp1 = front_word;
	temp2 = front_word -> nextNode;
	while(temp2 != NULL)//如果单词头字母大于前者但是小于后者，那么就插入在这里
	{
		if (inFront(temp1->stored_word, item->stored_word) && inFront(item->stored_word, temp2->stored_word))
		{
			temp1 -> nextNode = item;
			temp2 -> prevNode = item;
			item -> nextNode = temp2;
			item -> prevNode = temp1;
			List l;
			l.add_in(fname);
			(item->fileListHead) = l.head();
			return;
		}
		else
		{
			temp1 = temp1 -> nextNode;
			temp2 = temp2 -> nextNode;
		}
	}
	last_word -> nextNode = item;
	item ->prevNode = last_word;
	last_word = item;
	List l;
	l.add_in(fname);
	(item->fileListHead) = l.head();
}

bool word_list::inFront(string input1, string input2)//检测1是否在2前面
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