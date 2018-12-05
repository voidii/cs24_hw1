#ifndef WORD_H
#define WORD_H
#include <cstdlib>
#include "list.h"
using namespace std;

class word{
private:
	struct Node
	{
		string stored_word;
		Node *prev;
		Node *next;
		List* file_that_count_most;
	};
	int used;
	
public:
	//void print();
	word();
	void input_word(string input_word_name);//加入单词
	string wordname(int n) const;//返还第n个单词的单词名
	bool inFront(string input1, string input2)；//检测1是否在2前面
	int number_of_word();//检测有多少词
	void set_ptr_to_dll();//指向list的head
	
	Node *front_word, *last_word;

};
#endif
 