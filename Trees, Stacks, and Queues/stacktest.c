#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct


/** Makes a variety of structs that contain integers and doubles. It then tests each function that is made in stack.c thoroughly.
 *
 */
int main() {
  const int max_entries = 5; // size of stack
  Foo* new_foo1;
  Foo* new_foo2;
  Foo* new_foo3;
  Foo* new_foo4;
  Foo* new_foo5;
  Foo* new_foo6;
  Foo* returned_foo;

  // First, create a stack
  Stack *new_stack = create_stack(max_entries);

  // Allocate a Foo and push it onto the stack.
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  push(new_stack, (void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push(new_stack, (void *) new_foo2);

  // Allocate another Foo and push it onto the stack.
  new_foo3 = (Foo *) malloc(sizeof(Foo));
  new_foo3->x = 56;
  new_foo3->y = 89;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo3->x, new_foo3->y);
  push(new_stack, (void *) new_foo3);
 
  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stack);
  if(returned_foo != NULL) {
    printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  }
  
  // Allocate another Foo and push it onto the stack.
  new_foo4 = (Foo *) malloc(sizeof(Foo));
  new_foo4->x = 14;
  new_foo4->y = 100;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo4->x, new_foo4->y);
  push(new_stack, (void *) new_foo4);
  
  /// Retrieve the Foos and print them.
  returned_foo = (Foo *) pop(new_stack);
  if(returned_foo != NULL) {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  }
  
  // Allocate another Foo and push it onto the stack.
  new_foo5 = (Foo *) malloc(sizeof(Foo));
  new_foo5->x = 27;
  new_foo5->y = 52.45;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo5->x, new_foo5->y);
  push(new_stack, (void *) new_foo5);
 
  // Allocate another Foo and push it onto the stack.
  new_foo6 = (Foo *) malloc(sizeof(Foo));
  new_foo6->x = 90.763;
  new_foo6->y = 34;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo6->x, new_foo6->y);
  push(new_stack, (void *) new_foo6);
  
  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stack);
  if(returned_foo != NULL) {
    printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  }
  
  //Retrieve the Foos and print them.
  returned_foo = (Foo *) pop(new_stack);
  if(returned_foo != NULL) {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
 }
  
  // Clean up
  delete_stack(new_stack);
  free(new_foo1);
  free(new_foo2);
  free(new_foo3);
  free(new_foo4);
  free(new_foo5);
  free(new_foo6);
  
  return 0;
}
