/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SortingClass.hpp
 * Author: Alani
 *
 * Created on April 27, 2017, 5:00 PM
 */

#ifndef SORTINGCLASS_HPP_
#define SORTINGCLASS_HPP_
#include <string>
#include <math.h>
using namespace std;

class SortingClass {
    int *randArr;
    int *inOrderArr;
    int *revOrderArr;
    int size;
    int smallest;
    int largest;
public:
    SortingClass(int si, int sm, int la);
    SortingClass(int si);
    SortingClass();
    // takes the word "random", "inorder", or "reverse
    //order" as input,
    // and returns the address of a newly made copy of that array
    // because we don't want to mess with the original arrays for the other
    //sorts
    int *copyArr(string s); 
    //Helper function used to copy over any of the pre-existing arrays to a new array
    int* copy(int arr[],int newArr[]);
    void selectionSort(int arr[]); // must take array as input because you want
    //to pass in a
    // copy of either the in-order, reverse-order, or random array and sort it
    void insertionSort(int arr[]);
    void quickSort(int first, int last, int arr[]); // first and last are the
    //indices indicating
    // the current part of the array you're sorting
    int partition(int first, int last, int arr[]); //again, because you're only
    //partitioning
    //    part of the array
    void merge(int arr[], int f, int m, int l); // in this case, you're creating
    //a newly
    //merges list from 2 portions of the array that are already sorted, and then
    //copying the
    //sorted portion back into the list. Thus you'll need to know the index of
    //the beginning of
    //the first sorted list, the index of the beginning of the second sorted list
    //(m), and the
    //index of the last value in the second sorted list
    void mergeSort(int arr[], int low, int hi); // this is the part that divides
    //the array into
    //smaller and smaller subarrays. The stopping condition is when the low is >=
    //to the hi index
    //in the array
    void compareSorts(); // the function that should be called from main after
    //you've
    // created a SortingClass object. This function compares the timing of the
    //different sorting methods when the arrays are in order, in reverse order,
    //and random.
    void arrayPrint(int array[]);
    void swap(int arr[], int ind1, int ind2); //helper function to swap values at indices
    void bubbleSort(int array[]);
};
#endif /* SORTINGCLASS_HPP_ */

