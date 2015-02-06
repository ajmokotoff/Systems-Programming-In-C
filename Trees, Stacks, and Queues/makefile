# By default, make all the executables:
all: stacktest queuetest tnodetest randtnodetest

# Make each executable:
stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

# Compile each source file:
stack.o: stack.c stack.h
	gcc -g -c stack.c

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

queuetest: queuetest.o queue.o
	gcc -g queuetest.o queue.o -o queuetest

queue.o: queue.c queue.h
	gcc -g -c queue.c

queuetest.o: queuetest.c queue.h
	gcc -g -c queuetest.c

tnodetest: tnodetest.o tnode.o
	gcc -g tnodetest.o tnode.o -o tnodetest

tnode.o: tnode.c tnode.h
	gcc -g -c tnode.c

tnodetest.o: tnode.c tnode.h
	gcc -g -c tnodetest.c

randtnodetest: randtnodetest.o tnode.o
	gcc -g randtnodetest.o tnode.o -o randtnodetest

randtnodetest.o: tnode.c tnode.h
	gcc -g -c randtnodetest.c

# Other targets:
clean:
	rm -f *.o
	rm -f stacktest queuetest tnodetest randtnodetest

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2301/assig6

