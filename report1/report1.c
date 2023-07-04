#include <stdio.h>

int smaller(int a, int b)
{

    if(a<b)
        return a;
    else 
        return b;
}

void main()
{
    int a=100, b=120;
    printf("%d", smaller(a,b));

}