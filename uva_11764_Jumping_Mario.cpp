#include <stdio.h>
int main(){
    int Case;
    scanf("%d",&Case);
    int n=0;//計算目前的次數
    int high_jump=0;
    int low_jump=0;
    int Case_current=1;
    while(n<Case){
        int Case_numbers;
        int high_arr[50]={11};
        scanf("%d",&Case_numbers);
        for (int i=0;i<Case_numbers;i++){
            scanf("%d",&high_arr[i]);
        }
        for (int j=0;j<Case_numbers;j++){
            if(j>0){
                if(high_arr[j-1]>high_arr[j]){
                    low_jump++;
                }else if(high_arr[j-1]<high_arr[j]){
                    high_jump++;
                }
            }
        }
        printf("Case %d: %d %d\n",Case_current,high_jump,low_jump);
        Case_current++;
        high_jump=0;
        low_jump=0;
        n++;
    }
}