#include <stdio.h>
int fib(const int number, int arr[]){
    int a=0;
    int b=1;
    int n=0;
    while(true){
        int result=a+b;
        if(result>number){
            return n;
        }
        arr[n]=result;
        a=b;
        b=result;
        n++;
    }
}

int main(){
    int n=0;
    scanf("%d",&n);
    int number=0;
    int arr[500];
    for(int i=1;i<=n;i++){
        int arrr[500]={};
        scanf("%d",&number);
        int len=fib(number,arr);
        int count=number;
        printf("%d = ",number);
        for(int i=len-1;i>=0;i--){
            if(count-arr[i]>=0){
                count=count-arr[i];
                printf("1");
            }else{
                printf("0");
            }
        }
        printf(" (fib)\n");
    }
}
