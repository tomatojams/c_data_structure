#include <stdio.h>
#include "queue_array.h"

void main()
{
    queueType q1;
    init(&q1);

    insert(&q1, 10);
    insert(&q1, 20);
    insert(&q1, 30);
    insert(&q1, 40);
    insert(&q1, 50);
    insert(&q1, 60);
    insert(&q1, 70);

    queuePrint(&q1);

    printf("큐에서 %d를 꺼냈습니다.\n", delete(&q1));
    printf("큐에서 %d를 꺼냈습니다.\n", delete(&q1));
    printf("큐에서 %d를 꺼냈습니다.\n", delete(&q1));

    insert(&q1, 80);
    insert(&q1, 90);

    queuePrint(&q1);

}