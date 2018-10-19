//code part
#include <cstdlib>

using namespace std;

class node
{
	public:
		typedef double value_type;//
		node(const value_tyoe& d = value_type(),
			const node* l=NULL)//constructor
		{
			date = d;
			link = l;
		}
	void set_data(const value_type& d){data = d;}
	void set_link(const node*& l){link = l;}//modifiers
	
	value_type data() const {return data;}
	node* link() {return link;}
	const node* link() const {return link;}//observers
	
	private:
		value_type data;
		node* link;//pointer	
};

//Helper methods 
size_t list_length(const node* head)
{
	const node* temp_ptr = head;
	int count = 0;
	
	while (temp_ptr != NULL)
	{
		count++;
		temp_ptr = temp_ptr -> link();
	}
	return count;
}

void list_head_insert(node*& head, const node::value_type v)
{
	node* new_node(v, head);
	head = new_node;
}
	

//lecture note
/*Lmkod Lists
	Array
		1, Most of the time, during the excution, only part of array is being used. 90%都没有在被使用, low uliliage
		2，max limit
	Can we design a data structure that has no such limitation?
	
	a sequence of items：
		items arrageng one after another 
		each of the item is connected to the next by a link
		
	Head pointer
		node* head_ptr
	Tail pointer
		node* tail_ptr