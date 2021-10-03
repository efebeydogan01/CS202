/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : word network source file
*/

#include "WordNetwork.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

WordNetwork:: WordNetwork( const string vertexFile, const string edgeFile) {
    ifstream wordFile;

    wordFile.open( vertexFile.c_str(), ios_base::in);
    string readWord;
    int counter = 0;
    int wordSize = 0;
    // read the vertices from the file one by one
    while ( wordFile.eof() == false) {
        getline( wordFile, readWord);
        if ( readWord.length() == 0) {
            continue;
        }
        // find the size of the words only once (this is done because otherwise the code doesn't run properly on dijkstra)
        if ( counter == 0) {
            for ( int i = 0; i < readWord.length(); i++) {
                if ( readWord[i] != 13) {
                    wordSize++;
                }
            }
        }
        readWord = readWord.substr( 0, wordSize);
        // create a word object with the string and index data
        Word word( readWord, counter);
        // insert the words into the hash table
        ht.insertItem( word);
        counter++;
    }
    wordFile.close();
    length = counter;
    wordFile.open( vertexFile.c_str(), ios_base::in);
    int counter2 = 0;
    string wordRead;
    vertices = new string[length];

    while ( wordFile.eof() == false) {
        getline( wordFile, wordRead);
        if ( wordRead.length() == 0) {
            continue;
        }
        wordRead = wordRead.substr( 0, wordSize);
        vertices[counter2] = wordRead;
        counter2++;
    }
    wordFile.close();

    // initialize adjacency matrix
    matrix = new int*[length];
    for ( int i = 0; i < length; i++) {
        matrix[i] = new int[length];
    }

    for ( int i = 0; i < length; i++) {
        for ( int k = 0; k < length; k++) {
            matrix[i][k] = 0;
        }
    }

    ifstream edges;
    edges.open( edgeFile.c_str(), ios_base::in);
    string text, first, second;
    // process the edges
    while ( edges.eof() == false) {
        getline( edges, text);
        if ( text.length() == 0) {
            continue;
        }
        //text = text.substr( 0, wordSize);
        //stringstream ss( text);
        // getline( ss, first, ',');
        // getline( ss, second, '\n');
        first = text.substr( 0, wordSize);
        second = text.substr( wordSize + 1, wordSize);
        // mark the edges as 1, both words are connected
        matrix[ht.returnIndex( first)][ht.returnIndex( second)] = 1;
        matrix[ht.returnIndex( second)][ht.returnIndex( first)] = 1;
    }
    edges.close();
}

WordNetwork::~WordNetwork() {
    for ( int i = 0; i < length; i++) {
        delete [] matrix[i];
    }

    delete [] matrix;

    delete [] vertices;
}

void WordNetwork::listNeighbors( const string word) {
    cout << "Neighbors of " << word << ":" << endl;
    int index = ht.returnIndex( word);
    if ( index == -1) {
        cout << "The word does not exist in the graph" << endl;
        return;
    }
    for ( int i = 0; i < length; i++) {
        if ( matrix[index][i] == 1) {
            cout << vertices[i] << endl;
        }
    }
}

void WordNetwork::listNeighbors( const string word , const int distance ) {
    int index = ht.returnIndex(word);
    if ( index == -1) {
        cout << "The word does not exist in the graph" << endl;
        return;
    }
    cout << "Neighbors of " << word << " with a distance of " << distance << ":" << endl;
    bfsNeighbor( index, distance);
}

void WordNetwork::listConnectedComponents() {
    bool* visited = new bool[length];
    for ( int i = 0; i < length; i++) {
        visited[i] = false;
    }
    int counter = 1;
    // iterate for every word in the network
    for ( int i = 0; i < length; i++) {
        if ( !visited[i]) {
            cout << "Connected component " << counter << endl;
            // use depth first search to find connected components
            dfsComponent( i, visited);
            counter++;
            cout << endl;
        }
    }

    delete [] visited;
}

void WordNetwork::findShortestPath( const string word1, const string word2) {
    cout << "Shortest path from " << word1 << " to " << word2 << endl;
    // use breadth first search to find the shortest path between words
    int word1Ind = ht.returnIndex( word1);
    int word2Ind = ht.returnIndex(word2);
    if ( word1Ind == -1 || word2Ind == -1) {
        cout << "Invalid input" << endl;
        return;
    }
    bfsPath( word1Ind, word2Ind);
}

void WordNetwork::bfsDistance( int startingVertex, int distance) {
    int** tmpMatrix = new int*[length];
    for ( int i = 0; i < length; i++) {
        tmpMatrix[i] = new int[length];
    }
    for ( int i = 0; i < length; i++) {
        for ( int j = 0; j < length; j++) {
            tmpMatrix[i][j] = matrix[i][j];
        }
    }

    Queue q;
    // bool* visited = new bool[length];
    int* level = new int[length];

    for ( int i = 0; i < length; i++) {
        // visited[i] = false;
        level[i] = 0;
    }

    // visited[startingVertex] = true;

    q.enqueue( startingVertex);
    level[startingVertex] = 0;
    Queue tmp;
    while ( !q.isEmpty()) {
        int currentVertex, i;
        q.dequeue( currentVertex);
        for ( i = 0; i < length; i++) {
            if ( tmpMatrix[currentVertex][i]) {
                q.enqueue( i);
                level[i] = level[currentVertex] + 1;
                tmpMatrix[currentVertex][i] = 0;
                if ( level[i] == distance) {
                    tmp.enqueue(i);
                }
            }
        }
    }
    while ( !tmp.isEmpty()) {
        int vert;
        tmp.dequeue(vert);

        cout << vertices[vert] << endl;
    }
    for ( int i = 0; i < length; i++) {
        delete [] tmpMatrix[i];
    }

    delete [] tmpMatrix;
    // delete [] visited;
    delete [] level;
}

void WordNetwork::dfsDistance( int startingVertex, int distance) {
    int** tmpMatrix = new int*[length];
    for ( int i = 0; i < length; i++) {
        tmpMatrix[i] = new int[length];
    }
    for ( int i = 0; i < length; i++) {
        for ( int j = 0; j < length; j++) {
            tmpMatrix[i][j] = matrix[i][j];
        }
    }
    int* levels = new int[length];
    Stack S;
    S.push( startingVertex);
    levels[startingVertex] = 0;
    while ( !S.isEmpty()) {
        int currentVertex, i;

        S.getTop( currentVertex);

        for ( i = 0; i < length; i++) {
            if ( tmpMatrix[currentVertex][i]) {
                S.push(i);
                levels[i] = levels[currentVertex] + 1;
                if ( levels[i] == distance) {
                    cout << vertices[i] << endl;
                }
                break;
            }
        }

        if ( i == length) {
            int top;
            S.pop( top);
            int next;
            S.getTop( next);
            tmpMatrix[next][top] = 0;
        }
    }
    for ( int i = 0; i < length; i++) {
        delete [] tmpMatrix[i];
    }

    delete [] tmpMatrix;

}

void WordNetwork::bfsPath( int startingVertex, int endingVertex) {
    Queue q;
    bool* visited = new bool[length];
    int* parent = new int[length];
    // int* distance = new int[length];

    for ( int i = 0; i < length; i++) {
        visited[i] = false;
        parent[i] = 0;
        // distance[i] = 0;
    }
    visited[startingVertex] = true;
    // distance[startingVertex] = 0;
    // the first vertex has parent -1
    parent[startingVertex] = -1;
    bool found = false;

    q.enqueue( startingVertex);
    while ( !q.isEmpty()) {
        int currentVertex;
        q.dequeue( currentVertex);
        // if the goal vertex is reached stop
        if ( currentVertex == endingVertex) {
            found = true;
            break;
        }
        for ( int i = 0; i < length; i++) {
            if ( matrix[currentVertex][i] && !visited[i]) {
                // mark the words as visited
                visited[i] = true;
                // keep track of the parents
                parent[i] = currentVertex;
                // distance[i] = distance[currentVertex] + 1;
                q.enqueue( i);
            }
        }
    }

    if ( !found) {
        cout << "A path does not exist between the two words" << endl;
    }
    else {
        printPath( endingVertex, parent);
    }

    delete [] visited;
    delete [] parent;
    // delete [] distance;
}

void WordNetwork::printPath( int endingVertex, int*& parent) {
    if ( endingVertex == -1) {
        return;
    }
    printPath( parent[endingVertex], parent);

    cout << vertices[endingVertex] << endl;
}

void WordNetwork::dfsComponent( int i, bool*& visited) {
    // mark the word as visited
    visited[i] = true;
    // print the element
    cout << vertices[i] << " ";
    // iterate for every unvisited neighbor of the word
    for ( int j = 0; j < length; j++) {
        // call depth first search on every unvisited neighbor and print them
        if ( !visited[j] && matrix[i][j]) {
            dfsComponent( j, visited);
        }
    }
}

void WordNetwork::bfsNeighbor( int startingVertex, int distance) {
    Queue q;
    // to keep track of which nodes are visited
    bool* visited = new bool[length];
    // keeps track of the levels of the nodes to find nodes with the given distance
    int* level = new int[length];
    int* parent = new int[length]; // PARENT

    for ( int i = 0; i < length; i++) {
        visited[i] = false;
        level[i] = 0;
        parent[i] = 0; // PARENT
    }
    // first node is visited
    visited[startingVertex] = true;
    // level of the starting node is 0
    level[startingVertex] = 0;
    q.enqueue( startingVertex);
    parent[startingVertex] = -1; // PARENT
    Queue tmp;
    while ( !q.isEmpty()) {
        int currentVertex;
        q.dequeue( currentVertex);

        for ( int i = 0; i < length; i++) {
            if ( matrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                q.enqueue( i);
                // the level is one more than the parent's level
                level[i] = level[currentVertex] + 1;
                parent[i] = currentVertex; // PARENT
                if ( level[i] == distance) {
                    tmp.enqueue( i);
                }
            }
        }
    }
    while ( !tmp.isEmpty()) {
        int vert;
        tmp.dequeue( vert);
        // cout << vertices[vert] << endl;
        printNeighborPath( vert, parent);
        cout << endl;
    }

    delete [] visited;
    delete [] level;
    delete [] parent; // PARENT
}

void WordNetwork::dfsNeighbor( int startingVertex, int distance) {
    int* parent = new int[length];
    List printed;
    for ( int i = 0; i < length; i++) {
        parent[i] = 0;
    }
    Stack S;
    S.push( startingVertex);
    parent[startingVertex] = -1;
    while ( !S.isEmpty()) {
        int currentVertex, i;

        S.getTop( currentVertex);

        for ( i = parent[currentVertex] + 1; i < length; i++) {
            if ( matrix[currentVertex][i] && !S.isCyclic(i)) {
                S.push(i);
                parent[i] = currentVertex;
                if ( S.getLength() == distance) {
                    printed.insertList( 1, i);
                }
                break;
            }
        }

        if ( i == length) {
            S.pop();
        }
    }

    while ( !printed.isEmpty()) {
        int tmp;
        printed.retrieve( 1, tmp);
        printed.removeList( 1);
        cout << vertices[tmp] << endl;
    }

    delete [] parent;
}

void WordNetwork::printNeighborPath( int endingVertex, int*& parent) {
    if ( endingVertex == -1) {
        cout << "\n";
        return;
    }
    printNeighborPath( parent[endingVertex], parent);
    if ( parent[endingVertex] == -1) {
        cout << vertices[endingVertex];
    }
    else
        cout << " -> " << vertices[endingVertex];

}

void WordNetwork::bfsNeighbor2( int startingVertex, int distance) {
    Queue q;
    int** tmpMatrix = new int*[length];
    for ( int i = 0; i < length; i++) {
        tmpMatrix[i] = new int[length];
    }
    for ( int i = 0; i < length; i++) {
        for ( int j = 0; j < length; j++) {
            tmpMatrix[i][j] = matrix[i][j];
        }
    }
    // keeps track of the levels of the nodes to find nodes with the given distance
    int* level = new int[length];
    int* parent = new int[length]; // PARENT

    for ( int i = 0; i < length; i++) {
        level[i] = 0;
        parent[i] = 0; // PARENT
    }
    // level of the starting node is 0
    level[startingVertex] = 0;
    q.enqueue( startingVertex);
    parent[startingVertex] = -1; // PARENT
    // Queue tmp;
    while ( !q.isEmpty()) {
        int currentVertex;
        q.dequeue( currentVertex);

        for ( int i = 0; i < length; i++) {
            if ( tmpMatrix[currentVertex][i]) {
                q.enqueue( i);
                tmpMatrix[currentVertex][i] = 0;
                // tmpMatrix[i][currentVertex] = 0;
                // the level is one more than the parent's level
                level[i] = level[currentVertex] + 1;
                parent[i] = currentVertex; // PARENT
                if ( level[i] == distance) {
                    cout << vertices[i] << endl;
                }
            }
        }
    }
//    while ( !tmp.isEmpty()) {
//        int vert;
//        tmp.dequeue( vert);
//        // cout << vertices[vert] << endl;
//        printNeighborPath( vert, parent);
//        cout << endl;
//    }

    cout << endl;

    delete [] level;
    delete [] parent; // PARENT
    for ( int i = 0; i < length; i++) {
        delete [] tmpMatrix[i];
    }

    delete [] tmpMatrix;


}


