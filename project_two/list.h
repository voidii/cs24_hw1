#ifndef LIST_H
#define LIST_H
#include <cstdlib>
/*struct Node
	{
		itemtype file_name;
		//int count;
		Node* next;
		Node* prev;
	};
class List{
public:
	Node *front, *rear;
	List();
	//Node *head();//return front
	void add_in(string fname);//在list末尾加入文件
	int get_count(Node *item_to_got_count);
	int size;
};*/
typedef struct FileWordCount {
FileWordCount(): wordCount(0), prevNode(NULL), nextNode(NULL) {}
string file_name;
int wordCount;
FileNode* prevNode;
FileNode* nextNode;
} FileNode;

class List{
public:
	FileNode *front, *rear;
	List();
	FileNode *head();//return front
	void add_in(string fname);//在list末尾加入文件
	int get_count(FileNode *item_to_got_count);
	int size;
};
#endif