#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void main()
{

    nodeType *head, *temp;

    temp=(nodeType*)malloc(sizeof(nodeType));
    temp->item = 'A';
    temp->next = NULL;
    head = temp;

    temp=(nodeType*)malloc(sizeof(nodeType));
    temp->item = 'B';
    temp->next = NULL;
    insertNext(head,temp);

    temp=(nodeType*)malloc(sizeof(nodeType));
    temp->item = 'C';
    temp->next = NULL;
    insertNext(head,temp);

    printList(head);
    removeNext(head);
    printList(head);
}