#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct Foo {
  int x;
  double y;
};

typedef struct Foo Foo;

/** Creates a variety of structs that contain doubles and integers, and it tests each function in queue.c thoroughly.
 *
 */
int main() {

  const int size = 4;
  Foo* Foo1;
  Foo* Foo2;
  Foo* Foo3;
  Foo* Foo4;
  Foo* Foo5;
  Foo* anotherFoo;

  //create a queue
  Queue *new_queue = create_queue(size);

  //Allocate a Foo and put into in the queue
  Foo1 = (Foo*) malloc(sizeof(Foo));
  Foo1->x = 3;
  Foo1->y = 5;

  printf("Enqueueing: x = %5d, y = %10.3f \n", Foo1->x, Foo1->y);
  enqueue(new_queue, (void*) Foo1, size);

  //Allocate another foo and put it into the existing queue
  Foo2 = (Foo*) malloc(sizeof(Foo));
  Foo2->x = 43;
  Foo2->y = 92;

  printf("Enqueueing: x = %5d, y = %10.3f \n", Foo2->x, Foo2->y);
  enqueue(new_queue, (void*) Foo2, size);
  
  //Allocate another foo and put it into the existing queue
  Foo3 = (Foo*) malloc(sizeof(Foo));
  Foo3->x = 52;
  Foo3->y = 23.73;

  printf("Enqueueing: x = %5d, y = %10.3f \n", Foo3->x, Foo3->y);
  enqueue(new_queue, (void*) Foo3, size);

  //Allocate another foo and put it into the existing queue
  Foo4 = (Foo*) malloc(sizeof(Foo));
  Foo4->x = 326;
  Foo4->y = 4.84;

  printf("Enqueueing: x = %5d, y = %10.3f \n", Foo4->x, Foo4->y);
  enqueue(new_queue, (void*) Foo4, size);

  //Test Enqueue when queue is full
  Foo5 = (Foo*) malloc(sizeof(Foo));
  Foo5->x = 26;
  Foo5->y = 458;;

  printf("Enqueueing: x = %5d, y = %10.3f \n", Foo5->x, Foo5->y);
  enqueue(new_queue, (void*) Foo5, size);

  //Tests dequeueing an empty queue
  //Dequeueing the queue
  anotherFoo = (Foo*) dequeue(new_queue, size);
  if (anotherFoo == NULL) {
    printf("Dequeued: x = %s, y = %s \n", anotherFoo, anotherFoo);
  }
  else {
    printf("Dequeued: x = %5d, y = %10.3f \n", anotherFoo->x, anotherFoo->y);
  }

//Dequeueing the queue
  anotherFoo = (Foo*) dequeue(new_queue, size);
  if (anotherFoo == NULL) {
    printf("Dequeued: x = %s, y = %s \n", anotherFoo, anotherFoo);
  }
  else {
    printf("Dequeued: x = %5d, y = %10.3f \n", anotherFoo->x, anotherFoo->y);
  }

//Dequeueing the queue
  anotherFoo = (Foo*) dequeue(new_queue, size);
  if (anotherFoo == NULL) {
    printf("Dequeued: x = %s, y = %s \n", anotherFoo, anotherFoo);
  }
  else {
    printf("Dequeued: x = %5d, y = %10.3f \n", anotherFoo->x, anotherFoo->y);
  }

//Dequeueing the queue
  anotherFoo = (Foo*) dequeue(new_queue, size);
  if (anotherFoo == NULL) {
    printf("Dequeued: x = %s, y = %s \n", anotherFoo, anotherFoo);
  }
  else {
    printf("Dequeued: x = %5d, y = %10.3f \n", anotherFoo->x, anotherFoo->y);
  }

//Dequeueing the queue
  anotherFoo = (Foo*) dequeue(new_queue, size);
  if (anotherFoo == NULL) {
    printf("Dequeued: x = %s, y = %s \n", anotherFoo, anotherFoo);
  }
  else {
    printf("Dequeued: x = %5d, y = %10.3f \n", anotherFoo->x, anotherFoo->y);
  }

  //Test wrapping the tail
  printf("Enqueueing: x = %5d, y = %10.3f \n", Foo3->x, Foo3->y);
  enqueue(new_queue, (void*) Foo3, size);

  printf("Enqueueing: x = %5d, y = %10.3f \n", Foo2->x, Foo2->y);
  enqueue(new_queue, (void*) Foo2, size);

  printf("Enqueueing: x = %5d, y = %10.3f \n", Foo1->x, Foo1->y);
  enqueue(new_queue, (void*) Foo1, size);

  printf("Enqueueing: x = %5d, y = %10.3f \n", Foo5->x, Foo5->y);
  enqueue(new_queue, (void*) Foo5, size);

  //makes head pointer move to the next spot in queue so tail can wrap
  anotherFoo = (Foo*) dequeue(new_queue, size);
  if (anotherFoo == NULL) {
    printf("Dequeued: x = %s, y = %s \n", anotherFoo, anotherFoo);
  }
  else {
    printf("Dequeued: x = %5d, y = %10.3f \n", anotherFoo->x, anotherFoo->y);
  }
  
  return 0;
}
