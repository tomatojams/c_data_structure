#include <stdio.h>
#include <linked_list.h>

void main()
{

    nodeType n1, n2, n3;
    nodeType *head;


    n1.item = 'A';
    n2.item = 'B';
    n3.item = 'C';
    n1.next = NULL;
    n2.next = NULL;
    n3.next = NULL;

    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
}