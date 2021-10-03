/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Efe Beydogan
* ID: 21901548
* Section : 1
* Assignment : 4
* Description : word source file
*/

#include "Word.h"
#include <string>
using namespace std;
#include <iostream>

Word::Word() {
    word = "";
    index = -1;
}

Word::Word( string name, int ind) {
    word = name;
    index = ind;
}

string Word::getWord() const {
    return word;
}

int Word::getIndex() const {
    return index;
}

