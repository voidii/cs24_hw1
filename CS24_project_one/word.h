#ifndef WORD_H
#define WORD_H
#include <cstdlib>
#include "bag.h"
using namespace std;

class wordddd{
public:
	//void print();
	wordddd();
	void input_word(string input_word_name);
	string wordname() const;
	void bag_file_add_one(string fname);
	void get_file_name();
	//void add_count();
	//int size();
	//int name_used;
private:
	bag file_contain_word;
	string words;
	int used;
};
#endif
 