#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ofApp.h"

#define BAR_WIDTH 50
#define MAX 100

int samples[MAX];
int graph[10];

void frequencyTableGenerate() {
    srand((unsigned)time(NULL));

    for(int i=0; i<10; i++){
        graph[i] = 0;
    }

    for(int i =0; i<MAX; i++){
        samples[i] = rand() %MAX;
        graph[samples[i]/10]++;
    }
}

// ofRect 그래프 그리기
void frequencyTableDraw() {
    for(int i = 0; i <10; i++){
        ofRect(i * BAR_WIDTH, 0, BAR_WIDTH, graph[i]*10);

    }
}