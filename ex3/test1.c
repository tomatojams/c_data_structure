#include <stdio.h>
void add(int* a)
{
    *a = *a +10;
}

void main()
{
    int a = 0;
    add(&a);
    printf("%d",a);
}