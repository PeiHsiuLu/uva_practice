#include <stdio.h>
#include <math.h>
int main(){
    int num_arr[31];
    while(true){
        num_arr[0]=0;
        int n=0;
        int integer;
        scanf("%d",&integer);
        int sum=0;
        int calculation=integer;
        if(integer == 0){
            return 0;
        }
        for(int i=30;i>=0;i--){
            if(calculation-pow(2,i)>=0){
                calculation=calculation-pow(2,i);
                num_arr[n]=1;
                sum+=1;
                n++;
            }else if(num_arr[0]!=1){
                continue;
            }else{
                num_arr[n]=0;
                n++;
            }
        }
        int size_len = sizeof(num_arr)/sizeof(num_arr[0]);
        printf("The parity of ");
        for(int j=0;j<n;j++){
            printf("%d",num_arr[j]);
        }
        printf(" is %d (mod 2).\n",sum);
    }

}
