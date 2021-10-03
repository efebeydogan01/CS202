/*
* Title: Binary Search Trees
* Author: Efe Beydoðan
* ID: 21901548
* Section: 1
* Assignment: 2
* Description: Binary Search Tree header file
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
using namespace std;
#include <iostream>
#include "BinaryNode.h"
#include "Queue.h"

typedef void (*FunctionType)(int anItem);

void display( int anItem);

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void destroyTree( BinaryNode*& treePtr);
    bool isEmpty();
    int getHeight();
    int heightOfTree( BinaryNode* node);
    int getNumberOfNodes();
    bool add( const int newEntry);
    bool insertItem( BinaryNode*& node, int newItem);
    bool remove( const int anEntry);
    bool deleteItem( BinaryNode*& node, int newItem);
    void deleteNodeItem( BinaryNode*& node);
    void processLeftMost( BinaryNode*& nodePtr, int& treeItem);
    bool contains( const int anEntry);
    bool retrieveItem( BinaryNode* treePtr, int item);
    void preorderTraverse();
    void preorderPrint( BinaryNode* treePtr, FunctionType visit);
    void inorderTraverse();
    void inorderPrint( BinaryNode* treePtr, FunctionType visit);
    void postorderTraverse();
    void postorderPrint( BinaryNode* treePtr, FunctionType visit);
    void levelorderTraverse();
    void levelorderPrint( BinaryNode* treePtr);
    int span(const int a, const int b);
    int spanRecursive( const int a, const int b, int& count, BinaryNode* node);
    void mirror();
    void mirrorNodes( BinaryNode*& node);

private:
    BinaryNode* root;
    int noOfNodes;
};


#endif // BINARYSEARCHTREE_H
