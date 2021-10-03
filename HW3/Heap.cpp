/*
* Title: Heaps
* Author: Efe Beydogan
* ID: 21901548
* Section: 1
* Assignment: 3
* Description: heap main file
*/

#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap() {
    size = 0;
}
Heap::Heap( int heapSize) {
    items = new HeapItemType[heapSize];
    size = 0;
}

Heap::~Heap() {
    delete [] items;
}

bool Heap::heapIsEmpty() const {
    return ( size == 0);
}

void Heap::heapInsert(const HeapItemType& newItem) {

	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
    // if the item to be added has a smaller arrival time, trickle it up
    // or if the items' arrival times are equal but the new item has a higher priority, trickle it up
	while ( (place > 0) && items[place].getPriority() > items[parent].getPriority() ) {
        HeapItemType temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}

void Heap::heapDelete(HeapItemType&rootItem) {
    if ( size != 0) {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
    }
}

void Heap::heapRebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find child with higher priority or if the priorities are equal find the child with smaller request time
		if ( (rightChild < size) && ((items[rightChild].getPriority() > items[child].getPriority())
                                    || ( items[rightChild].getPriority() == items[child].getPriority() && items[rightChild].getReqTime() < items[child].getReqTime())) ) {
		     child = rightChild; 	// index of larger child
        }

		// If root’s priority is smaller or if the priorities are the same but the child has arrived earlier, change the places
		if ( items[root].getPriority() < items[child].getPriority() || ( items[root].getPriority() == items[child].getPriority() && items[child].getReqTime() < items[root].getReqTime()) ) {
			HeapItemType temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}

void Heap::print() {
    for ( int i = 0; i < size; i++) {
        cout << items[i].getId() << " " << items[i].getPriority() << " " << items[i].getReqTime() << " " << items[i].getProcTime() << endl;
    }
}
