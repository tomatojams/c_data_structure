#include <stdio.h>

void main()
{
    int i = 20;
    int *p;
    p=&i;
    *p=*p-1;
    printf("%d %d",*p,i);
}