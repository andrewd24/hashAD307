#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "hash.h"

using namespace std;
/*-----------------------------------------------------------------------------
Function:     Constructor

Inputs:       None

Upon creation of new hash object, the wordTable array is looped through and 
initialized to empty strings and NULL pointers.
-----------------------------------------------------------------------------*/
hashTable::hashTable()
{	
	for (int i = 0; i < table; i++)
	{ 
		wordTable[i] = new wordNode;
	
		wordTable[i]->definition = " ";
		
		wordTable[i]->link = NULL;
	}
}

/*-----------------------------------------------------------------------------
Function:     hashKey

Inputs:       string key value (value to be hashed)

Adds all of the chars of the word together and mods them by the size of the hash
tables to find the key to insert the word into.
-----------------------------------------------------------------------------*/
int hashTable::hashKey(string key)
{
	int index;
	
	int hash = 0;
	
	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}
	
	index = hash % table;
	
	return index;
}

/*-----------------------------------------------------------------------------
Function:     AddWord

Inputs:       string definition

Calls hashKey to find the index to hash the word into.  Creates a wordNode and
chains the word into the correct slot.
-----------------------------------------------------------------------------*/
void hashTable::addWord(string def)
{
	int index = hashKey(def);

	if (wordTable[index]->definition == " ")
	{
		wordTable[index]->definition = def;
	}

	else 
	{
		wordNode * current = wordTable[index];
		
		wordNode * n = new wordNode;
		
		n->definition = def;
		
		n->link = NULL;

		while (current->link != NULL)
		{
			current = current->link;
		}
		current->link = n;
	}
}
/*-----------------------------------------------------------------------------
Function:     Search

Inputs:       string unDefined, int count

searches the hash table for the word to check if it is undefined or not.
-----------------------------------------------------------------------------*/
int hashTable::search(string unDef, int count)
{
	int index = hashKey(unDef);
	
	bool found = false;
	
	wordNode * current = wordTable[index];

	while (current != NULL)
	{
		if (current->definition == unDef)
		{
			found = true;
			
			current = NULL;
		}
		
		else current = current->link;
	}
	
	if (found == false)
	{
		count++;
		
		cout << unDef << " is not spelled correctly or not defined in the dictionary." << endl;
	}
	
	return count;
}

/*-----------------------------------------------------------------------------
Destructor:   Loops through the array and deletes all chained values of the 
hash table.
-----------------------------------------------------------------------------*/
hashTable::~hashTable()
{
	for (int i = 0; i < table; i++)
	{
		wordNode * current = wordTable[i];
		
		wordNode * temp = new wordNode;
		
		while (current != NULL)
		{
			temp = current;
		
			current = current->link;
			
			delete temp;
		}
		delete current;
	}
}