#include <iostream>
#include <string>
//#include "itemtype.h"
#include "word.h"
//#include "bag.h"
using namespace std;

wordddd::wordddd(){
    used = 0;
}
  
string wordddd::wordname() const
{
	return words;
}

void wordddd::input_word(string input_word_name)
{
	words = input_word_name;
	used = used + 1;
}

void wordddd::bag_file_add_one(string fname)
{
	file_contain_word.add(fname);
}

void wordddd::get_file_name()
{
	file_contain_word.print();
}

//int word::size()
//{
//	return used;
//}S