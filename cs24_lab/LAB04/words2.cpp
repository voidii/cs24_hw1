// words2.cpp - implements class Words
// (fixed size array version)
//Frank Zhang, wrote in 10/25/2018

#include <cassert>
#include <string>
#include "words2.h"

using std::string;

namespace lab04_2
{
    Words::Words(unsigned int initial_capacity) {
        used = 0;
		data = new std::string[initial_capacity];
        capacity = initial_capacity;
    }
	
	Words::Words(const Words& source)
	{
		data = new std::string[source.get_capacity()];
		capacity = source.get_capacity();
		used = source.size();
		copy(source.data, source.data + used, data);
	}
    
    void Words::append(std::string word) {
		if (used == capacity)
		{
			capacity = used * 2;
		}
		std::string* data_new;
		data_new = new std::string[capacity];
		for (int i =0; i < used; i++)
		{
			data_new[i] = data[i];
		}
		
		data_new[used] = word;
		data = data_new;
		++ used;
    }
    
    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
    }
    
    unsigned int Words::size() const {
        return used;
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
    }
	
	Words& Words::operator = (const Words &source)
	{
		std::string *new_data;
		if (this == &source)
		{
			return *this;
		}
		if(capacity != source.capacity)
		{
			new_data = new std::string[source.get_capacity()];
			delete []data;
			data = new_data;
			capacity = source.get_capacity();
		}
		used = source.size();
		copy(source.data, source.data + used, data);
	}
	
	Words::~Words() {
		delete [] data;
	}
    
}

