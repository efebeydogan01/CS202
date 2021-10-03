/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : hash table header
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include "Word.h"
#include <string>
using namespace std;
class HashTable {
public:
    HashTable();
    ~HashTable();
    int hashFunction( const string &key, int tableSize);
    void insertItem( Word word);
    int returnIndex( string word);

private:
    LinkedList* listTable;
    int BUCKETS;

};

#endif
