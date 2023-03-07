#ifndef TREEBIN_H_INCLUDED
#define TREEBIN_H_INCLUDED

struct node{
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node* TreeInitit();
Node* InsertNode(Node*, int);
Node* RemoveNode(Node*, int);
Node* MaxDir(Node*);
void FreeTree(Node*);
void Path(Node*, int, int);
void PreOrder(Node*);
void PosOrder(Node*);
int Height(Node*);

#endif // TREEBIN_H_INCLUDED
