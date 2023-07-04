#include <stdio.h>
void add( int *a)
{
    *a += 10;
}
void main(void)
{
    int a = 0;
    add(&a);
    printf("%d\n",a);

}