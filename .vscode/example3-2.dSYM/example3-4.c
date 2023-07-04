#include <stdio.h>

void main()
{
    short a[3] = {10, 20, 30};

    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
    printf("%d\n", *a);
    printf("%d", *(a+1));


}