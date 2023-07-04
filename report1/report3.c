#include <stdio.h>

void main()
{
    int x[5]={17,34,45,52,36};
    int y[5]={22,85,71,33,14};
    int z[5];
    int* p[3];
    int i;

    p[0]=x;
    p[1]=y;
    p[2]=z;

    for(i=0;i<=4;i++)
        *(p[2]+i)=*(p[0]+i)+(*(p[1]+i));

    for(i=0;i<=4;i++)
        printf("z[%d]=%d \n", i, z[i]);
}