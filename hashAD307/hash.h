/*-----------------------------------------------------------------------------
Class:      hash

Functions:  
			constructor
			hashKey
			addWord
			search
			destructor

Defines the prototype of the hash class.
-----------------------------------------------------------------------------*/
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hashTable
{
public:
	
	hashTable();
	
	int hashKey(string key);
	
	void addWord(string def);
	
	int search(string unDef, int count);
	
	~hashTable();

private:
	
	static const int table = 20; 
	
	struct wordNode
	{
		string definition;
		
		wordNode * link;
	};
	
	wordNode * wordTable[table];
};





#endif