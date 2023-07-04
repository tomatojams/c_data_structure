#include <stdio.h>
#include <stdlib.h>

void change_value(int* p, int* q)
{
    *p = 5;
    *q = 10;
}

void main(void)
{
    int *a, *b;
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    *a = 10;
    *b = 20;
    change_value(a,b);
    printf("%d %d",*a, *b);
}