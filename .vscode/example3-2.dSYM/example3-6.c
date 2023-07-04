#include <stdio.h>

int func_add( int *a, int *b)
{
    int result;
    a += 1;
    b += 1;
    result = *a + *b;
    return result;

}

void main()
{
    int a[4] = {10,20, 30, 40};
    int b[4] = {100, 200, 300, 400};
    int result;
    result = func_add(a,b);
    printf("%d\n",result);
    
}