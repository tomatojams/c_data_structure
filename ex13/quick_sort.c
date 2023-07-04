
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20

int list[MAX_SIZE];
int n;

void Swap(int *x, int *y)
{
	int temp;
	temp = *x;	*x = *y; *y = temp;
}

int partition( int list[], int left, int right)
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right +1;
    pivot = list[left];
    do{
        do
        {
            low++;
        } while (list[low]<pivot);
        do
        {
            high--;
        } while (list[high]>pivot);
        if( low<high) Swap(&list[low], &list[high]);

    } while(low<high);

    Swap(&list[left], &list[high]);
    return high;
}

void quick_sort(int list[], int left, int right)
{
    if(left<right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}


void main(void)
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));

    for(i = 0; i< n; i++)
    list[i] = rand() % 100;

    printf("정렬되기전 데이터 값:\n");
    for(i = 0; i< n; i++) printf("%d,", list[i]);
    printf("\n");
    quick_sort(list, 0, n-1);

    printf("정렬된 후데이터 값:\n");
    for(i = 0; i< n; i++) printf("%d,", list[i]);
    printf("\n");
}