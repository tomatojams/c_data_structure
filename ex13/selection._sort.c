
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
int list[MAX_SIZE];
int sorted[MAX_SIZE];

void Swap(int *x, int *y)
{
	int temp;
	temp = *x;	*x = *y; *y = temp;
}

void selection_sort(int list[], int n)
{
    int i, j, least;
    for(i = 0; i < n; i++) {
        least = i;

        for(j = i+1; j < n; j++)
        if(list[j]<list[least]) least = j;
            
        Swap(&list[i], &list[least]);

    }
}

void insertion_sort(int list[], int n)
{
    int i, j, key;
    for(i = 1; i< n; i++){
        key = list[i];
        for (j = i-1; j>=0 && list[j]>key;j--)
            list[j+1]= list[j];
        list[j+1] =key; //
    }
}

void bubble_sort(int list[], int n)
{
    int i, j, temp;
    for (i= n-1; i> 0; i--){
        for(j =0; j<i; j++)
        if(list[j]>list[j+1])
            Swap(&list[j], &list[j+1]);
    }
}

void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for(i = first + gap; i <=last; i = i+gap){
        key = list[i]; // 오른쪽에서 키를 잡고
        for(j= i-gap; j>=first && list[j]>key; j = j-gap) //키보다 왼쪽것들이 크면 
            list[j+gap] = list[j]; // 오른쪽으로 하나씩 이동

        list[j+gap] = key; // for문 마지막에 갭만큼 -해서 적정위치에 삽입
    
    }
}

void shell_sort(int list[], int n)
{
    int i, gap;
    for(gap = n/2; gap>0; gap= gap/2){ // 2로 나누고 몫을 취함
        if((gap %2)==0) gap++; //짝수면 홀수로 만들어줌
        for(i = 0; i<gap; i++) 
            inc_insertion_sort(list, i, n-1, gap);
    }
}

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l; // i 왼쪽, j 중간바로 다음, k 왼쪽
    i = left; j = mid+1; k = left;

    while( i <= mid && j <= right){
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++]; // 둘중의 작은값을 sorted 왼쪽부터 넣는다
    }
    if(i>mid) // i가 미드를 넘어가서 오른쪽 남아있는것을 일괄 복사
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    else // 왼쪽에 남아있는것을 일괄 복사
        for(l =i; l<= mid; l++)
            sorted[k++] = list[l];
    
    for(l= left; l <= right; l++)
        list[l] = sorted[l];

} 

void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left<right){
        mid = (left+right)/2; // 미드값 잡고
        merge_sort(list, left, mid); //왼쪽 절반
        merge_sort(list, mid+1, right); // 오른쪽 절반 분할
        merge(list, left, mid, right); // 병합
    }

}



void main(void)
{
    int i;
    int n = MAX_SIZE;
    
    srand(time(NULL));

    for(i = 0; i< n; i++)
    list[i] = rand() % 100;

    printf("정렬되기전 데이터 값:\n");
    for(i = 0; i< n; i++) printf("%d,", list[i]);
    printf("\n");
    merge_sort(list, 0, MAX_SIZE-1);

    printf("정렬된 후데이터 값:\n");
    for(i = 0; i< n; i++) printf("%d,", list[i]);
    printf("\n");
}