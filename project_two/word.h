#ifndef WORD_H
#define WORD_H
#include <cstdlib>
#include "list.h"
using namespace std;
struct wordNode
	{
		string stored_word;
		wordNode *prevword;
		wordNode *nextword;
		List head_of_list;//指向list的head
		//List* file_that_count_most;
	};
class word{
public:
	
	int used;
	
	//void print();
	word();
	void input_word(string input_word_name, string fname);//加入单词
	string wordname(int n);//返还第n个单词的单词名
	bool inFront(string input1, string input2);//检测1是否在2前面
	int number_of_word();//检测有多少词
	void set_up_list();
	
	wordNode *front_word = 0, *last_word = 0;

};
#endif
 