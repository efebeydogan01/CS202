/*
* Title: Binary Search Trees
* Author: Efe Beydoðan
* ID: 21901548
* Section: 1
* Assignment: 2
* Description: Binary Node header file
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H
using namespace std;
#include <cstddef>
#include <iostream>
typedef int TreeItemType;

class BinaryNode {
    private:
    BinaryNode();
    BinaryNode(const TreeItemType& nodeItem, BinaryNode *left = NULL, BinaryNode *right = NULL);

    TreeItemType getItem();
    void setItem( TreeItemType newItem);

    TreeItemType item;       // data portion
    BinaryNode *leftChildPtr;  // pointer to left child
    BinaryNode *rightChildPtr; // pointer to right child

    friend class BinarySearchTree;
    friend class Queue;
};

























#endif // BINARYNODE_H
