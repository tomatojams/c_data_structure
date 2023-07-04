#include <stdio.h>

int sum(int a[], int size)
{
    int i, sum = 0;
    for(i=0; i<size;i++)
    {
        sum = sum + a[i];
    }
    return sum;

}

void main()
{
    int total, score[3] = {98, 92, 88};

    total= sum(score, 3);
    printf("합계는 :%d\n", total);

}