#include <stdio.h>

int main()
{
    int a[5] = {2000, 2001, 2002, 2003, 2004};

    printf("a[0]    : %d\n", a[0]);
    printf("*a      : %d\n", *a);
    printf("*(a+1)   : %d\n", *(a+1));
    printf("*(&a[0]) : %d\n", *(&a[0]));
    printf("*(&a[0]+1): %d\n", *(&a[0]+1));
    printf("a        : %p\n", a);
    printf("&a[0]    : %p\n", &a[0]);
    printf("&a[0]+1  : %p\n", &a[0]+1);
    return 0;
}