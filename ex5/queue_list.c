#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

void main(void)
{
    init();

    insert('A');
    insert('B');
    insert('C');
    insert('D');
    printQueue();

    printf("큐에서 %C를 꺼냈습니다.\n", delete());
    printf("큐에서 %C를 꺼냈습니다.\n", delete());
    printQueue();

    insert('O');
    insert('P');
    printQueue();
}