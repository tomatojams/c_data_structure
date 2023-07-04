#define maxItems 100

int itemCount;
int items[maxItems];

void ininList(){
    itemCount = 0;
}

int isEmpty(){
    if(itemCount == 0)
        return 1;
    else return 0;
}

int isFull() {
    if(itemCount == maxItems)
        return 1;
    else return 0;
}

int getCurrentSize(){
    return itemCount;
}

int contains(int pos){
    return items[pos];
}

void insert(int pos, int item)
{
    int i;
    if(isFull() == 0 && pos>= 0 && pos <=itemCount){
        for(i = itemCount; i>pos; i--) // itemCount는 배열 마지막+1 위치가됨
            items[i] = items[i-1]; // 한칸씩 뒤로

        items[pos] = item;
        itemCount +=1;
    }
    else
        printf("리스트가 포화상태거나 상입위치가 잘못되었습니다.\n");
}

void delete(int pos)
{
    int i;
    if(isEmpty() == 0 && pos>=0 && pos<itemCount){
        for (i = pos+1; i<itemCount; i++) // pos오른쪽것을 하나씩 왼쪽으로 이동
        items[i-1] = items[i];

        itemCount -=1;
    }
    else
        printf("리스트가 공백상태이거나 삭제위치가 잘못되었습니다.\n");
}       

void printList()
{
    int i;
    printf("리스트내용을 출력합니다.\n");
    for(i=0; i<itemCount; i++)
        printf("[%d]", items[i]);

    printf("\n");
}
