/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : linked list header file
*/

#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include "Word.h"
#include <string>
using namespace std;

typedef Word ListItemType;

class LinkedList {
public:
    LinkedList();
    LinkedList( const LinkedList& aList);
    ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve ( int index, ListItemType& dataItem) const;
    bool insertList( int index, ListItemType newItem);
    bool removeList( int index);
    int returnIndex( string word);

private:

    struct ListNode{
        ListItemType item;
        ListNode* next;
    };

    int listSize;
    ListNode* head;

    ListNode* findList(int index) const;
};

#endif // __LINKEDLIST_H
