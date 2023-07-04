#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

void main()
{
    init();

    push('A');
    push('B');
    push('C');
    push('D');
    printStack();

    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printStack();

    push('O');
    push('P');
    printStack();

    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printf("스택에서 %c를 꺼냈습니다.\n", pop());

    
}