#include <stdio.h>

void change_value(int a, int b)
{
    a = 75;
    b = 50;

}

void main()
{
    int a=30, b=25;
    change_value(a,b);
    printf("%d\n",a+b);
}