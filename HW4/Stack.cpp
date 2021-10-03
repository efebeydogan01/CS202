/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : stack source file
*/

#include <iostream>

using namespace std;

#include "Stack.h"

Stack::Stack() {
}

Stack::~Stack(){
}

bool Stack::isEmpty() const {
    return aList.isEmpty();
}

bool Stack::getTop( StackItemType& stackTop) const {
    return aList.retrieve(1, stackTop);
}

bool Stack::push( StackItemType newItem) {
    return aList.insertList( 1, newItem);
}

bool Stack::pop() {
    return aList.removeList(1);
}

bool Stack::pop( StackItemType& stackTop) {
    if ( aList.retrieve( 1, stackTop))
        return aList.removeList(1);
    else
        return false;
}

int Stack::getLength() {
    return aList.getLength();
}

bool Stack::isCyclic( int index) const {
    return aList.isCyclic( index);
}
