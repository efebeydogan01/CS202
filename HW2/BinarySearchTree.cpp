/*
* Title: Binary Search Trees
* Author: Efe Beydoðan
* ID: 21901548
* Section: 1
* Assignment: 2
* Description: Binary Search Tree source file
*/
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    noOfNodes = 0;
}

BinarySearchTree::~BinarySearchTree() {
    destroyTree( root);
}

void BinarySearchTree::destroyTree( BinaryNode*& treePtr) {
    if (treePtr != NULL){
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

bool BinarySearchTree::isEmpty() {
    return root == NULL;
}

int BinarySearchTree::getHeight() {
    return heightOfTree( root);
}

int BinarySearchTree::heightOfTree( BinaryNode* node) {
    if ( node == NULL) {
        return 0;
    }
    else {
        int left;
        int right;
        // Get the max height of left subtree
        left = heightOfTree( node->leftChildPtr);
        // Get the max height of right subtree
        right = heightOfTree( node->rightChildPtr);

        // Find the bigger of the height values
        if ( left > right) {
            // Add 1 for the current node
            return left + 1;
        }
        else {
            // Add 1 to the height for the current node
            return right + 1;
        }
    }
}

int BinarySearchTree::getNumberOfNodes() {
    return noOfNodes;
}

bool BinarySearchTree::add( const int newEntry) {
    return insertItem( root, newEntry);
}

bool BinarySearchTree::insertItem( BinaryNode*& node, int newItem) {
    // If node is null, insert
    if ( node == NULL) {
        node = new BinaryNode( newItem, NULL, NULL);
        noOfNodes++;
        return true;
    }
    // If the item is equal to newItem, return false because node already exists
    if ( node->item == newItem) {
        cout << "item already exists in the tree" << endl;
        return false;
    }
    // Check left subtree if the item is smaller than current node
    else if ( newItem < node->item) {
        insertItem( node->leftChildPtr, newItem);
    }
    // Check right subtree if the item is bigger than current node
    else {
        insertItem( node->rightChildPtr, newItem);
    }
}

bool BinarySearchTree::remove( const int anEntry) {
    return deleteItem( root, anEntry);
}

bool BinarySearchTree::deleteItem( BinaryNode*& node, int newItem) {
    // Empty tree
    if ( node == NULL) {
        return false;
    }
    // Position of deletion found
    else if ( node->item == newItem) {
        deleteNodeItem( node);
        noOfNodes--;
        return true;
    }
    // Keep searching for deletion position
    else if ( newItem < node->item) {
        deleteItem( node->leftChildPtr, newItem);
    }

    else {
        deleteItem( node->rightChildPtr, newItem);
    }
}

void BinarySearchTree::deleteNodeItem( BinaryNode*& node) {
    BinaryNode* delPtr;
    int replacementItem;

    // Test for leaf
    if ( ( node->leftChildPtr == NULL) && ( node->rightChildPtr == NULL)) {
        delete node;
        node = NULL;
    }

    // Test for no left child
    else if ( node->leftChildPtr == NULL) {
        delPtr = node;
        node = node->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }

    // Test for no right child
    else if ( node->rightChildPtr == NULL) {
        delPtr = node;
        node = node->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }

    // There are two children:
    // Retrieve and delete the inorder successor
    else {
        processLeftMost(node->rightChildPtr, replacementItem);
        node->item = replacementItem;
    }
}

void BinarySearchTree::processLeftMost( BinaryNode*& nodePtr, int& treeItem) {
    if (nodePtr->leftChildPtr == NULL) {
        treeItem = nodePtr->item;
        BinaryNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else
        processLeftMost(nodePtr->leftChildPtr, treeItem);
}

bool BinarySearchTree::contains( const int anEntry) {
    return retrieveItem( root, anEntry);
}

bool BinarySearchTree::retrieveItem( BinaryNode* treePtr, int item) {
    // item is not in the tree
    if ( treePtr == NULL) {
        return false;
    }
    // item has been found in the tree
    else if ( item == treePtr->item)
        return true;
    // check left subtree if the item is smaller than node
    else if ( item < treePtr->item) {
        retrieveItem( treePtr->leftChildPtr, item);
    }
    // check right subtree if the item is greater than node
    else {
        retrieveItem( treePtr->rightChildPtr, item);
    }
}

void display( int anItem) {
    cout << anItem << " ";
}

void BinarySearchTree::preorderTraverse() {
    cout << "Pre order traversal:" << endl;
    preorderPrint( root, display);
}

void BinarySearchTree::preorderPrint( BinaryNode* treePtr, FunctionType visit) {
    if ( treePtr != NULL) {
        visit(treePtr->item);
        preorderPrint(treePtr->leftChildPtr, visit);
        preorderPrint(treePtr->rightChildPtr, visit);
    }
}

void BinarySearchTree::inorderTraverse() {
    cout << "In order traversal:" << endl;
    inorderPrint( root, display);
}

void BinarySearchTree::inorderPrint( BinaryNode* treePtr, FunctionType visit) {
    if (treePtr != NULL) {
        inorderPrint(treePtr->leftChildPtr, visit);
        visit(treePtr->item);
        inorderPrint(treePtr->rightChildPtr, visit);
    }
}

void BinarySearchTree::postorderTraverse() {
    cout << "Post order traversal:" << endl;
    postorderPrint( root, display);
}

void BinarySearchTree::postorderPrint( BinaryNode* treePtr, FunctionType visit) {
    if (treePtr != NULL) {
        postorderPrint(treePtr->leftChildPtr, visit);
        postorderPrint(treePtr->rightChildPtr, visit);
        visit(treePtr->item);
    }
}

void BinarySearchTree::levelorderTraverse() {
    cout << "Level order traversal:" << endl;
    levelorderPrint( root);
}

void BinarySearchTree::levelorderPrint( BinaryNode* treePtr) {
    // print the nodes in level order iteratively
    if ( treePtr == NULL) {
        return;
    }
    // create a queue to hold nodes
    Queue q;
    // push the node in the queue
    q.enqueue( treePtr);

    while ( !q.isEmpty()) {
        BinaryNode* node;
        // dequeue the first node in the queue
        q.dequeue( node);
        // print the value of the first node in the queue
        cout << node->item << " ";

        // enqueue the left child
        if ( node->leftChildPtr != NULL) {
            q.enqueue( node->leftChildPtr);
        }

        // enqueue the right child
        if ( node->rightChildPtr != NULL) {
            q.enqueue( node->rightChildPtr);
        }
    }
}

int BinarySearchTree::span( const int a, const int b) {
    int count = 0;
    return spanRecursive( a, b, count, root);
}

int BinarySearchTree::spanRecursive( const int a, const int b, int& count, BinaryNode* node) {
    if ( node == NULL) {
        return count;
    }
    // if the node item is in the range, increase count
    if ( node->item >= a && node->item <= b) {
        count++;
    }
    // if the item is smaller than lower bound, return and go right
    else if ( node->item < a) {
        return spanRecursive( a, b, count, node->rightChildPtr);
    }
    // if the item is greater than upper bound, return and go left
    else if ( node->item > b) {
        return spanRecursive( a,b, count, node->leftChildPtr);
    }
    // check left and right subtrees
    spanRecursive( a, b, count, node->leftChildPtr);
    spanRecursive( a, b, count, node->rightChildPtr);
}

void BinarySearchTree::mirror() {
    mirrorNodes( root);
}

void BinarySearchTree::mirrorNodes( BinaryNode*& node) {
    // If the node is  null return
    if ( node == NULL) {
        return;
    }
    // switch the nodes
    BinaryNode* temp = node->leftChildPtr;
    node->leftChildPtr = node->rightChildPtr;
    node->rightChildPtr = temp;
    // finish off the left subtree
    mirrorNodes( node->leftChildPtr);
    // finish off the right subtree
    mirrorNodes( node->rightChildPtr);
}



