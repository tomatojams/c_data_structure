#include <stdio.h>
#include <linked_list.h>
#include <stdlib.h>

void main()
{
    // 1 노드타입 포인터와 첫번째 노드생성
    nodeType *head, *temp;
    head = (nodeType*)malloc(sizeof(nodeType));
    
    // 2 두번째 노드생성
    head->item = 'A';
    head->next =(nodeType*)malloc(sizeof(nodeType));

    // 세번째 노드생성
    head->next->item = 'B';
    head->next->next =(nodeType*)malloc(sizeof(nodeType));



}

