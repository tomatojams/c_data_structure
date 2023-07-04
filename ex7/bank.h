#define ConstCloseTime 120 //업무시간
#define ConstMaxInterval 5 //도착시간 0~4분
#define ConstMaxSvcTime 10 // 서비스시간 1~9분

//고객 도착, 서비스시간

typedef struct {
    int ArrivalTime;
    int ServiceTime;
} customerType;

typedef struct node {
    customerType Customer;
    struct node* next;
} nodeType;

nodeType* Front;
nodeType* Rear;

typedef struct {
    int CustomerNumber; //고객수
    int ServiceStartTime; // 서비스 시작시간
    int WaitingTime; // 대기시간
    int TotalWaitingTime; // 총대기시간
    float AvgWaitingTime; // 평균대기시간
} serverType;

void init() {
    Front = NULL;
    Rear = NULL;
}

int isEmpty() {
    return (Front == NULL);
}

void insert(customerType NewCustomer) //임시포인터메모리할당생성, 새로운 아이템채움, 새로운 포인터설정(NULL)
// 연결수정(뒤에 붙이므로 Rear->Next), Rear수정
{
    nodeType* p = (nodeType*)malloc(sizeof(nodeType));
    p->Customer = NewCustomer;
    p->next = NULL;

    if(isEmpty()){
        Front = p;
        Rear = p;
    }
    else{
    Rear->next = p;
    Rear = p;
    }

}

customerType delete() // 임시포인터생성(+임시데이타타입), 데이타보존, 연결수정(Front 포인터수정),값리턴
{
    nodeType* p;
    customerType temp_data;

    if(isEmpty()){
        printf("큐가 비었습니다.\n");
        temp_data.ArrivalTime = -1;
        temp_data.ServiceTime = -1;
        return temp_data;
    }
    else {
        p = Front; //임시포인터
        temp_data = p->Customer; //데이타 보존
        Front = p->next; // Front 포인터 수정
        free(p);
        return temp_data;

    }
}

