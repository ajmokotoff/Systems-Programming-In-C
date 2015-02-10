#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <errno.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
  char* line=malloc(sizeof(char)*1024); //Allocate memory for line to be read
  FILE *fp = fopen("etest2.txt","r");  //Open file
  int switcher=1; //Traverser
  char* temp;

  if(fp==NULL) { //Check for file error
    return 1;
  }

  int numEmployee = employeeCounter(line,1024,fp); //Count number of employees in file


  Employee2 arr[employeeCounter(line,1024,fp)]; //Initalize array based on count above
  Employee2* arrPtr=arr;

  rewind(fp); //Reset file read, so it starts from the beginning

  while(fgets(line,1024,fp)) { //While theres another line
    printf("%s",line);
    if(switcher) {
      temp=line;
      switcher=0;
    }
    else {
      switcher=1;
      arrPtr=createEmployee2(atoi(line),temp); //Create employee2 from file read
      arrPtr++;
    }
  }
}
