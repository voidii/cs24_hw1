#include <sys/types.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dirent.h"
#include "word.h"
#include "wordsearchcount.h"

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
	//bag bag_one;
	word w;
	//int words_list_size = 0;



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
		
		string word_we_put_in;
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
		while (true)
		{
			cout << "Enter word: ";
			cin >> word_we_put_in;
			cout << "Enter threshold: ";
			cin >> threshold;
			if( word_we_put_in != "exit")
			{
				int i = 0;
				wordNode *item = w.front_word;
				while (i < w.number_of_word())
				{
					if (w.wordname(i) == word_we_put_in)
					{
						Node *check_count_of_list = (item->head_of_list).front;
						while(check_count_of_list != NULL)
						{
							if((item->head_of_list).get_count(check_count_of_list) >= threshold)
							{
								cout << "File: " << (check_count_of_list->file_name).filename() << "; " << "Count: " << (item->head_of_list).get_count(check_count_of_list) << endl;
								check_count_of_list = check_count_of_list -> next;
							}
							else{
								break;
							}
						}
						break;
					}
					else
					{
						i++;
						item = item -> nextword;
					}
				}
			}
			else
			{
				break;
			}
		}
	return 0;
}

