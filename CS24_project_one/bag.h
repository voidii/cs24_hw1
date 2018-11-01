#ifndef BAG_H
#define BAG_H
#include <cstdlib>
#include <iostream>
#include "itemtype.h"
#include <string>
using namespace std;

class bag
{
public:
    // constructor
    bag();
    // modifiers
    void add(string fname);
    // observers
    int size() const;
    void print() const;
	//string wenjianming;
private:
    itemtype file_names[100];
    int used;
};
#endif
