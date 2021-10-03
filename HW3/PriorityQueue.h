/*
* Title: Heaps
* Author: Efe Beydogan
* ID: 21901548
* Section: 1
* Assignment: 3
* Description: priority queue header file
*/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Heap.h"
using namespace std;

typedef HeapItemType PQItemType;

class PriorityQueue {
public:
	PriorityQueue( int size);
	~PriorityQueue();

	// priority-queue operations:
	bool pqIsEmpty() const;
	void pqInsert(const PQItemType& newItem);
	void pqDelete(PQItemType& priorityItem);
	void print();

private:
	Heap* h;
};

#endif // PRIORITYQUEUE_H





