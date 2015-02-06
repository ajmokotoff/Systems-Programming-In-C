#ifndef TNODE_H
#define TNODE_H

struct _Tnode {
  char* node;
  struct _Tnode *leftLeaf;
  struct _Tnode *rightLeaf;
};

typedef struct _Tnode Tnode;

Tnode *add_tnode(Tnode *current_tnode,char* value);
void treePrint(Tnode *current_tnode);
char* randword();
void randtree();
void freetree(Tnode* current_tnode);

#endif
