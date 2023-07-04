#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void main()
{

    nodeType *head, *temp;

    temp =(nodeType*)malloc(sizeof(nodeType));
    temp->item = 'A';
    temp->next = NULL;
    head = temp; // 동적생성된 노드를 첫번째 노드로 지정

    temp =(nodeType*)malloc(sizeof(nodeType));
    temp->item = 'B';
    temp->next = NULL;
    insertNext(head, temp);

    temp =(nodeType*)malloc(sizeof(nodeType));
    temp->item = 'C';
    temp->next = NULL;
    insertNext(head, temp);

    printList(head);
    


}