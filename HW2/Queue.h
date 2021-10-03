/*
* Title: Binary Search Trees
* Author: Efe Beydoðan
* ID: 21901548
* Section: 1
* Assignment: 2
* Description: Queue header
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "BinaryNode.h"
using namespace std;

typedef BinaryNode* QueueItemType;

class Queue{
public:
    Queue();                     // default constructor
    ~Queue();                    // destructor

    // Queue operations:
    bool isEmpty() const;
    bool enqueue(QueueItemType newItem);
    bool dequeue();
    bool dequeue(QueueItemType& queueFront);
    bool getFront(QueueItemType& queueFront) const;

private:
    // The queue is implemented as a linked list with one external
    // pointer to the front of the queue and a second external
    // pointer to the back of the queue.

    struct QueueNode{
        QueueItemType  item;
        QueueNode     *next;
    };
    QueueNode *backPtr;
    QueueNode *frontPtr;
};

#endif // QUEUE_H
