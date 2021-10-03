/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : queue header
*/

#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

typedef int QueueItemType;

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
