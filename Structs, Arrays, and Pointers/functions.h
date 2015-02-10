#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_NAME (40)

struct _Employee {
  int salary; // Monthly salary in US dollars
  char name[MAX_NAME + 1]; // Character string holding name of employee.
              // MUST be dynamically allocated from the heap.
};

struct _Employee2 {
  int salary; // Monthly salary in US dollars
  char *name; // Pointer to character string holding name of employee.
              // MUST be dynamically allocated from the heap.
};

typedef struct _Employee Employee; // For convenience
typedef struct _Employee2 Employee2; // For convenience


// function prototypes
void printEmployeeVerbose(Employee *employee);
void outputEmployeeVerbose(FILE *stream, Employee *employee);
Employee* fillinEmployee(Employee* emp, int salary, char* name);
Employee* createEmployee(int salary, char* name);
void outputEmployee2Verbose(FILE *stream,Employee2* employee);
void printEmployee2Verbose(Employee2* employee);
Employee2* createEmployee2(int salary, char* name);
Employee2* inputCreateEmployee2();
int numOfEmployees();
void writeEmployee2File(FILE *stream,Employee2* employee);
Employee* fillinEmployee(Employee* emp, int salary, char* name);
Employee2** writeToEmployee2File(int num);
Employee* inputCreateEmployee();
void freeEmployee2Array(Employee2** empArr,int num);
int employeeCounter(char* line,int size,FILE* fp);

#endif
