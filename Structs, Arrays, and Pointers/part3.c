#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <errno.h>

int main() {
  int num = numOfEmployees(); //Find number of employees
  Employee2** empArr=writeToEmployee2File(num); //Allocate array
  if(empArr==NULL) { //Will return null if there is an error
    return 1; //error
  }
  freeEmployee2Array(empArr,num); //Unallocate array in memory
  return 0; //Success
}
