#define maxItems 100

int itemCount;
int items[maxItems];

void initList(){
    itemCount = 0;
}

int isEmpty() 
{
    if(itemCount == 0)
    return 1;
    else return 0;

}

int isFull()
{
    if (itemCount == maxItems)
        return 1;
    else return 0;
}

int getCurrentSize()
{
    return itemCount;
}
int contains(int pos){
    return items[pos]
}

void insert(int pos, int item)
{
    int i;
    if(ifFull()==0 && pos>=0 && pos<=itemCount ) /*새로운 포지션이 맨뒤에서 하나더 덧붙일수도있다
    따라서 position보다 +1 큰값을 가지는 itemCount와 같은 값을 수있다. */
    {
        for(i = itemCount; i>pos; i--)
        /* 맨뒤에서부터 삽입하므로 itemCount를 대입하고 insert되는 위치보다 클때까지 반복해서 정렬*/
        items[i] = items[i-1];

        items[pos] = item;
        /* 정해진 위치에 삽입 */
        itemCount += 1;
    
    }
    else 
    printf("리스트가 포화상태이거나 삽입위치가 잘못되었습니다")

}


void insert(int pos, int item)
{
    int i;
    if(isFull()==0 && pos>=0 && pos<=itemCount)
    {
     for(i=itemCount;i>pos;i--)
        { items[i]=items[i-1]; }
        items[pos] = item;
        itemCount += 1;
    }
    else
    printf("리스트가 포화상태이거나 삽입위치가 잘못되었습니다")

}


void delete(int pos)
{
    if(isEmpty == 0 && pos>=0 && pos <itemCount)
    {
        for(i=pos+1;i<itemCount;i++) /* pos보다 다음값을 포지션으로 이동하고,
        itemCount는 포지션+1값이므로 삽입이 없는 상태에서 위치값의 최대는 itemCount보다 작아야 한다  
        i에 pos보다 1이 큰값을 넣는 이유는 pos+1값을 pos에 넣는다 
        다만, 리스트 마지막값의 경우 i=itemCount가 되므로 for문자체가 실행되지 않고
        itemCount만 하나 줄어들어서 자동으로 삭제되는 효과를 보는식의 코딩
        
        */
        items[i-1] = items[i];
    
        itemCount -= 1;

    }

    else
    printf("리스트가 공백상태이거나 삭제위치가 잘못되었습니다.")
}

void delete(int pos)
{
    int i;
    if(isEmpty==0 && pos>=0 && pos<itemCount)
    {
        for(i=pos+1;i<itemCount;i++)
        {
            items[i-1] = items[i];
        }
        itemCount -= 1;
    }
    else
    printf("리스트공백 또는 삭제위치 잘못")

}

void printList()
{
    int i;
    printf("리스트 내용을 출력합니다.\n");
    for(i=0; i<itemCount;i++)
        printf("[%d]", items[i]);

    printf("\n");    
}