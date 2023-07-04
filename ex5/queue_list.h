
typedef struct node
{
    char data;
    struct node* next;
} nodeType;

nodeType* Front;
nodeType* Rear;

void init()
{
    Front = NULL;
    Rear = NULL;
}

int isEmpty()
{
    return(Front == NULL);
}

int getSize()
{
    nodeType *p;
    int count = 0;

    for(p = Front; p != NULL; p=p->next)
        count +=1;

    return count;
}

void insert(char item)
{
    nodeType* p =(nodeType*)malloc(sizeof(nodeType));
    p->data = item;
    p->next = NULL;

    if(isEmpty())
    {
        Front = p;
        Rear = p;
    }
    else
    {
        Rear->next = p;
        Rear = p;
    }
}

char delete()
{
    nodeType* p;
    char item;

    if(isEmpty())
    {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    else
    {
        p = Front;
        Front = p->next;
        item = p->data;
        free(p);
        return(item);
    }
}

void printQueue()
{
    nodeType* p;
    printf("Queue의 크기는 %d입니다.\n", getSize());
    for(p=Front; p != NULL; p= p->next)
        printf("%c\n", p->data);
}