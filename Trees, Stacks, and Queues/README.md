# Trees, Stacks, and Queues

In this project, I implemented Trees, Stacks, and Queues using pointers. I thoroughly tested them to make sure they worked.

Files:
stack.c: Contains the function implementations that we defined part of stack. The function prototypes are referenced in stack.h. Specifically it defines: the stack struct, create_stack, delete_stack, push, pop, and peek.
stack.h: Contains the function prototypes for stack.c.
stacktest.c: Contains a runnable main and brief testing and using our new impelemented stack.
queue.c: Contains the function implementations that we defined part of queue. The function prototypes are referenced in queue.h. Specifically, it defines: the Queue struct, create_queue, enqueue, and dequeue.
queue.h: Contains the function prototypes for queue.c.
queuetest.c: Contains a runnable main and brief testing and using our new imelemented queue.
tnode.c: Contains the function implementations that we defined part of our treenode. Specifically, it defines: the Tnode struct, add_tnode, treePrint, randWord, randtree, and freetree.
tnode.h: Contains the function prototypes for the functions in tnode.c.
tnodetest.c: Contains a runnable main and testing for the add_tnode and treePrint.
randtnodetest.c: Contains a runnable main and testing for the randtree, freetree, and randWord.
makefile: Contains instructions for the make command. Make is a unix tool that simplifies building program executables from many modules. It is convienent because it can make the executables and delete them for when you need to edit your code. It is also used to create the webpages using doxygen.
Doxyfile: Describes the settings to be used by the documentation system.

Instructions:
Type "make" to compile the code in terminal using a gcc compiler. To test a stack, type "./stacktest". Then to test a queue, type "./queuetest". To test a tree, type "./tnodetest". To further test the tree, type "./randtnodetest". Once finished, it is good practice to type "make clean" because if we change the contents of the program and the executables, it will not run correctly. In order to generate the doxygen file, simply type "make docs" and the doxygen file will be posted at this url: http://www.wpi.edu/~your_user_name/cs2301/assig6/.