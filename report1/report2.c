#include <stdio.h>
void proc(int x, int y, int* z)
{
    y +=10;
    *z = *z + y;
    printf("x=%d y=%d *z=%d\n", x, y, *z); // 여기서 x는 지역변수가 되어서 보존


}

void main()
{
    int a=4, b=5;
    proc(a, b, &a);
    printf("a=%d b=%d\n", a, b);

}