#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tnode.h"


/** Sets a random seed using the system clock, then calls a function in tnode.c that creates random strings and adds them to a tree. It then prints the tree in descending order, and then frees them all from memory.
 */
int main() {
  srand(time(0)); //randomize value
  randtree();

  return 0;
}
