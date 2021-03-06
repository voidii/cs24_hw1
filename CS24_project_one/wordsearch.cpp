#include <sys/types.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dirent.h"
#include "word.h"
#include "bag.h"
#include "itemtype.h"
#include "wordsearch.h"

using namespace std;


int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}

int main(int argc, char* argv[])
{
	string dir; //
	vector<string> files = vector<string>();
	bag bag_one;
	wordddd word_s[1000];
	int words_list_size = 0;



	if (argc < 2)
	{
		cout << "No Directory specified; Exiting ..." << endl;
		return(-1);
	}
	dir = string(argv[1]);
	if (getdir(dir, files) != 0)
	{
		cout << "Error opening " << dir << "; Exiting ..." << endl;
		return(-2);
	}

	string slash("/");
	for (unsigned int i = 0; i < files.size(); i++)
	{
		if (files[i][0] == '.')continue; 
		ifstream fin((string(argv[1]) + slash + files[i]).c_str()); 
		
		string word;
		while (true)
		{
			fin >> word;
			if (fin.eof())
			{
				break;
			}
			else
			{
				int j = 0;
				while (j <= words_list_size)
				{
					if (word_s[j].wordname() == word)
					{
						word_s[j].bag_file_add_one(files[i]);
						break;
					}
					else if (j == words_list_size)
					{
						word_s[j].input_word(word);
						words_list_size = words_list_size + 1;
					}
					else
					{
						j++;
					}
				}
			}

		}
		fin.close();
	}
		while (true)
		{
			cout << "Enter the word you want to look up: ";
			cin >> word_we_put_in;
			if( word_we_put_in != "exit")
			{
				int i = 0;
				while(i < words_list_size)
				{
					if (word_s[i].wordname() == word_we_put_in)
					{
						cout << "The word: " << word_s[i].wordname() << " and its occurence is: ";
						word_s[i].get_file_name();
						cout << endl;
						break;
					}
					else
					{
						i++;
					}
				}
				if (i == words_list_size)
				{
					cout << "Sorry there is no such word" << endl;
				}
			}
			else
			{
				break;
			}
		}
	return 0;
}

