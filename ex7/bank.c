#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

void main()
{
    int CustomerArrivalTime = 0;
    customerType C1;

    serverType S1;
    S1.CustomerNumber = 0;
    S1.WaitingTime = 0;
    S1.TotalWaitingTime = 0;
    S1.AvgWaitingTime = 0;
    S1.ServiceStartTime = 0;

    init();
    CustomerArrivalTime = rand() % ConstMaxInterval;

    while(CustomerArrivalTime <=ConstCloseTime)
    {
        C1.ArrivalTime = CustomerArrivalTime;
        C1.ServiceTime = rand()%ConstMaxSvcTime +1;
        insert(C1);
        
        CustomerArrivalTime = CustomerArrivalTime +(rand() % ConstMaxInterval);
    }

    while(!isEmpty())
    {
        C1 = delete();
        S1.CustomerNumber++;

        if(S1.ServiceStartTime >= C1.ArrivalTime){
           S1.WaitingTime = S1.ServiceStartTime - C1.ArrivalTime;
           S1.TotalWaitingTime = S1.TotalWaitingTime + S1.WaitingTime;
           printf("%d번째 고객의 대기시간은 %d분 입니다.\n",S1.CustomerNumber, S1.WaitingTime);
        }
        else{
           S1.ServiceStartTime = C1.ArrivalTime;
           printf("%d번째 고객의 대기시간은 0분입니다.\n", S1.CustomerNumber); 
        }
        S1.ServiceStartTime = S1.ServiceStartTime +C1.ServiceTime;
    }
    S1.AvgWaitingTime =(float)S1.TotalWaitingTime / (float)S1.CustomerNumber;
    printf("방문한 고객의 총수는 %d명입니다.\n",S1.CustomerNumber);
    printf("방문한 고객의 총 대기시간은 %d분 입니다.\n", S1.TotalWaitingTime);
    printf("방문한 고객의 평균 대기시간은 %f분 입니다.\n", S1.AvgWaitingTime);

}