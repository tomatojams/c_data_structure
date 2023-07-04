typedef struct Node
{
    char item;
    struct Node* next;
} nodeType;

void initList(nodeType *headPtr) {
    headPtr = NULL;
}

int isEmpty(nodeType *headPtr) {

    if(headPtr == NULL)
        return 1;
    else return 0;
}

int getCurrentSize(nodeType *headPtr){
    nodeType *p;
    int COUNT = 0;

    for(p=headPtr; p!=NULL; p=p->next)
        COUNT += 1;

    return COUNT;
}

char contains(nodeType *headPtr, int POS){
    nodeType *p = headPtr;
    int i;
    for(i =0;i<POS;p=p->next)
        if(p == NULL) return NULL;

    return p->item;

}

void insertNext(nodeType *preNode, nodeType *newNode) // 새것에 받아적고 앞의것 수정하고
{
    if(newNode != NULL) {
        newNode->next =preNode->next; // 새노드를 앞의것이 가르치는 다음것을 받아서 적음
        preNode->next = newNode; // 앞의것을 수정

    }
}

nodeType* removeNext(nodeType *preNode)
{
    nodeType *removed = preNode->next;

    if(removed != NULL)
        preNode->next = removed->next;
        removed = NULL;
    return removed;

}


void printList(nodeType *headPtr)
{
    nodeType *p = headPtr;

    printf("리스트내용출력\n");
    for(p=headPtr; p != NULL; p=p->next)
    {
        printf("[%c]", p->item);
    }
    printf("\n");
}

