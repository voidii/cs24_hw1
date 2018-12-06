#ifndef WORD_H
#define WORD_H
#include <cstdlib>
#include <string>
#include "list.h"
using namespace std;
struct WordNode {

	WordNode* prevNode;
	WordNode* nextNode;
	FileNode* fileListHead;
	string stored_word;
	List list_for_word;
	WordNode(): prevNode(NULL), nextNode(NULL), fileListHead(NULL), stored_word(" ") {}
} ;

class word_list
{
public:
	
	void input_word(string input_word_name, string fname);//加入单词
	string wordname(int n);//返还第n个单词的单词名
	bool inFront(string input1, string input2);//检测1是否在2前面
	int number_of_word();//检测有多少词
	WordNode* front_word, *last_word;
	int used;
	word_list() : used(0), front_word(NULL), last_word(NULL){};
};
#endif
 