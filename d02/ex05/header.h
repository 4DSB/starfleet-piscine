#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int	searchShifted(int *rocks, int length, int value);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
int *createRandomArray(int n);
void printArray(int *arr, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/
int binarySearch(int arr[], int low, int high, int key);
int findPivot(int arr[], int low, int high);
int pivotedBinarySearch(int arr[], int n, int key);

#endif

