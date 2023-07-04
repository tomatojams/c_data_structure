#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NO 100

int samples[NO];
int graph[10];

int main(){
    srand((unsigned)time(NULL));

    for(int i = 0; i<10; i++){ //도수 분포표 초기화
        graph[i] = 0;
    }
    

    for(int i = 0; i<NO; i++){ // 샘플 100개 만들기
        samples[i] = rand()% NO;
    }

    for(int i = 0; i<NO; i++){// 샘플 값을 그래프값의 인덱스로 사용해서 그래프값을 증가시킴
        graph[samples[i]/10]++;
    }

    for(int i = 0; i<10; i++){ // 샘플의 할당된 그래프값을 출력
        printf("%d\n", graph[i]);

    }
    return 0;
}