/*
* Title: Sorting and Algorithm Efficiency
* Author: Efe Beydoðan
* ID: 21901548
* Section: 1
* Assignment: 1
* Description: Main method
*/

#include "sorting.h"
#include <iostream>

using namespace std;
int main() {
    int size = 16;
    int* arr = new int[size]{12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int compCount = 0;
    int moveCount = 0;


    selectionSort( arr, size, compCount, moveCount);
    cout << "Selection sort: " << endl;
    cout << "Number of key comparisons: " << compCount << endl;
    cout << "Number of data moves: " << moveCount << endl;
    cout << "Array after sorting: ";
    displayArray( arr, size);
    cout << endl;

    delete [] arr;
    arr = new int[size]{12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    compCount = 0;
    moveCount = 0;

    mergeSort( arr, size, compCount, moveCount);
    cout << "mergesort: " << endl;
    cout << "Number of key comparisons: " << compCount << endl;
    cout << "Number of data moves: " << moveCount << endl;
    cout << "Array after sorting: ";
    displayArray( arr, size);
    cout << endl;

    delete [] arr;
    arr = new int[size]{12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    compCount = 0;
    moveCount = 0;

    quickSort( arr, size, compCount, moveCount);
    cout << "quicksort: " << endl;
    cout << "Number of key comparisons: " << compCount << endl;
    cout << "Number of data moves: " << moveCount << endl;
    cout << "Array after sorting: ";
    displayArray( arr, size);
    cout << endl;

    delete [] arr;
    arr = new int[size]{12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    compCount = 0;
    moveCount = 0;

    radixSort( arr, size);
    cout << "radixsort: " << endl;
    cout << "Array after sorting: ";
    displayArray( arr, size);
    cout << endl;
    delete [] arr;

    performanceAnalysis();
}
