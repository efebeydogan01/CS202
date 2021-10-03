/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : word header file
*/

#ifndef WORD_H
#define WORD_H

using namespace std;
#include <string>
class Word {
public:
    Word();
    Word( string name, int ind);
    string getWord() const;
    int getIndex() const;

private:
    string word;
    int index;
};


#endif


