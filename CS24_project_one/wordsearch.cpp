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




using namespace std;

/*function... might want it in some class?*/

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
  if (getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }
  
  string slash("/");
  for (unsigned int i = 0; i < files.size(); i++) 
  {
	if(files[i][0]=='.')continue; //skip hidden files
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file...
    string word;
    while(true)
	{
      fin>>word;
      if(fin.eof()) 
	  {
		cout << "EOF " << files[i] << endl; 
		//j = j + 1;
		//word_for_file[0].next_file;
		break;
	  }
      else 
	  {
	    int j = 0;
		while(j <= words_list_size)
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
				word_s[j].bag_file_add_one(files[i]);
				break;
			}
			else
			{
				j++;
			}
		}
		
		cout<<files[i]<<"::"<<word<<endl;
		//bag_one.add(files[i]);
		//word_for_file[j].file_word.add(word);
	
	// Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
	// Use these two strings to search/insert in your array/list of words.
      }
    }
    fin.close();
  }

  cout << "This is the next part of the program " << endl;
  //bag_one.print();
  for (int m = 0; m < words_list_size; m ++)
  {
	  cout << "there is word: " << word_s[m].wordname() << " and its occurence is: ";
	  word_s[m].get_file_name();
	  cout << endl;
  }
  return 0;
}



