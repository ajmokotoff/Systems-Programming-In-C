#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "functions.h"
#include <readline/readline.h>
#include <readline/history.h>

#define OUTFILENAME "etest2.txt"

/** Prints one Employee structure in verbose form
 * @param employee Pointer to the structure to print
*/

void printEmployeeVerbose(Employee *employee) {
 // Save effort -- make use of other function already written!
  outputEmployeeVerbose(stdout, employee);
}


/** Outputs one Employee structure in verbose form, to an open file stream
 * @param stream The output stream to write to (must already be open).
 * @param employee Pointer to the structure to print
*/

void outputEmployeeVerbose(FILE *stream, Employee *employee) {
  fprintf(stream, "Employee:. Name = %s, Salary = %d\n",
	  employee->name, employee->salary);
}

/** Creates and fills an Employee2 from user inputs and returns the new filled Employee2
 * @return employee Employee2 holding salary and name from user inputs
 */
Employee2* inputCreateEmployee2() {
  int salary;
  char* name;
  char* input;
  int boolFlag=0;
  int nc;

  name=readline("Enter a name for the employee: ");
  printf("You just entered: %s\nThe employee name is now: %s\n",name,name);

  while(!boolFlag) { //To switch between salary and name
    input = readline("Enter a salary: ");
    printf("You just entered: %s\n",input);
    nc = sscanf(input,"%d",&salary);
    if(nc>0) {
      boolFlag=1;
      printf("The salary is now: %d\n",salary);
    } else {
      printf("Please enter a valid salary.\n");
    }
  }
  return createEmployee2(salary,name); 
}

/** Allocates an Employee struct and fills in its fields. 
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets copied into struct.
 * @return Pointer to the newly-allocated struct.
 */
Employee* createEmployee(int salary,char* name) {
  Employee* emp;
  emp=(Employee*)malloc(sizeof(Employee));
  fillinEmployee(emp,salary,name);
  return emp;
}

/** Creates and fills an Employee from user inputs and returns the new filled Employee
 * @return employee Employee holding salary and name from user inputs
 */
Employee* inputCreateEmployee() {
  int salary;
  char* name;
  //name = malloc(sizeof(char)*15);
  char* input;
  int boolFlag=0;
  int nc;
  Employee temp;

  name=readline("Enter a name for the employee: ");
  printf("You just entered: %s\nThe employee name is now: %s\n",name,name);
  
  while(!boolFlag) { //To switch between salary and name
    input=readline("Enter a salary: ");
    printf("You just entered: %s\n",input);
    nc=sscanf(input,"%d",&salary);
    if((nc>0)&&(salary<=200000000)) {
      boolFlag=1;
      printf("The salary is now: %d\n",salary);
    } else {
      printf("Please enter a valid salary.\n");
    }
  }
  return createEmployee(salary,name);
}
/** Dynamically allocates an Employee2 struct and fills in its fields
 *@param salary Annual salary in dollars
 *@param name Pointer to the String that contains the employee's name
 *@return Pointer to the newly-allocated struct
 */
Employee2* createEmployee2(int salary, char* name) {
  Employee2* emp;
  emp=(Employee2*)malloc(sizeof(Employee2));
  emp->salary=salary;
  emp->name=strdup(name);
  return emp;
}

/** Prints one Employee2 structure in verbose form
 * @param employee Pointer to the structure to print
*/
void printEmployee2Verbose(Employee2* employee) {
  outputEmployee2Verbose(stdout, employee);
}

/** Outputs one Employee2 structure in verbose form, to an open file stream
 * @param stream The output stream to write to (must already be open).
 * @param employee Pointer to the structure to print
*/
void outputEmployee2Verbose(FILE *stream,Employee2* employee) {
  fprintf(stream, "Employee2:. Name = %s, Salary = %d\n",employee->name, employee->salary);
}

/** Asks the user how many employees they wish to be made
 * @return num number of employees they wish to use in another function
 */
int numOfEmployees() {
  int num;
  char* input;
  int boolFlag=0;
  int nc;

  while(!boolFlag) { //To switch between salary and name
    input=readline("Enter a number of employees: ");
    printf("You just entered: %s\n",input);
    nc = sscanf(input,"%d",&num);
    if(num>15) { //If over 15, error, and try again
      fprintf(stderr,"Error: You have entered too many employees!\n");
    }
    if((nc>0)&&(num<=15)) { //Error check
      boolFlag=1;
      printf("The number of employees is: %s\n",input);
    } else {
      printf("Please enter a valid number of employees.\n");
    }
  }
  return num;
}

/** Writes the data held by employee into a file with name and salary on their own lines
 * @param stream The file to be written to
 * @param employee The struct that contains the data to be written to the file
 */
void writeEmployee2File(FILE *stream,Employee2* employee) {
  fprintf(stream,"%s\n%d\n",employee->name,employee->salary);
}
/** Fills in the fields of an Employee structure
 * @param emp Pointer to the struct. MUST ALREADY EXIST!
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets copied into struct.
 * @return Pointer to the same struct
 */
Employee* fillinEmployee(Employee* emp, int salary, char* name) {
  emp->salary = salary;
  strncpy(emp->name,name,sizeof(char)*strlen(name));
}

/** After the user inputs the data for a new Employee this function writes it to the text file and prints it into the terminal window for the user
 * @param num Number of employees to print and write
 * @return Employee2 Array of pointers that point to Employee2s filled in by the user input.
 */
Employee2** writeToEmployee2File(int num) {
  int i;
  Employee2** empArr=(Employee2**)malloc(num*sizeof(Employee2*));

// Output the employees to a file.
  printf("About to write to file %s.\n", OUTFILENAME);
  FILE *outfile = fopen(OUTFILENAME, "w"); // Open or create file for writing
  if(!outfile) { //Error check
    fprintf(stderr, "Uh-oh! In the program etest, there was a problem writing to the file: %s. Error %d: %s!\n",OUTFILENAME,errno,strerror(errno));
    return NULL;
  }
  
  for(i=0;i<num;i++) { //Writing to file
    Employee2* ptr = inputCreateEmployee2();
    empArr[i] = ptr;
    writeEmployee2File(outfile,ptr);
  }
  for(i=0;i<num;i++) { //Printing
    Employee2* ptr=empArr[i];
    printEmployee2Verbose(ptr);
  }
  return empArr; 
}

/** Function that unallocates the space held by an array of pointers that point to employees
 * @param empArr array to be unallocated
 * @param num number of employees in the array
 */
void freeEmployee2Array(Employee2** empArr,int num) {
  int i;
  for(i=0;i<num;i++) {
    Employee2* ptr = empArr[i];
    free(ptr->name); //Free string pointed to in Employee2
    free(ptr); //Free the node
  }
  free(empArr); //Free the entire array
  printf("The Array has been cleared from memory!\n");
}

/** Counts how many employees there are in the file
 * @param line All of the characters in the file on a specific line
 * @param size Number of bytes to read
 * @param fp The file to be read
 * @return count Number of employees that are in the file
 */
int employeeCounter(char* line,int size,FILE* fp) {
  int count=1;
  while(fgets(line,size,fp)) {
    count++;
  }
  return count/2;
}

