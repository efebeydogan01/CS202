/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : stack header files
*/

#ifndef __STACK_H
#define __STACK_H

#include "List.h"
#include "Word.h"
#include <string>

typedef int StackItemType;

class Stack {
public:
    Stack();
    // Stack( const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push( StackItemType newItem);
    bool pop();
    bool pop( StackItemType& stackTop);
    bool getTop( StackItemType& stackTop) const;
    int getLength();
    bool isCyclic( int index) const;

private:
    List aList;
};

#endif // __STACK_H
