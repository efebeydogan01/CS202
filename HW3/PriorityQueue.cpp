/*
* Title: Heaps
* Author: Efe Beydogan
* ID: 21901548
* Section: 1
* Assignment: 3
* Description: priority queue main file
*/

#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue( int size) {
    h = new Heap( size);
}

PriorityQueue::~PriorityQueue() {
    delete h;
}

bool PriorityQueue::pqIsEmpty() const {
	return h->heapIsEmpty();
}

void PriorityQueue::pqInsert(const PQItemType& newItem) {
    h->heapInsert(newItem);
}

void PriorityQueue::pqDelete(PQItemType& priorityItem) {
    h->heapDelete(priorityItem);
}

void PriorityQueue::print() {
    h->print();
}
