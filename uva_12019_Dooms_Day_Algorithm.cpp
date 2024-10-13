#include <stdio.h>

int main(){
    //2011年1月1日是禮拜六
    int M;
    int D;
    int month_array[11]={31,28,31,30,31,30,31,31,30,31,30};//從1月到11月，因為12月基本上不會被計算到，所以不用記錄到12月
    int Case;
    int weekday;
    scanf("%d",&Case);
    int n=1;
    while(n<=Case){
        int count=0;
        scanf("%d %d",&M,&D);
        count+=(D+6-1);//距離1月1日多少天，且1月1日是禮拜六，所以要 +6
        if(M>1){
            for(int i=0;i<M-1;i++){
                count+=month_array[i];
            }
        }
        weekday = count%7;
        switch(weekday){
            case 1:
                printf("Monday");
                break;
            case 2:
                printf("Tuesday");
                break;
            case 3:
                printf("Wednesday");
                break;
            case 4:
                printf("Thursday");
                break;
            case 5:
                printf("Friday");
                break;
            case 6:
                printf("Saturday");
                break;
            case 0:
                printf("Sunday");
                break;
        }
        printf("\n");
        n++;
    }


    return 0;
}