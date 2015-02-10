#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Takes the array and size and iterates through so it can print each element
 * @param nums, array of integers to print
 * @param count, number of elements in array of integers
 */

void print_int_array(int nums[], int count) {
  int i;
  int* point;
  point=nums;
  for(i=0; i<count; i++) {
    printf("%d\n", *(point++));
  }
}

/* Takes the array and uses the bubble sort to make the array sorted in descending order
 * @param nums, array of integers to sort
 * @param count, number of elements in array of integers
 */

void sort_descending(int nums[], int count) {
  int i;
  int j;
  int temp;
  int* point1; // Points to first number to compare
  int* point2; // Always points to the number after point1

  for(i=0;i<=count;i++) {
    point1=nums; // Reset to start of array
    point2=&nums[1];

    for(j=0; j<count; j++) {
      if(*(point1) <  *(point2)) {
	temp = *point1;
	*point1=*point2;
	*point2=temp;
      }
      point1++;
      point2++;
    }
  }
}

/* Takes the keyboard input, allocates space for an entire array of integers and converts the input array  into an integer array using pointers
 * @param argc, number of inputs
 * @param argv, array of inputs to be converted to ints
 * @return pointer to first element of the new integer array
*/


int *alloc(int argc, char* argv[]) {
  int *newa; // Pointer to start of newly-allocated array.
  int* point; // Pointer which moves through the array
  int i;

  newa = calloc(argc,sizeof(int)); //allocate space for the new integer array
  point = newa; //leaves a pointer at the beginning so the beginning can be refrenced

  for(i=0; i<argc-1; i++) { //iterate through the input array to make pointers
    *point=atoi(argv[i+1]);
    ++point;
  }
  return newa; //return the pointer at the beginning of the array
}
