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
  int num;
  int fd = open(OUTFILENAME, O_RDONLY); //open for file
  if (fd >= 0) { //check for file errors
    printf("File opened successfully\n");
  } else { //error condition
    printf("Unable to open file. Error %d: %s\n", errno, strerror(errno));
    return 1; //error
  }
  Employee* arrPtr=malloc(sizeof(Employee)*15);
  num=read(fd,(char*)arrPtr,sizeof(Employee));
  while(num) { //reads until there isn't another line
    printf("Name: %s, Salary: %d\n",arrPtr->name,arrPtr->salary);
    num=read(fd,(char*)++arrPtr,sizeof(Employee));
  }
  return 0; //success
}
