#include <stdlib.h>
#include <stdio.h>
#include "tnode.h"


/** Creates a tree and adds a series of names to it. It then goes through the tree manually to make sure that each name is in the right place. Once confirmed, it prints the tree in descending order. Finally, it frees it all from memory.
 *
 */
int main() {
  Tnode* tree = NULL;
  tree=add_tnode(tree,"andrew");
  tree=add_tnode(tree,"jamie");
  tree=add_tnode(tree,"yellow");
  tree=add_tnode(tree,"purple");
  tree=add_tnode(tree,"yellow");
  tree=add_tnode(tree,"Andrew");
  tree=add_tnode(tree,"Bobby");
  tree=add_tnode(tree,"John");
  tree=add_tnode(tree,"John");
  tree=add_tnode(tree,"Henry");
  tree=add_tnode(tree,"Abby");
  tree=add_tnode(tree,"abby");

  printf("Expect andrew, actual: %s\n",tree->node);
  printf("Expect jamie, actual: %s\n",tree->leftLeaf->node);
  printf("Expect yellow, actual: %s\n",tree->leftLeaf->leftLeaf->node);
  printf("Expect purple, actual: %s\n",tree->leftLeaf->leftLeaf->rightLeaf->node);
  printf("Expect yellow, actual: %s\n",tree->leftLeaf->leftLeaf->leftLeaf->node);
  printf("Expect Andrew, actual: %s\n",tree->rightLeaf->node);
  printf("Expect Bobby, actual: %s\n",tree->rightLeaf->leftLeaf->node);
  printf("Expect John, actual: %s\n",tree->rightLeaf->leftLeaf->leftLeaf->node);
  printf("Expect John, actual: %s\n",tree->rightLeaf->leftLeaf->leftLeaf->leftLeaf->node);
  printf("Expect Henry, actual: %s\n",tree->rightLeaf->leftLeaf->leftLeaf->rightLeaf->node);
  printf("Expect Abby, actual: %s\n",tree->rightLeaf->rightLeaf->node);
  printf("Expect abby, actual: %s\n",tree->rightLeaf->leftLeaf->leftLeaf->leftLeaf->leftLeaf->node);

  printf("Tree printing in descending order:\n");
  treePrint(tree);
  printf("Unallocating memory for the tree...\n");
  freetree(tree);
  printf("The tree has been unallocated!\n");
  return 0;
}
