#include <stdlib.h>
#include "tnode.h"
#include <stdio.h>


/** Adds a node to the tree and returns the new updated tree, if there is no other nodes, it will create a new one and return it.
 * @param current_tnode Current node of the tree to be added to
 * @param value String value to be added to the tree
 * @return The new updated tree
 */
Tnode *add_tnode(Tnode *current_tnode,char* value) {
  if(current_tnode == NULL) { //Create a new tnode if one doesn't exist
    current_tnode = malloc(sizeof(Tnode));
    current_tnode -> leftLeaf = NULL;
    current_tnode -> rightLeaf = NULL;
    current_tnode -> node = value;

    return current_tnode;
  }

  if(strcmp(current_tnode -> node,value) > 0) { //Recursively go to tnode that is pointed to
    current_tnode->rightLeaf=add_tnode((((Tnode*)current_tnode -> rightLeaf)),value);
  }

  else {
    current_tnode->leftLeaf=add_tnode(((Tnode*)current_tnode -> leftLeaf),value);
  }
}

/** Prints all of the nodes in the tree in descending order
 * @param current_tnode Tree to print from
 */
void treePrint(Tnode *current_tnode) {
  if(current_tnode==NULL) { //exit if empty
    return;
  }
  treePrint(current_tnode->rightLeaf);
  printf("%s\n",current_tnode->node);
  treePrint(current_tnode->leftLeaf);
}

/** Generates a random string
 * @return The new random string
 */
char* randword() {
  char* randWord = (char*)malloc(sizeof(char)*8); //allocate adequate space for the string
  int i,randNum;

  for(i=0;i<8;i++) {
    do{ //to include lower case and uppercase letters but avoid symbols inbetween ascii values
      randNum=(65+rand()%57);
    }while(randNum>=91 && randNum <=96);

    randWord[i] =(char)(randNum);
  }

  randWord[8]='\0'; //to put an end to the string
  return randWord;
}

/** Function that sets up a new tree, puts the random strings in the tree, prints the tree, and then unallocates the memory
 */
void randtree() {
  int treeSize = 10;
  int i = 0;
  char* newRandString = randword(); 
  Tnode* new_tnode = add_tnode(NULL,newRandString); //new tnode with random string as the value

  printf("Generating random strings...\n");
  for(i=0;i<treeSize-1;i++) { //generate random strings
    newRandString=randword();
    new_tnode = add_tnode(new_tnode,newRandString);
  }
  printf("Printing the new tree...\n");
  treePrint(new_tnode); //print in descending order
  printf("Unallocating memory for the new tree...\n");
  freetree(new_tnode); //unallocate from memory
  printf("The tree has been unallocated!\n");
}

/** Unallocates the tree from memory
 * @param current_tnode The tree to free from memory
 */
void freetree(Tnode* current_tnode) {
  if(current_tnode != NULL) {//keeps going until the entire thing is null
    freetree(current_tnode->leftLeaf);
    freetree(current_tnode->rightLeaf);
    free(current_tnode);
  }
}
