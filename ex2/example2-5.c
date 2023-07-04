#include <stdio.h>
#include <string.h>

struct Person {

    char name[10];
    int age;
    float salary;

};

void main()
{
    struct Person person1;
    strcpy(person1.name, "james");
    person1.age = 10;
    person1.salary = 35000;

    printf("%s %d %f\n", person1.name, person1.age, person1.salary);
}