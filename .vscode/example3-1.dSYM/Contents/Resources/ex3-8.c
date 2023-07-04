#include <stdio.h>
#include <stdlib.h>

typedef struct charNode
{
    char ch;
    struct charNode *p;

} nodeType;

void main()
{
    nodeType *node1, *node2;

    node1 = (nodeType*)malloc(sizeof(nodeType));
    node1->ch = 'X';
    node1->p = NULL;

    node2 =(nodeType*)malloc(sizeof(nodeType));
    node2->ch = 'Z';
    node2->p = NULL;
}