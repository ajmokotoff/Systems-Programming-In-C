#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, char* argv[]) {
  if(argc<2) { //check to see if user entered something
    printf("You must enter something on the command line!\n");
    return 1; //Indicates failure!
  }
  int num_nums; // How many numbers actually entered on the command line.
  num_nums = argc - 1;
 
  int *nums = alloc(argc, argv); //to get int array from user input

  printf("Unsorted list:\n");
  print_int_array(nums, num_nums); //print int array before sort

  sort_descending(nums, num_nums); //sort array in descending order

  printf("Sorted list:\n");
  print_int_array(nums, num_nums); //print int array after sort

  return 0; // Indicate success!
}
