#define MaxQueueSize 6

typedef struct 
{
    int Front;
    int Rear;
    int Count;
    int data[MaxQueueSize];
} queueType;

#define MaxQueueSize 6





void init(queueType* Qptr)
{
    Qptr->Front = 0;
    Qptr->Rear = -1;
    Qptr->Count = 0;
}

int isEmpty(queueType* Qptr)
{
    return(Qptr->Count == 0);
}

int isFull(queueType* Qptr)
{
    return(Qptr->Count == MaxQueueSize);
}

int getSize(queueType* Qprt)
{
    return(Qprt->Count);
}

void insert(queueType* Qptr, int item)
{
    if(isFull(Qptr))
        printf("더이상 넣을 수 없습니다.\n");
    else
    {
        Qptr->Rear = (Qptr->Rear+1)%MaxQueueSize; // 원형배일이라 %연산자를 사용
        Qptr->data[Qptr->Rear] = item;
        Qptr->Count +=1;
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
        temp = Qptr->data[Qptr->Front];
        Qptr->Front = (Qptr->Front +1)%MaxQueueSize;
        Qptr->Count -=1;
        return(temp);
    }
}

void queuePrint(queueType* Qptr)
{
    int i,j;
    printf("큐에는 총 %d개의 원소가 있습니다.\n", getSize(Qptr));

    j=Qptr->Front;
    for(i=1;i<=Qptr->Count;i++)
    {
        printf("큐의 %d번째 원소는 %d입니다.\n", i, Qptr->data[j%MaxQueueSize]);
        j +=1;
        
    }

}

