#ifndef LIST_H
#define LIST_H
#include <cstdlib>
#include <string>
using namespace std;
struct FileNode {

string file_name;
int wordCount;
FileNode* prevNode;
FileNode* nextNode;
FileNode(): wordCount(0), prevNode(NULL), nextNode(NULL), file_name(" ") {}
} ;

class List{
public:
	int size;
	FileNode *front, *rear;
	List();
	FileNode *head();//return front
	void add_in(string fname);//在list末尾加入文件
	int get_count(FileNode *item_to_got_count);
	
};
#endif