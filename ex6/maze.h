#define MaxRowSize 7
#define MaxColSize 6

int maze[MaxRowSize+2][MaxColSize+2] ={
    {1,1,1,1,1,1,1,1},
    {1,0,1,1,0,1,1,1},
    {1,0,0,1,0,1,1,1},
    {1,1,0,0,0,1,1,1},
    {1,1,1,0,0,0,1,1},
    {1,0,0,0,1,1,1,1},
    {1,1,0,1,0,0,0,1},
    {1,0,0,0,0,1,0,1},
    {1,1,1,1,1,1,1,1}};

typedef struct {
    int x;
    int y;
    int dir;
} mouseType;

typedef struct {
    int Top;
    mouseType stack[MaxRowSize*MaxColSize];
} stackType;

void initStack(stackType* Sptr)
{
    Sptr->Top = -1;
}

void push(stackType* Sptr, mouseType Item)
{
    if(Sptr->Top >= MaxRowSize*MaxColSize)
        printf("더이상 넣을수 없습니다.\n");
    else{

        Sptr->stack[Sptr->Top+1] = Item;
        Sptr->Top=Sptr->Top +1;
    }
}

mouseType pop(stackType* Sptr)
{
    mouseType temp;

    if(Sptr->Top <0){
        printf("스택이 비었습니다.\n");
        temp.dir = -1;
        return temp;
    }
    else{
        temp = Sptr->stack[Sptr->Top];
        Sptr->Top -=1;
        return temp;
    }
}

void printStack(stackType* Sptr)
{
    int i;
    if(Sptr->Top >= 0)
        for(i=0;i<=Sptr->Top; i++)
            printf("<%d, %d, %d>\n", Sptr->stack[i].x,Sptr->stack[i].y,Sptr->stack[i].dir);
    else
        printf("스택이 비었습니다.\n");
}
