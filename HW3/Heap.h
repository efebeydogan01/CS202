/*
* Title: Heaps
* Author: Efe Beydogan
* ID: 21901548
* Section: 1
* Assignment: 3
* Description: heap header file
*/

#ifndef HEAP_H
#define HEAP_H

#include "Request.h"
using namespace std;
typedef Request HeapItemType;

class Heap {
public:
    Heap();
    Heap( int heapSize);
    ~Heap();

    bool heapIsEmpty() const;
    void heapInsert(const HeapItemType& newItem);
	void heapDelete(HeapItemType& rootItem);
	void print();

protected:
    void heapRebuild(int root);

private:

    HeapItemType* items;	// array of heap items
	int size;
};


#endif // HEAP_H

