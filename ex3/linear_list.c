#include <stdio.h>
#include "linear_list.h"

void main()
{

    ininList();
    insert(0,10);
    insert(0, 20);
    insert(1, 30);
    insert(1, 40);
    printList();

    delete(2);
    printList();    
}