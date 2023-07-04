#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"
void DescendingOrder(treeNodeType* T)
{
   if(T != NULL)
    {
        DescendingOrder(T->right);
        printf("내림차순으로 %d입니다.\n", T->data);
        DescendingOrder(T->left);
    }
}
void main(void)
{
    treeNodeType *n;
    initTree();
    root = insertBST(root, 40);
    insertBST(root,18);
    insertBST(root,55);
    insertBST(root,10);
    insertBST(root,25);
    insertBST(root,45);
    insertBST(root,75);
    DescendingOrder(root);
}