#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"

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
    
    Inorder(root);

    n=searchBST(root,30);
    if (n == NULL) printf("해당키를 가진 노드가 없습니다.\n");
    else printf("데이타 %d를 찾았습니다.\n", n->key);

    deleteNode(root, 40);
    Inorder(root);

}