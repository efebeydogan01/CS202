/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : linked list source file
*/

#include <iostream>

using namespace std;

#include "LinkedList.h"

LinkedList::LinkedList() {
    listSize = 0;
    head = NULL;
}

LinkedList::LinkedList( const LinkedList& aList) {
    listSize = aList.listSize;

    if ( aList.head == NULL) {
        head = NULL;
    }
    else {
        head = new ListNode;
        head->item = aList.head->item;
        ListNode* ptr = head;

        for ( ListNode* origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next) {
            ptr->next = new ListNode;
            ptr = ptr->next;
            ptr->item = origPtr->item;
        }
        ptr->next = NULL;
    }
}

LinkedList::~LinkedList() {
    while ( !isEmpty()) {
        removeList(1);
    }
}

bool LinkedList::isEmpty() const {
    return listSize == 0;
}

int LinkedList::getLength() const {
    return listSize;
}

bool LinkedList::retrieve( int index, ListItemType& dataItem) const {
    if ( index < 1 || index > getLength()) {
        return false;
    }

    ListNode* cur = findList(index);
    dataItem = cur->item;

    return true;
}

bool LinkedList::insertList( int index, ListItemType newItem) {
    int newLength = getLength() + 1;

    if ( index < 1 || index > newLength) {
        return false;
    }
    ListNode* newPtr = new ListNode;
    listSize = newLength;
    newPtr->item = newItem;

    if ( index == 1) {
        newPtr-> next = head;
        head = newPtr;
    }
    else {
        ListNode* prev = findList(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}

bool LinkedList::removeList( int index) {
    ListNode* cur;

    if ( index < 1 || index > getLength()) {
        return false;
    }

    listSize--;

    if ( index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        ListNode* prev = findList(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }

    cur->next = NULL;
    delete cur;
    cur = NULL;
    return true;
}

int LinkedList::returnIndex( string word) {
    for ( int i = 1; i <= listSize; i++) {
        Word tmp;
        retrieve( i, tmp);
        if ( tmp.getWord() == word) {
            return tmp.getIndex();
        }
    }
    return -1;
}

LinkedList::ListNode* LinkedList:: findList( int index) const{
    if ( index < 1 || index > getLength()) {
        return NULL;
    }

    else {
        ListNode* cur = head;
        for ( int skip = 1; skip < index; skip++) {
            cur = cur->next;
        }
        return cur;
    }
}

