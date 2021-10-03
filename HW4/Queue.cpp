/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : queue source file
*/

#include "Queue.h"
#include <string>
using namespace std;

Queue::Queue() : backPtr(NULL), frontPtr(NULL){
}

Queue::~Queue(){
    while (!isEmpty())
        dequeue();
}

bool Queue::isEmpty() const {

    return backPtr == NULL;
}

bool Queue::enqueue(QueueItemType newItem){

    // create a new node
    QueueNode *newPtr = new QueueNode;

    // set data portion of new node
    newPtr->item = newItem;
    newPtr->next = NULL;

    // insert the new node
    if (isEmpty())   // insertion into empty queue
        frontPtr = newPtr;
    else             // insertion into nonempty queue
        backPtr->next = newPtr;

    backPtr = newPtr;  // new node is at back

    return true;
}

bool Queue::dequeue(){

    if (isEmpty())
        return false;

    else{
        // queue is not empty; remove front
        QueueNode *tempPtr = frontPtr;

        if (frontPtr == backPtr){   // special case
            frontPtr = NULL;
            backPtr = NULL;
        }
        else
            frontPtr = frontPtr->next;

        tempPtr->next = NULL;  // defensive strategy
        delete tempPtr;
        return true;
    }
}

bool Queue::dequeue(QueueItemType& queueFront){

    if (isEmpty())
        return false;

    else{
        // queue is not empty; retrieve front
        queueFront = frontPtr->item;
        dequeue();  // delete front

        return true;
    }

}

bool Queue::getFront(QueueItemType& queueFront)const {

    if (isEmpty())
        return false;

    else {
        // queue is not empty; retrieve front
        queueFront = frontPtr->item;

        return true;
    }
}
