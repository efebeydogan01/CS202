/*
* Title: Binary Search Trees
* Author: Efe Beydoðan
* ID: 21901548
* Section: 1
* Assignment: 2
* Description: Binary Node source file
*/
#include "BinaryNode.h"
using namespace std;
BinaryNode::BinaryNode() {
    item = 0;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

BinaryNode::BinaryNode( const TreeItemType& nodeItem, BinaryNode *left, BinaryNode *right) {
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
}

TreeItemType BinaryNode::getItem() {
    return item;
}

void BinaryNode::setItem( TreeItemType newItem) {
    item = newItem;

}
