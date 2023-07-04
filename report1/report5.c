#include <stdio.h>

void main()
{
    int x[2][5]={{110, 115, 220, 250, 355},{114, 112, 136, 138, 141}};
    int i, total1, total2;

    total1=total2=0;
    for(i=0; i<=4; i++)
    {
        total1 += x[0][i];
        total2 += x[1][i];

    }
    for(i=0;i<=4;i++)
        printf("x[0][%d]=%d\n", i, x[0][i]);
    printf("tatal1=%d\n", total1);

    for(i=0;i<=4;i++)
        printf("x[1][%d]=%d\n", i, x[1][i]);
    printf("tatal2=%d\n", total1);
}