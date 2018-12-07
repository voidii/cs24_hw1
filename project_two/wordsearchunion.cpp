#include <sys/types.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dirent.h"
#include "word.h"
#include "wordsearchunion.h"

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
	word_list w;

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

		while (true)
		{
			fin >> word_file_put_in;
			if (fin.eof())
			{
				break;
			}
			else
			{
				w.input_word(word_file_put_in, files[i]);
			}
		}
		fin.close();
	}
	string word1_we_put_in;
	string word2_we_put_in;
	cout << "Enter word1: ";
	cin >> word1_we_put_in;
	cout << "Enter Word2: ";
	cin >> word2_we_put_in;
	if( word1_we_put_in != "000")
	{
		int i = 0;
		int j = 0;
		WordNode *item_one = w.front_word;
		WordNode *item_two = w.front_word;
		while (i < w.number_of_word() && j < w.number_of_word())
		{
			if (w.wordname(i) == word1_we_put_in && w.wordname(j) != word2_we_put_in)
			{
				item_two = item_two -> nextNode;
				j++;
			}
			else if (w.wordname(i) != word1_we_put_in && w.wordname(j) == word2_we_put_in)
			{
				i++;
				item_one = item_one -> nextNode;
			}
			else if(w.wordname(i) == word1_we_put_in && w.wordname(j) == word2_we_put_in)
			{
				break;
			}
			else{
				i++;
				item_one = item_one -> nextNode;
				item_two = item_two -> nextNode;
				j++;
			}
		}
		FileNode *check_list1 = ((item_one->list_for_word).head());
		FileNode *check_list2 = ((item_two->list_for_word).head());
		while(check_list1 != NULL)
		{
			while (check_list2 != NULL)
			{
				if (check_list2 -> file_name == check_list1 -> file_name)
				{
					cout << check_list2 -> file_name << endl;
					break;
				}
				check_list2 = check_list2 -> nextNode;
			}
			check_list1 = check_list1 -> nextNode;
		}
	}
	else
	{
		return 0;
	}
	cout << "---Program exits" << endl;
	return 0;
}

