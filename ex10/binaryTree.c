#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

void main()
{
    treeNodeType *b, *c, *d, *e, *f;

    initTree();
    d = createTree('D', NULL, NULL);
    e = createTree('E', NULL, NULL);
    f = createTree('F', NULL, NULL);

    b = createTree('B', d, e);
    c = createTree('C', f, NULL);

    root = createTree('A', c, b);

    printf("\n트리를 중위순회합니다.\n");
    Inorder(root);

    printf("\n트리를 전위순회합니다.\n");
    Preorder(root);

    printf("\n트리를 후위순회합니다.\n");
    Postorder(root);

    int count;
    count = TreeSize(root);
    printf("노드의 개수는 %d입니다.\n",count);

}