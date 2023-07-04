#include <stdio.h>

void swap(int *x, int* y)
{
    int* temp; // 주소의 지역변수만 바뀐거라 영향없음
    temp = x;
    x = y;
    y = temp;
}

void main()
{
    int a = 10, b= 20;
    swap(&a,&b);
    printf("%d %d", a,b);
}