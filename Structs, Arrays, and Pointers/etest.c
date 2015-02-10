#include <stdio.h>
#include <string.h>
#include "etest.h"
#include <errno.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#define OUTFILENAME "etest.txt"

int main() {
  printf("Starting program etest.\n"); 

  // Anybody recognize these names?
  Employee harry; // Declare a local variable (a struct).
  harry.salary = 50000;
  strcpy(harry.name, "Harry Palmer"); // Copy into array in struct

  Employee bluejay; // Declare a local variable (a struct).
  bluejay.salary = 60000;
  strcpy(bluejay.name, "Erik Grantby"); // Copy into array in struct

  Employee andrew;
  fillinEmployee(&andrew,100000,"Andrew Mokotoff");

  Employee* employeePtr = createEmployee(30000,"John McCarty");

  Employee2* sam = createEmployee2(13100,"Samuel Wilson");
  Employee2* naaman = createEmployee2(169100,"Naaman Fletcher");

  Employee2* daniel = inputCreateEmployee2();


  // Output the employees to a file.
  printf("About to write to file %s.\n", OUTFILENAME);
  FILE *outfile = fopen(OUTFILENAME, "w"); // Open or create file for writing
  if(!outfile) { //check for errors
    fprintf(stderr, "Uh-oh! In the program etest, there was a problem writing to the file: %s. Error %d: %s!\n",OUTFILENAME,errno,strerror(errno));
    return 1;
  }
  outputEmployeeVerbose(outfile, &harry);
  outputEmployeeVerbose(outfile, &bluejay);
  outputEmployeeVerbose(outfile, &andrew);
  outputEmployeeVerbose(outfile, employeePtr);
  outputEmployee2Verbose(outfile, sam);
  outputEmployee2Verbose(outfile, naaman);
  outputEmployee2Verbose(outfile, daniel);
  fclose(outfile); // Close the file

  // Output the employees to stdout.
  printEmployeeVerbose(&harry);
  printEmployeeVerbose(&bluejay);
  printEmployeeVerbose(&andrew);
  printEmployeeVerbose(employeePtr);
  printEmployee2Verbose(sam);
  printEmployee2Verbose(naaman);
  printEmployee2Verbose(daniel);

  printf("Ending program etest.\n");
  return 0;
}
