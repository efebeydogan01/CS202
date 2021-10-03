/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : integer linked list source file
*/

#include <iostream>

using namespace std;

#include "List.h"

List::List() {
    listSize = 0;
    head = NULL;
}

List::List( const List& aList) {
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

List::~List() {
    while ( !isEmpty()) {
        removeList(1);
    }
}

bool List::isEmpty() const {
    return listSize == 0;
}

int List::getLength() const {
    return listSize;
}

bool List::retrieve( int index, ListItem& dataItem) const {
    if ( index < 1 || index > getLength()) {
        return false;
    }

    ListNode* cur = findList(index);
    dataItem = cur->item;

    return true;
}

bool List::insertList( int index, ListItem newItem) {
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

bool List::removeList( int index) {
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

bool List::isCyclic( int index) const {
    for ( int i = 1; i <= getLength(); i++) {
        if ( findList( i)->item == index) {
            return true;
        }
    }
    return false;
}

List::ListNode* List:: findList( int index) const{
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
