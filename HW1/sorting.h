/*
* Title: Sorting and Algorithm Efficiency
* Author: Efe Beydoðan
* ID: 21901548
* Section: 1
* Assignment: 1
* Description: Sorting algorithms
*/

#ifndef SORTING_H
#define SORTING_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <iomanip>


    void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
    void quickSort(int *arr, const int size, int &compCount, int &moveCount);
    void radixSort(int *arr, const int size);
    void mergesort( int* arr, int first, int last, int& compCount, int& moveCount);
    void merge( int* theArray, int first, int mid, int last, int& compCount, int& moveCount);
    void quickSort( int *theArray, int first, int last, int &compCount, int &moveCount);
    void partition( int* theArray, int first, int last, int& pivotIndex, int& compCount, int& moveCount);
    void radixsort( int* arr, const int n, const int d);
    int getDigit( int number, int index);
    void performanceAnalysis();

    void displayArray(const int *arr, const int size);
    void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

#endif // SORTING_h
