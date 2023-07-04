#include <stdio.h>

struct student
{
    char s_sum[5];
    char s_name[10];
    int year;

};
void main()
{
    struct student a = {"S001", "Petre", 2021};
    struct student b = {"S002", "Jane", 2022};
    if (a.year >= b.year)
            printf("%s\n", a.s_name);
    else
            printf("%s\n", b.s_name);
    
}