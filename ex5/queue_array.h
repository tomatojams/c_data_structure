#define MaxQueueSize 10

typedef struct {
    int Front;
    int Rear;
    int data[MaxQueueSize];
} queueType;

void init(queueType* Qptr)
{
    Qptr->Front = 0;
    Qptr->Rear = -1;
}

int isEmpty(queueType* Qptr)
{
    return(Qptr->Front > Qptr->Rear);
}

int isFull(queueType* Qptr)
{
    return(Qptr->Rear >= MaxQueueSize - 1);
}

int getSize(queueType* Qptr)
{
    return(Qptr->Rear - Qptr->Front +1);
}

void insert(queueType* Qptr, int item)
{
    if(isFull(Qptr))
        printf("더이상 넣을 수 없습니다.\n");
    else
    {
        Qptr->Rear +=1; // Rear을 먼저 증가시키고 Rear위치에 item을 넣음
        Qptr->data[Qptr->Rear] = item;
    }
}


int delete(queueType* Qptr)
{
    int temp;

    if(isEmpty(Qptr))
    {
        printf("큐가 비었습니다.\n");
        return -1;
    }
    else
    {
        temp = Qptr->data[Qptr->Front]; // Front를 먼저 가져오고 Front를 증가시킴
        Qptr->Front +=1;
        return temp;
    }
}


void queuePrint(queueType* Qptr)
{
    int i=1,j;
    printf("큐에는 총 %d개의 원소가 있습니다\n", getSize(Qptr));

    for(j=Qptr->Front; j<=Qptr->Rear; j++)
        printf("큐의 %d번째 원소는 %d입니다.\n", i++, Qptr->data[j]);

}
