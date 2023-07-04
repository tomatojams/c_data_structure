#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_array_postfix.h"

double cal_postfix(char expr[])
{
    char c;
    int i = 0;
    int st_value, val_left, val_right;

    stacktype st1;
    init(&st1);

    for(i=0; i<strlen(expr);i++)
    {
        c = expr[i];

        if(c >= '0' && c <='9')
        {
            st_value = c - '0';
            push(&st1, st_value);
        }
        else
        {
            val_right = pop(&st1);
            val_left = pop(&st1);
            switch(c){
                case '+': push(&st1, (val_left + val_right)); break;
                case '-': push(&st1, (val_left - val_right)); break;
                case '*': push(&st1, (val_left * val_right)); break;
                case '/': push(&st1, (val_left / val_right)); break;


            }
        }


    }
    return pop(&st1);

}

void main()
{

    char expr1[10] = "25+3*1-";
    char expr2[10] = "25+3+2/";
    
    printf("연산식: %s의 값은 %1f입니다\n", expr1, cal_postfix(expr1));
    printf("연산식: %s의 값은 %1f입니다\n", expr2, cal_postfix(expr2));
    

}