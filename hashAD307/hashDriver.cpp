/*-----------------------------------------------------------------------------
Programmer:   Andrew Douglas

Program:      Program that opens a dictionary file, inserts the words into a 
			  hash table.  Then opens check.txt which contains another dictionary
			  and checks the two against one another.  If no new words are found,
			  the message "No errors" is displayed.  If mismatches are found, it
			  the total number of mismatches is printed to the screen.

Course:       CSC 307 - Data structures using C++

Instructor:   Tom Rishel

Files:        hash.h, hashImp.cpp
-----------------------------------------------------------------------------*/
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "hash.h"

using namespace std;

int main()
{
	ifstream myFile;
	
	ifstream yourFile;
	
	myFile.open("dictionary.txt");
	
	yourFile.open("check.txt");
	
	if (!myFile.is_open())
	{
		cout << "Could not open dictionary.txt.  Terminating. " << endl;
		
		return 1;
	}
	
	else if (!yourFile.is_open())
	{
		cout << "Could not open check.txt.  Terminating. " << endl;
		
		return 1;
	}
	
	else
	{
		
		string word;
		
		string testWord;
		
		hashTable test;
		
		cout << "Building dictionary and searching your file for correct spelling." << endl;
		
		while (myFile.good())
		{
			myFile >> word;
		
			test.addWord(word);
		}
		
		int count = 0;
		int temp;
		
		while (yourFile.good())
		{
			yourFile >> testWord;
			
			temp = test.search(testWord, count);
		}
		
		if (temp < 1)
		{
			cout << "No errors to report." << endl;
		}
		
		else
		{
			cout << "There were " << temp << " mispelled words in your file" << endl;
		}
		
		myFile.close();
		yourFile.close();
		
	}

	cin.get();
	return 0;
}