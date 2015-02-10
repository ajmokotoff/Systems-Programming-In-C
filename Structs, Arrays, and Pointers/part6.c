#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <errno.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#define OUTFILENAME "etest3.bin"

int main() {
  int numOfEmployee=numOfEmployees(); //Number of employees to work with
  int i=0;

  int fd = open(OUTFILENAME, O_WRONLY | O_CREAT | O_TRUNC,S_IRUSR | S_IWUSR );
  if (fd >= 0) { //check for file errors
    printf("File opened successfully\n");
  } else { //error condition
    printf("Unable to open file. Error %d: %s\n", errno, strerror(errno));
    return 1; //Error
  }

  Employee** empArr=(Employee**)malloc(numOfEmployee*sizeof(Employee*)); //Allocate array for new array
  printf("About to write to file %s.\n",OUTFILENAME);

  Employee* temp;

  for(i=0;i<numOfEmployee;i++) {
    temp=inputCreateEmployee(); //Create employee based on user input
    write(fd, temp, sizeof(Employee)); // Write struct to binary file 
  }
  close(fd); //close the file
  return 0; //success
}
