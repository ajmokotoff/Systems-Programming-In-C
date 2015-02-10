# Structs, Arrays, and Pointers

In this project, I implemented Structs, Arrays, and pointers. I thoroughly tested them to make sure they worked.

Files:
etest.c: Contains function implementations and a runnable main that creates and fills Employee and Employee2 structs. The program prints the structs in the terminal window, and also writes them to the etest.txt file.
etest.h: Header file that contains the function prototypes of the functions in etest.c.
functions.c: Contains function implementations of nearly every single function in the project. It basically serves as a function database so that functions can be re-used and do not need to be redefined in other programs.
functions.h: Header file that contains the function prototypes of the functions in functions.c.
part3.c: A main program that asks the user to input a number of employees and then creates an array of employees of that size. The program then asks the user to input the name and salary of the employee, it fills the employee with the data, and puts it into the array. It also writes the name and salary on their own respective lines in etest2.txt. The function then frees the memory that the array of employees held.
part5.c: This main program fills an employee array from reading the etest2.txt (filled by part3.c) file. It reads each line and fills in the employee and adds it to the array. It also prints it out in the terminal window so you can see all the data.
part6.c: Similar to part3.c, this main program asks the user to input a number of employees and then creates an array of employees of that size. The program then asks the user to input the name and salary of the employee, it fills the employee with the data, and puts it into the array. It also writes the name and salary on their own respective lines in a binary file: etest3.bin. Since you can only write to the binary file with a specific amount of bytess, we make the number of bytes constant, and either cut off the end of the string, or fill in the rest with empty space. 
part7.c: Similar to part5.c, this main program fills an employee array from reading the etest3.bin (filled by part6.c) file. It reads each line and fills in the employee and adds it to the array. It also prints it out in the terminal window so you can see all the data.
makefile: Contains instructions for the make command. Make is a unix tool that simplifies building program executables from many modules. It is convienent because it can make the executables and delete them for when you need to edit your code. It is also used to create the webpages using doxygen.
etest.txt: Text file written to by etest.c.
etest2.txt: Text file written to by part3.c and read by part5.c.
etest3.bin: Binary file written to by part6.c and read by part7.c.
Doxyfile: Describes the settings to be used by the documentation system.

Instructions:
due to my makefile, simply type "make" into terminal. Your code is now compiled. Then to run part1 and part2, type "./etest". To run part3 and part4, type "./part3". To run part5, type "./part5". To run part6, type "./part6". To run part7, type "./part7". Once finished, it is good practice to type "make clean" because if we change the contents of the program and the executables, it will not run correctly. 