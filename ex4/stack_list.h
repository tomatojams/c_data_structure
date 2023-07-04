#define MaxStackSize 100

typedef struct node
{
    char data;
    struct node* next;
    
} nodeType;

nodeType* Stack_top; // 전역변수라서 동적메모리 할당이 필요없음.

void init()
{
    Stack_top = NULL;
}

int isEmpty() 
{
    if(Stack_top == NULL)
        return 1;
    else return 0;
}

int getSize()
{
    nodeType* p;
    int count = 0;

    for(p=Stack_top; p != NULL; p=p->next)
        count +=1;

    return count;
}

int isFull()
{
    return(getSize() ==MaxStackSize);
}

void push(char item)
{
    //삽입할 노드의 생성
    nodeType* p=(nodeType*)malloc(sizeof(nodeType)); // push로 생성했다가 pop으로 해제할 것이기떼문에
                                                     // 동적할당을 함. 
    p->data = item;

    p->next = Stack_top; // 기존의 것은 두번째 스택으로 이동
    Stack_top = p; // 새로운것이 탑으로 생성
}

char pop()
{
    nodeType *temp; // 기존에 생성된 것을 그대로 복사해 해제할것이므로 새로 생성은 안함.
    char item;

    if(isEmpty())
    {
        printf("스택이 비었습니다.\n");
        exit(1);
    }
    else
    {
        temp= Stack_top; // 해제할 것을 임시로 넣어둠
        Stack_top = temp->next; //두번째것이 탑으로 이동
        item = temp->data;// 해제할 것에서 아이템을 꺼냄
        free(temp); // 동적할당을 한것을 해제하는 push에서 동적할당하고 pop에서 해제
        return(item);

    }
}

void printStack()
{
    nodeType* p;
    printf("스택의 크기는 %d입니다.\n", getSize());
    for(p=Stack_top; p != NULL; p=p->next)
        printf("%c\n", p->);
}