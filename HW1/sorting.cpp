/*
* Title: Sorting and Algorithm Efficiency
* Author: Efe Beydoðan
* ID: 21901548
* Section: 1
* Assignment: 1
* Description: Sorting algorithms
*/

#include "sorting.h"

using namespace std;
int MAX_SIZE = 40000;

void selectionSort( int* arr, const int size, int& compCount, int& moveCount) {
    for (int last = size - 1; last >= 1; --last) {
        // Finding the largest
        int largest = 0;
        for (int currentIndex = 1; currentIndex < last + 1; ++currentIndex)
        {
            if (arr[currentIndex] > arr[largest])
                largest = currentIndex;
            compCount++;
        }
        // Swap
        int tmp = arr[last];
        arr[last] = arr[largest];
        arr[largest] = tmp;
        moveCount = moveCount + 3;
    }
}

void mergeSort( int *arr, const int size, int &compCount, int &moveCount) {
    mergesort( arr, 0, size - 1, compCount, moveCount);
}

void quickSort( int *arr, const int size, int &compCount, int &moveCount) {
        quickSort( arr, 0, size - 1, compCount, moveCount);
}

void radixSort( int *arr, const int size) {
    int maxDigit = arr[0];
    // Find the maximum element in the array
    for ( int i = 1; i < size; i++) {
        if ( arr[i] > maxDigit)
            maxDigit = arr[i];
    }
    int digit = 0;
    // Determine the maximum digit count from the maximum element to pass into the radixSort algorithm
    while ( maxDigit != 0) {
        maxDigit = maxDigit / 10;
        digit++;
    }
    radixsort( arr, size, digit);
}

void mergesort( int* arr, int first, int last, int& compCount, int& moveCount) {
    if ( first < last) {
        int mid = ( first + last) / 2;

        mergesort( arr, first, mid, compCount, moveCount);
        mergesort( arr, mid + 1, last, compCount, moveCount);

        // merging the halves
        merge( arr, first, mid, last, compCount, moveCount);
    }
}

void merge( int* theArray, int first, int mid, int last, int& compCount, int& moveCount) {


    int* tempArray = new int[MAX_SIZE];
    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount++;
        if (theArray[first1] < theArray[first2]) {
            tempArray[index] = theArray[first1];
            moveCount++;
            ++first1;
        }
        else {
            tempArray[index] = theArray[first2];
            moveCount++;
            ++first2;
        }
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index) {
        tempArray[index] = theArray[first1];
        moveCount++;
    }


    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        tempArray[index] = theArray[first2];
        moveCount++;
    }


    // copy the result back into the original array
    for (index = first; index <= last; ++index) {
        theArray[index] = tempArray[index];
        moveCount++;
    }

    delete [] tempArray;
}


void quickSort( int *theArray, int first, int last, int &compCount, int &moveCount) {
    // Precondition: theArray[first..last] is an array.
    // Postcondition: theArray[first..last] is sorted.

	int pivotIndex;

    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quickSort(theArray, first, pivotIndex-1, compCount, moveCount);
        quickSort(theArray, pivotIndex+1, last, compCount, moveCount);
    }

}

void partition( int* theArray, int first, int last, int& pivotIndex, int& compCount, int& moveCount) {
    // Precondition: theArray[first..last] is an array; first <= last.
    // Postcondition: Partitions theArray[first..last] such that:
    //   S1 = theArray[first..pivotIndex-1] < pivot
    //   theArray[pivotIndex] == pivot
    //   S2 = theArray[pivotIndex+1..last] >= pivot


    int pivot = theArray[first]; // copy pivot
    moveCount++;
    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot

        // move item from unknown to proper region
        compCount++;
        if (theArray[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;
            int tmp = theArray[firstUnknown];
            theArray[firstUnknown] = theArray[lastS1];
            theArray[lastS1] = tmp;
            moveCount = moveCount + 3;
        }	// else belongs to S2
    }
    // place pivot in proper position and mark its location
    int tmp = theArray[first];
    theArray[first] = theArray[lastS1];
    theArray[lastS1] = tmp;
    moveCount = moveCount + 3;

    pivotIndex = lastS1;
}

void radixsort( int* arr, const int n, const int d) {
    for ( int j = d; j >= 1; j--) {
        // Create 10 arrays and 10 counters since the base is 10 (numbers are in decimal format)
        int* arr0 = new int[n];
        int* arr1 = new int[n];
        int* arr2 = new int[n];
        int* arr3 = new int[n];
        int* arr4 = new int[n];
        int* arr5 = new int[n];
        int* arr6 = new int[n];
        int* arr7 = new int[n];
        int* arr8 = new int[n];
        int* arr9 = new int[n];
        int counter0 = 0;
        int counter1 = 0;
        int counter2 = 0;
        int counter3 = 0;
        int counter4 = 0;
        int counter5 = 0;
        int counter6 = 0;
        int counter7 = 0;
        int counter8 = 0;
        int counter9 = 0;
        for ( int i = 0; i < n; i++) {
            // Get the digit at the jth place
            int k = getDigit( arr[i], d - j + 1);
            // Depending on what the digit is, add it to the corresponding array and increment the counter
            switch ( k) {
                case 0: arr0[counter0] = arr[i]; counter0++; break;
                case 1: arr1[counter1] = arr[i]; counter1++; break;
                case 2: arr2[counter2] = arr[i]; counter2++; break;
                case 3: arr3[counter3] = arr[i]; counter3++; break;
                case 4: arr4[counter4] = arr[i]; counter4++; break;
                case 5: arr5[counter5] = arr[i]; counter5++; break;
                case 6: arr6[counter6] = arr[i]; counter6++; break;
                case 7: arr7[counter7] = arr[i]; counter7++; break;
                case 8: arr8[counter8] = arr[i]; counter8++; break;
                case 9: arr9[counter9] = arr[i]; counter9++; break;
                default: break;
            }
        }
        // Fill the original array with the sorted values, starting from array0
        int index = 0;
        for ( int i = 0; i < counter0; i++) {
            arr[index] = arr0[i];
            index++;
        }
        for ( int i = 0; i < counter1; i++) {
            arr[index] = arr1[i];
            index++;
        }
        for ( int i = 0; i < counter2; i++) {
            arr[index] = arr2[i];
            index++;
        }
        for ( int i = 0; i < counter3; i++) {
            arr[index] = arr3[i];
            index++;
        }
        for ( int i = 0; i < counter4; i++) {
            arr[index] = arr4[i];
            index++;
        }
        for ( int i = 0; i < counter5; i++) {
            arr[index] = arr5[i];
            index++;
        }
        for ( int i = 0; i < counter6; i++) {
            arr[index] = arr6[i];
            index++;
        }
        for ( int i = 0; i < counter7; i++) {
            arr[index] = arr7[i];
            index++;
        }
        for ( int i = 0; i < counter8; i++) {
            arr[index] = arr8[i];
            index++;
        }
        for ( int i = 0; i < counter9; i++) {
            arr[index] = arr9[i];
            index++;
        }
        // Delete the arrays to avoid memory leaks
        delete [] arr0;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        delete [] arr5;
        delete [] arr6;
        delete [] arr7;
        delete [] arr8;
        delete [] arr9;
    }
}

int getDigit( int number, int index) {
    // get the digit of number at the specified index
    number = number / pow( 10, index - 1);
    return number % 10;
}

void displayArray( const int *arr, const int size) {
    // Display the given array
    for ( int i = 0; i < size - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[ size - 1] << endl;
}

void createRandomArrays( int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    // Create random arrays with the given size
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    for ( int i = 0; i < size; i++) {
        arr1[i] = rand();
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}

void createAscendingArrays( int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    // Create strictly ascending arrays
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    arr1[0] = rand();
    arr2[0] = arr1[0];
    arr3[0] = arr1[0];
    arr4[0] = arr1[0];
    for ( int i = 1; i < size; i++) {
        arr1[i] = arr1[i-1] + ((int) abs( rand())) + 1;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}

void createDescendingArrays( int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    // Create strictly descending arrays
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    arr1[size - 1] = rand();
    arr2[size - 1] = arr1[size - 1];
    arr3[size - 1] = arr1[size - 1];
    arr4[size - 1] = arr1[size - 1];
    for ( int i = size - 2; i >= 0; i--) {
        arr1[i] = arr1[i+1] + ((int) abs( rand())) + 1;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }

}

void performanceAnalysis() {
    // Create 4 arrays to be used later
    int *arr1, *arr2, *arr3, *arr4;
    int size = 6000;
    int compCount = 0;
    int moveCount = 0;
    double duration;
    // Create random arrays to measure Selection Sort efficiency
    cout << "Analysis of Selection Sort with Random Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << setw(20) << "compCount" << setw(20) << "moveCount";

    for ( int i = 0; i < 7; i++) {
        createRandomArrays( arr1, arr2, arr3, arr4, size);
        // Start the clock
        clock_t startTime = clock();

        selectionSort( arr1, size, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << setw(20) << compCount << setw(20) << moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Selection Sort with Ascending Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << setw(20) << "compCount" << setw(20) << "moveCount";
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createAscendingArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        selectionSort( arr1, size, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << setw(20) << compCount << setw(20) << moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Selection Sort with Descending Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << setw(20) << "compCount" << setw(20) << "moveCount";
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createDescendingArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        selectionSort( arr1, size, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << setw(20) << compCount << setw(20) << moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Merge Sort with Random Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << setw(20) << "compCount" << setw(20) << "moveCount";
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createRandomArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        mergeSort( arr1, size, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << setw(20) << compCount << setw(20) << moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Merge Sort with Ascending Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << setw(20) << "compCount" << setw(20) << "moveCount";
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createAscendingArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        mergeSort( arr1, size, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << setw(20) << compCount << setw(20) << moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Merge Sort with Descending Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << setw(20) << "compCount" << setw(20) << "moveCount";
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createDescendingArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        mergeSort( arr1, size, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << setw(20) << compCount << setw(20) << moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Quick Sort with Random Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << setw(20) << "compCount" << setw(20) << "moveCount";
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createRandomArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        quickSort( arr1, size, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << setw(20) << compCount << setw(20) << moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Quick Sort with Ascending Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << setw(20) << "compCount" << setw(20) << "moveCount";
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createAscendingArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        quickSort( arr1, size, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << setw(20) << compCount << setw(20) << moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Quick Sort with Descending Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << setw(20) << "compCount" << setw(20) << "moveCount";
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createDescendingArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        quickSort( arr1, size, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << setw(20) << compCount << setw(20) << moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Radix Sort with Random Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << endl;
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createRandomArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        radixSort( arr1, size);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << endl;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Radix Sort with Ascending Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << endl;
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createAscendingArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        radixSort( arr1, size);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << endl;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
    cout << endl;

    cout << "Analysis of Radix Sort with Descending Arrays" << endl;
    cout << left << setw(20) << "Array Size" << setw(20) << "Elapsed time (ms)" << endl;
    size = 6000;

    for ( int i = 0; i < 7; i++) {
        createDescendingArrays( arr1, arr2, arr3, arr4, size);

        clock_t startTime = clock();

        radixSort( arr1, size);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << left << setw(20) << size << setw(20) << duration << endl;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        size += 4000;
        compCount = 0;
        moveCount = 0;
    }
}
