#include <stdio.h>
#include "stack_array.h"

void main()
{
    stacktype st1;
    init(&st1);

    push(&st1, 1);push(&st1, 2); push(&st1, 3);
    push(&st1, 4);push(&st1, 5);push(&st1, 6);
    push(&st1, 7);push(&st1, 8);push(&st1, 9);
    push(&st1, 10);
    push(&st1, 11);
    printStack(&st1);
    printf("스택에서 %d를 꺼냈습니다.\n", pop(&st1));
    printf("스택에서 %d를 꺼냈습니다.\n", pop(&st1));
    printf("스택에서 %d를 꺼냈습니다.\n", pop(&st1));
    printf("스택에서 %d를 꺼냈습니다.\n", pop(&st1));
    printStack(&st1);

}