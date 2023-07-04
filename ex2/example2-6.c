#include <stdio.h>
#include <string.h>

typedef struct{
    char name[10];
    int age;
    float salary;
} personType;

void main()
{
    personType mywife;
    personType *p = &mywife;

    strcpy(mywife.name, "angela");
    p->age = 30;

    mywife.salary = 35000;

    printf("%d\n", p->age);
    printf("%f\n", p->salary);
}