#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

void initMouse(mouseType* Mouse)
{
    Mouse->x = 1;
    Mouse->y = 1;
    Mouse->dir = 0;
}

void moveMouse(mouseType* Mouse) // 실제로 이동하므로 포인터로 받음
{

    switch (Mouse->dir)
    {
        case 0: Mouse->y++; break; //동으로
        case 1: Mouse->x++; break; //남으로
        case 2: Mouse->y--; break; //서
        case 3: Mouse->x--; break; //북
    }
    Mouse->dir = 0; //방향초기화
    maze[Mouse->x][Mouse->y] = 1; //이동한 지점을 다시가지않게 1로 표시
}

int MovePossible(int x, int y, int direction) // 테스트만 하므로 지역변수
{
    switch (direction)
    {
        case 0: y++; break;
        case 1: x++; break;
        case 2: y--; break;
        case 3: x--; break;
    }

    if(maze[x][y] == 1)
        return 0;
    else
        return 1;
}

void main(void)
{
    printf("시작합니다.\n");
    stackType Path_Stack; // item이 포함된 스택
    mouseType Mouse;  // item

    initStack(&Path_Stack);
    initMouse(&Mouse);

    push(&Path_Stack, Mouse);

    while (Path_Stack.Top >= 0) // 1개라도 들어간 값이 있다면  초기값이 -1이므로 
    {
        Mouse = pop(&Path_Stack); // 되돌리기

        while(Mouse.dir <= 3) // 시도방향이 있는지
        {
            if(Mouse.x == 7 && Mouse.y == 6) //목표지점
            {
                push(&Path_Stack, Mouse);
                printf("마우스의 이동경로는 다음과 같습니다.\n");
                printStack(&Path_Stack);
                exit(0);
            }
            else
            {
                if(MovePossible(Mouse.x,Mouse.y,Mouse.dir) == 1)
                {
                    push(&Path_Stack, Mouse); // 현재좌표저장
                    moveMouse(&Mouse); // 다음으로 이동

                }
                else
                {
                    Mouse.dir = Mouse.dir +1;
                }
            }

        }
    }

}