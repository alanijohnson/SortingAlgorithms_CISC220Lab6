
/* 
 * File:   SortingClass.cpp
 * Author: Alani
 * 
 * This file contains the lab 6 Sorting Class
 * 
 * Created on April 27, 2017, 5:00 PM
 */

#include "SortingClass.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

/*Constructor for sorting class
 * Parameters:
 *  int si - size of array
 *  int sm - smallest number
 *  int la - largest number
 */
SortingClass::SortingClass(int si, int sm, int la) {
    //(5 pts) random numbers should be between the smallest and largest numbers,
    //in-order should start at smallest
    //reverse order should start at largest
    //all should be of size size

    //set random seed using time
    srand(time(NULL));

    //set class variables
    size = si;
    smallest = sm;
    largest = la;

    //create random array on heap
    randArr = new int[size];

    for (int i = 0; i < size; i++) {
        randArr[i] = rand() % (largest - smallest + 1) + smallest;
    }

    //create in order array on heap
    inOrderArr = new int[size];
    for (int i = 0; i < size; i++) {
        inOrderArr[i] = sm;
        sm++;
    }

    //create reverse order array on heap
    revOrderArr = new int[size];
    for (int i = 0; i < size; i++) {
        revOrderArr[i] = la;
        la--;
    }

    int* arr = copyArr("rand");
    
    arrayPrint(arr);
    //startTime = clock();
    mergeSort(arr, 0, size-1);
}

/*Constructor for sorting class - creates array of desired size with random numbers between 10 and 5000
 * Parameters:
 *  int si - size of array
 */
SortingClass::SortingClass(int si) {
    //(2 pts) largest should be 5000, smallest should be 10
    //set random seed using time
    srand(time(NULL));

    //set class variables
    size = si;
    smallest = 10;
    largest = 5000;
    int sm = 10;
    int la = 5000;


    //create random array on heap
    randArr = new int[size];

    for (int i = 0; i < size; i++) {
        randArr[i] = rand() % (largest - smallest + 1) + smallest;
    }

    

    //create in order array on heap
    inOrderArr = new int[size];
    for (int i = 0; i < size; i++) {
        inOrderArr[i] = sm;
        sm++;
    }

    

    //create reverse order array on heap
    revOrderArr = new int[size];
    for (int i = 0; i < size; i++) {
        revOrderArr[i] = la;
        la--;
    }

}

/*Constructor for sorting class - creates an array of 50000 ints of random value between 10-5000
 * Parameters:
 *  none
 */
SortingClass::SortingClass() {
    // (2 pts)Start with a smaller size to make sure your sorting algorithms are working
    // and build up to 50000
    
    //set random seed using time
    srand(time(NULL));

    //set class variables
    size = 50000;
    smallest = 10;
    largest = 5000;
    int sm = 10;
    int la = 5000;
    
    //create random array on heap
    randArr = new int[size];

    for (int i = 0; i < size; i++) {
        randArr[i] = rand() % (largest - smallest + 1) + smallest;
    }


    //create in order array on heap
    inOrderArr = new int[size];
    for (int i = 0; i < size; i++) {
        inOrderArr[i] = sm;
        sm++;
    }


    //create reverse order array on heap
    revOrderArr = new int[size];
    for (int i = 0; i < size; i++) {
        revOrderArr[i] = la;
        la--;
    }


    
}

/*CopyArr(string s) - copies existing array into a dynamicaly allocated array
 * Parameters:
 *  string s - designates which array of the class should be used
 *      which can be “rev”, “ord”, or “rand”
 * Return: address of the array
 */
int *SortingClass::copyArr(string s) {
    //(7 pts) based on s (which can be “rev”, “ord”, or “rand”, creates a new array,
    // copies over the old array, and returns the address of the new array

    //create new array on heap
    int* newArr = new int[size];

    //copy over reverse order array
    if (s == "rev") {
        return copy(revOrderArr, newArr);
    } else if (s == "ord") {
        return copy(inOrderArr, newArr);
    } else if (s == "rand") {
        return copy(randArr, newArr);
    }

}

/*selectionSort(int arr[]) - sorts the array by selection sort
 * Parameters:
 *  int arr[] - array to sort
 * Return: none
 */
void SortingClass::selectionSort(int arr[]) {
    // (4 pts) Does what you’d think to the array passed into the method.
    int min;
    int index;

    //iterate through list to build subarray
    for (int i = 0; i < size - 1; i++) {
        //initialzie min as current val
        min = arr[i];
        index = i;
        for (int j = i + 1; j < size; j++) { //find min of remaining values in array
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        //swap items
        arr[index] = arr[i];
        arr[i] = min;
    }



}

/*insertionSort(int arr[]) - sorts the array by insertion sort
 * Parameters:
 *  int arr[] - array to sort
 * Return: none
 */
void SortingClass::insertionSort(int arr[]) {
    // (4 pts) Does what you think to the array passed into the method.
    int num; //place holder for elements in array

    //iterate through array. All values before i are sorted
    for (int i = 1; i < size; i++) {
        num = arr[i];

        //iterate through sorted array starting at end of sorted portion
        //if the value to be inserted is smaller than the current value 
        //in the sorted array move it to the left and replace value
        //when value to be inserted is smaller it is placed in hole
        //if beginning of list passed, the value is added to first position
        for (int j = i - 1; j >= -1; j--) {
            if (j == -1) {
                arr[j + 1] = num;
            } else if (num < arr[j]) {
                arr[j + 1] = arr[j];
            } else {
                arr[j + 1] = num;
                break;
            }
        }
    }

}

/*quickSort(int first, int last, int arr[]) - sorts the array by quickSort
 *                                              recursive function
 * 
 * Parameters:
 *  int first - the first index of subarray
 *  int last - the last index of the subarry
 *  int arr[] - array to sort
 * Return: none
 */
void SortingClass::quickSort(int first, int last, int arr[]) {
    // (4 pts) first and last are the indices indicating
    // the current part of the array you're sorting

    int piv; //location of pivot in the array
    if (last > first) {
        piv = partition(first, last, arr); //partition array and save index of pivot
        quickSort(first, piv - 1, arr); //sort left of pivot
        quickSort(piv + 1, last, arr); //sort right of pivot
    }

}

/*partition(int first, int last, int arr[]) - choses a pivot value and puts values smaller
 *  than the pivot to the left of the pivot and larger values to the right
 * Parameters:
 *  int first - the first index of subarray
 *  int last - the last index of the subarry
 *  int arr[] - array to sort
 * Return: int - index of the pivot
 */
int SortingClass::partition(int first, int last, int arr[]) {
    //(7 pts)again, because you're only partitioning part of the array
    int pivot;
    int mid = (last - first) / 2 + first;
    int low = first;
    int high = last;
    

    //choose middle or last pivot if they are the median of the first, last, mid
    //otherwise choose first value in list as pivot
    if ((arr[first] < arr[last] && arr[last] < arr[mid]) ||
            (arr[first] > arr[last] && arr[last] > arr[mid])) {
        pivot = last;
    } else if ((arr[first] > arr[mid] && arr[mid] > arr[last]) ||
            (arr[first] < arr[mid] && arr[mid] < arr[last])) {
        pivot = mid;
    } else {
        pivot = first;
    }

    while (low < high) {
        //scan the left side until a value greater than pivot is reached
        //will scan as low is less than or equal to high
        //and if the value is the pivot will skip over it    
        while ((arr[low] <= arr[pivot] || &arr[low] == &arr[pivot]) && (low <= high)) {
            low++;
        }
        
        //scan the right side until a value less than the pivot is reached
        //will scan as low is less than or equal to low      
        //and if the value is the pivot will skip over it
        
        while ((arr[high] > arr[pivot] || &arr[high] == &arr[pivot]) && (low <= high)) {
            high--;
            
        }
        
        //swap values
        if (low <= high) {
            swap(arr, high, low);
            
        }
       
    }
    
    //put pivot in position
    int val = ((pivot <= low) ? high : low); //put pivot in right location dependant on whether pivot is to the left or right of high low positions
    swap(arr, pivot, val);
    
    //arrayPrint(arr);
    return val;

}


/*merge(int arr[], int f, int m, int l) - helper function to mergeSort to merge
 *  elements in the array together after being sorted
 *                                              
 * 
 * Parameters:
 *  int f - the first index of subarray
 *  int l - the last index of the subarry
 *  int m - the middle index of the subarry
 *  int arr[] - array to sort
 * Return: none
 */
void SortingClass::merge(int arr[], int f, int m, int l) {
    // (7 pts)f is first index, m is middle index (end of first sorted array portion)
    // and l is the last index of the second array portion
    int tmp[l - f+1];
    int i = f; //iterator for first array
    int j = m + 1; //iterator for second array
    int k = 0; //iterator for position in new array, tmp

//    for (int p=0; p<=l-f;p++){
//        if (p==m+1){
//            cout << "/";
//        }
//        cout << arr[p+f] <<", ";
//    }
//    cout <<endl;
    
    
    //while elements still need to be added from both array to tmp array
    //add the smaller element to the array and move to the next positoon
    while (i <= m && j <= l) {
        if (arr[i] < arr[j]) {
            //cout << arr[i] <<endl;
            tmp[k++] = arr[i++];
        } else {
            //cout << arr[j] <<endl;
            tmp[k++] = arr[j++];
        }
    }
    //arrayPrint(tmp);

    
    //add remaining elements

    //elements exist in the first half
    while (i <= m) {
        //cout << arr[i] <<endl;
        tmp[k++] = arr[i++];
    }

    //elements exist in the second half
    while (j <= l) {
        //cout << arr[j] <<endl;
        tmp[k++] = arr[j++];
    }
    

    //arrayPrint(tmp);
    //copy over ordered elements in order to the original array
    for (int k = 0; k <= l - f; k++) {
        arr[f + k] = tmp[k];
    }
    //arrayPrint(arr);


}

/*mergeSort(int arr[], int low, int hi) - sorts array by mergeSort method
 *                                             
 * 
 * Parameters:
 *  int low - the first index of subarray
 *  int hi - the last index of the subarry
 *  int arr[] - array to sort
 * Return: none
 */
void SortingClass::mergeSort(int arr[], int low, int hi) {
    // (4 pts)keeps dividing the portion of the array between the low index and the hi
    // index by dividing by 2

    //split for subarray
    int mid = ((hi - low) / 2) + low;

    //if the subarray is one element, splitting and merge can occur
    //left half is split, then merged
    //right half is split, then merged
    if (hi - low <= 0) {
        return;
    } else {
        mergeSort(arr, low, mid); //split then merge left
        mergeSort(arr, mid + 1, hi); //split then merge right
        merge(arr, low, mid, hi);
    }



}

/*compareSorts() - compare all of the sorts that were a part of this lab          
 *              ****bubbleSort added
 *              Professor Yarrington said we didn't have to print once we moved to size = 50000
 * Parameters: none
 * Return: none
 */
void SortingClass::compareSorts() {
    clock_t startTime = clock();
    double timePassed;
    //SELECTION SORT
    int *arr = copyArr("rand");
    startTime = clock();
    selectionSort(arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Selection: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    selectionSort(arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Selection: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    selectionSort(arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Selection: ord " << timePassed << endl;
    //INSERTION
    arr = copyArr("rand");
    startTime = clock();
    insertionSort(arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Insertion: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    insertionSort(arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Insertion: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    insertionSort(arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Insertion: ord " << timePassed << endl;
    //QUICKSORT
    arr = copyArr("rand");
    startTime = clock();
    quickSort(0, size-1, arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Quick: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    quickSort(0, size-1, arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Quick: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    quickSort(0, size-1, arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Quick: ord " << timePassed << endl;
    //MERGE
    arr = copyArr("rand");
    startTime = clock();
    mergeSort(arr, 0, size - 1);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Merge: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    mergeSort(arr, 0, size - 1);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Merge: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    mergeSort(arr, 0, size - 1);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Merge: ord " << timePassed << endl;
    
    //Bubble
    arr = copyArr("rand");
    startTime = clock();
    bubbleSort(arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Bubble: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    bubbleSort(arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Bubble: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    bubbleSort(arr);
    timePassed = clock() - startTime;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << endl;
    delete [] arr;
    cout << "Bubble: ord " << timePassed << endl;
}

//helper function used to print the arrays to ensure they are properly doing what they should be doing

/*arrayPrint(int arr[]) - prints array to console
 *                                              
 * 
 * Parameters:
 *  int arr[] - array to print
 * Return: none
 */
void SortingClass::arrayPrint(int array[]) {
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            cout << array[i] << endl;
        } else {
            cout << array[i] << ",";
        }
    }
}

//helper function used to copy the array

/*copy(int arr[], int newArr[]) - copies over a preexisting array to the specified address
 *                                              
 * 
 * Parameters:
 *  int arr[] - array to print
 *  int newArr[] - location array should be copied to
 * Return: int* - address of new array
 */
int *SortingClass::copy(int arr[], int newArr[]) {
    //(7 pts) based on s (which can be “rev”, “ord”, or “rand”, creates a new array,
    // copies over the old array, and returns the address of the new array
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    return newArr;
}

/*swap(int arr[], int ind1, int ind2) - switches values at two index in array
 *                                              
 * 
 * Parameters:
 *  int arr[] - array to containing values to be switched
 *  int ind1 - index of one of the values to be switched
 *  int ind2 - index of one of the values to be switched
 * Return: none
 */
void SortingClass::swap(int arr[], int ind1, int ind2) {
    int tmp;
    tmp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = tmp;
}


//Extra Credit:

/*bubbleSort(int arr[]) - switches values at two index in array
 *                                              
 * 
 * Parameters:
 *  int arr[] - array to containing values to be switched
 *  int ind1 - index of one of the values to be switched
 *  int ind2 - index of one of the values to be switched
 * Return: none
 */
void SortingClass::bubbleSort(int arr[]) {
    bool swapped = true; //boolean to determine if a swap happened
    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
                swapped = true;
            }
        }
    }
   
}