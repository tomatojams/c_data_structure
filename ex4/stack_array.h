#define MaxStackSize 10

typedef struct {
    int Top;
    int data[MaxStackSize];
} stacktype;

void init(stacktype* Sptr)
{
    Sptr->Top = -1; // -1로 설정 마이너스일때 비었음 표시위해
}

int isEmpty(stacktype *Sptr)
{
    return(Sptr->Top <0);
}

int isFull(stacktype* Sptr)
{
    return(Sptr->Top >= MaxStackSize-1);
}

int getSize(stacktype* Sptr)
{
    return (Sptr->Top+1);
}

void push(stacktype* Sptr, int Item)
{
    if(isFull(Sptr))
        printf("더이상 넣을 수 없음\n");
    else
    {
        Sptr->data[Sptr->Top+1] = Item;
        Sptr->Top = Sptr->Top+1;

    }
}

int pop(stacktype* Sptr)
{
    int temp;
    if(isEmpty(Sptr))
    {
        printf("스택이 비었습니다.\n");
        return -1;
    }
    else
    {
        temp=Sptr->data[Sptr->Top];
        Sptr->Top -=1;
        return temp;
    }
}

void printStack(stacktype* Sptr)
{

    int i;
    if(Sptr->Top==-1)
        printf("스택이 비었습니다.\n");
    else
        for(i=0;i<=Sptr->Top;i++)
            printf("스택의 %d번째 원소는[%d]입니다.\n",i+1,Sptr->data[i]);


}