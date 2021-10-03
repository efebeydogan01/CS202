/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : integer linked list header file
*/

#ifndef __LIST_H
#define __LIST_H


using namespace std;

typedef int ListItem;

class List {
public:
    List();
    List( const List& aList);
    ~List();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve ( int index, ListItem& dataItem) const;
    bool insertList( int index, ListItem newItem);
    bool removeList( int index);
    bool isCyclic( int index) const;

private:

    struct ListNode{
        ListItem item;
        ListNode* next;
    };

    int listSize;
    ListNode* head;

    ListNode* findList(int index) const;
};

#endif // __LINKEDLIST_H
