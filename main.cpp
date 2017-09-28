
/* 
 * File:   main.cpp
 * Author: Alani Johnson
 * 
 * Lab 6
 *
 * Created on April 27, 2017, 5:00 PM
 * File Contents: 
 */

#include <cstdlib>
#include "SortingClass.hpp"

using namespace std;

/*
 * (4 pts) You must also write the main function, which creates an object of type
  SortingClass, and then calls the compareSorts method.
1
 * (4 pts) Add bubbleSort to the header file, the source code, and the compareSorts
method. Comment it thoroughly so that you’re explaining what is going on
(7 pts) Add heapsort to the header file, the source code, and the compareSorts
method. Comment it thoroughly
(10 pts) Add a radixSort to the header file, the source code, and the compareSorts
method. Comment it thoroughly.
 */
int main(int argc, char** argv) {
//    SortingClass* arr = new SortingClass(15,1,40);
//    arr->compareSorts();
    
    SortingClass* sort = new SortingClass();
    sort->compareSorts();
   
    return 0;
}

