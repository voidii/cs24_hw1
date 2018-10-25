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
//cs24_1023 part
void list_head_insert(node*& head, const node::value_type v)
{
	//node* new_node(v, head);
	//head = new_node;
	node* p;
	p = new node (v, head);//value, pointer
	head = p;
}

void list_insert(node* prev, const node::value_type& v)
{
	assert(prev != NULL);
	node* q;
	q = new node(v, prev -> link());
	prev -> set_link(q);
	prev = NULL;
}

node* list_search(node* head, const node::value_type& v)
{
	node* cursor = head;
	if (cursor == NULL)
	{
		return NULL;
	}
	else
	{
		while ((cursor != NULL) && cursor->data()) != v)
		{
			cursor = cursor->link();
		}
		return cursor
	}
}

void list_copy(node* src, node*& head, node*& tail)
{
	head = NULL;
	tail = NULL;
	
	if (src == NULL)//empty source list
	{
		return;
	}
	list_head_insert(head, src->data());
	tail = head;
	
	src = src->line();
	while (src != NULL)
	{
		list_insert(tail, src->data());
		src = src->link();
		tail = tail->link();
	
	
}


//lecture note
/*














