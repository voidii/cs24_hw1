// usestack.cpp - for CS 24 lab practice using stacks
// NAME(S), DATE

#include "intstack.h"
#include <iostream>
using namespace std;

int main() {
    Stack s;
	int right;
	int left;

    s.push(10);
    s.push(20);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
	// evaluating "8 8 9 10 11 + - * *"
	Stack numbers;
	numbers.push(8);
	numbers.push(8);
	numbers.push(9);
	numbers.push(10);
	numbers.push(11);

	right = numbers.top();
	numbers.pop();
	left = numbers.top();
	numbers.pop();
	numbers.push(left + right);

	right = numbers.top();
	numbers.pop();
	left = numbers.top();
	numbers.pop();
	numbers.push(left - right);	
	
	right = numbers.top();
	numbers.pop();
	left = numbers.top();
	numbers.pop();
	numbers.push(left * right);
	
	right = numbers.top();
	numbers.pop();
	left = numbers.top();
	numbers.pop();
	numbers.push(left * right);
	
	cout << numbers.top() << endl;
	
    return 0;
}