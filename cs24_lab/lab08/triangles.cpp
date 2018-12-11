// triangles.cpp - more recursive print functions
// Frank Zhang. 12/02

#include <iostream>
using namespace std;
/*
// recursively prints n asterisks ('*') on one line to cout
void stars(int n) {
    // IMPLEMENT
	if (n > 0)
	{
		cout << "*";
		stars(n-1);
	}
}

// recursively prints rows of '*', first n, then n-1, ... 1
void triangle(int n) {
    // IMPLEMENT
	if (n > 0)
	{
		stars(n);
		cout << endl;
		triangle(n -1);
	}
}

// recursively prints rows of '*' in reverse: 1, 2, ... n
void rtriangle(int n) {
    // IMPLEMENT
	if (n > 0)
	{
		rtriangle(n -1);
		stars(n);
		cout << endl;
	}
}

int main() {
    int size;
    cout << "enter size: " << endl;
    cin >> size;

    //stars(size); // first test only; then delete

    triangle(size);
    rtriangle(size);

}*/struct Node
	{
		//itemtype file_name;
		int count;
		Node* next;
		Node* prev;
	};
	
class List{
	
public:
	Node *front, *rear;
	int size;
	
	List() {size = 0;}
	
	void enqueue(int n) 
	{
		if (size == 0)
		{
		Node* item = new Node;
		item -> count = n;
		front = rear = item;
		size++;
		}
		Node* item = new Node;
		item -> count = n;
		rear -> next = item;
		rear = item;
		size++;
	}
	void rearrange_file()
	{
	Node* temp_one = front;
	Node* temp_two = front;
	while(true)
	{
		temp_two = temp_two -> next;
		if(temp_one -> count < temp_two -> count)
		{
			temp_one -> next -> prev = temp_two;
			temp_one -> prev -> next = temp_two;
			temp_two -> next -> prev = temp_one;
			temp_two -> next -> prev = temp_one;
		}
		if(temp_two == NULL)
		{
			break;
		}
	}
	}
    // IMPLEMENT (remember to consider special cases)
};

/*void rearrange_file()
{
	Node* temp_one = front;
	Node* temp_two = front;
	while(true)
	{
		temp_two = temp_two -> next;
		if(temp_one -> count < temp_two -> count)
		{
			temp_one -> next -> prev = temp_two;
			temp_one -> prev -> next = temp_two;
			temp_two -> next -> prev = temp_one;
			temp_two -> next -> prev = temp_one;
		}
		if(temp_two == NULL)
		{
			break;
		}
	}
}*/

int main()
{
	List l;
	for (int i=1; i<=8; i++)
	{
        l.enqueue(i * 7);
	}
	Node* item = l.front;
	for (int i=1; i<=8; i++)
	{
		cout << item -> count << endl;
		item = item->next;
	}
	l.rearrange_file();
	return 0;
	
	



}





