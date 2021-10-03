/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : hash table source file
*/

#include "HashTable.h"
#include <string>
using namespace std;

HashTable::HashTable() {
    BUCKETS = 1031;
    listTable = new LinkedList[BUCKETS];
}

HashTable::~HashTable() {
    delete [] listTable;
}

int HashTable::hashFunction( const string &key, int tableSize) {
   int hashVal = 0;

   for (int i = 0; i < key.length(); i++)
	hashVal = 37 * hashVal + key[i];
   hashVal %=tableSize;
   if (hashVal < 0)   /* in case overflows occurs */
	hashVal += tableSize;

   return hashVal;
}

void HashTable::insertItem( Word word) {
    int index = hashFunction( word.getWord(), BUCKETS);
    listTable[index].insertList( 1, word);
}

int HashTable::returnIndex( string word) {
    // function to return the index of the word for the adjacency matrix
    int index = hashFunction( word, BUCKETS);
    return listTable[index].returnIndex( word);
}
