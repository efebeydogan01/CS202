/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : word network header
*/
#ifndef WORDNETWORK_H
#define WORDNETWORK_H
#include "HashTable.h"
#include "Word.h"
#include "Stack.h"
#include "Queue.h"
#include "List.h"
using namespace std;
class WordNetwork {
public :
    WordNetwork ( const string vertexFile , const string edgeFile );
    ~WordNetwork() ;
    void listNeighbors( const string word );
    void listNeighbors( const string word , const int distance );
    void listConnectedComponents();
    void findShortestPath ( const string word1 , const string word2 );
    void bfsDistance( int startingVertex, int distance);
    void dfsDistance( int startingVertex, int distance);
    void bfsPath( int startingVertex, int endingVertex);
    void printPath( int endingVertex, int*& parent);
    void dfsComponent( int i, bool*& visited);
    void bfsNeighbor( int startingVertex, int distance);
    void dfsNeighbor( int startingVertex, int distance);
    void printNeighborPath( int endingVertex, int*& parent);
    void bfsNeighbor2( int startingVertex, int distance);

private:
    HashTable ht;
    int length;
    int** matrix;
    string* vertices;
};


#endif
