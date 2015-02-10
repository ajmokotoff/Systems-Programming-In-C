# Array Allocation and Sorting

In this project, I create arrays using pointers, allocate them, and sort them. I test them to prove that it works.

Files: 
Doxyfile: Describes the settings to be used by the documentation system
assig3.c: Code of the program; contains all logic and output
sort.h: Program that contains all the function headers that assig3.c calls to.
sort.c: Program that contains all the logic and output of the functions assig3.c calls to.
makefile: File that contains instructions for the make command. Make is a unix tool that simplifies building program executables from many modules. It is convienent because it can make the executables and delete them for when you need to edit your code. It is also used to create the webpages using doxygen.

Instructions
Due to my makefile, simply type "make" into terminal. Your code is now compiled. Then to run the file, type "./assig3 [numbers with spaces inbetween]" without including the brackets. Once finished, it is good practice to type "make clean" because if we change the contents of the program and the executables, it will not run correctly.

Test Results:
Input: ./assig3 3 2 1, Expect: 3 2 1, Result: 3 2 1
Input: ./assig3, Expect: You must enter something on the command line!, Result: You must enter something on the command line!
Input: ./assig3 10 9 8 7 6 5 4 3 2 1, Expect: 10 9 8 7 6 5 4 3 2 1, Result: 10 9 8 7 6 5 4 3 2 1
Input: ./assig3 11 10 9 8 7 6 5 4 3 2 1, Expect: 11 10 9 8 7 6 5 4 3 2 1, Result: 11 10 9 8 7 6 5 4 3 2 1
Input: ./assig3 12 11 10 9 8 7 6 5 4 3 2 1, Expect: 12 11 10 9 8 7 6 5 4 3 2 1, Result: 12 11 10 9 8 7 6 5 4 3 2 1
Input: ./assig3 1 3 2, Expect 3 2 1, Result: 3 2 1
Input: ./assig3 8 9 3 7 433 8 3 9 3 8 3 1 2, Expect: 433 9 9 8 8 8 7 3 3 3 3 2 1, Result: 433 9 9 8 8 8 7 3 3 3 3 2 1
Input: ./assig3 9 8 7 6 5 4 3 2 1, Expect: 9 8 7 6 5 4 3 2 1, Result: 9 8 7 6 5 4 3 2 1
Input: ./assig3 786 2 9999 3 5, Expect: 9999 786 5 3 2, Result: 9999 786 5 3 2 