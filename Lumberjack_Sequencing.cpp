#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int nums_arr[10];
    int count=0;
    int nums_arr_judge[9];
    printf("Lumberjacks:\n");
    while(count<N){
        for(int i=0;i<10;i++){
            scanf("%d",&nums_arr[i]);
            if(i==0){
                continue;
            }else if(nums_arr[i]>nums_arr[i-1]){
                nums_arr_judge[i-1]=1;
            }else{
                nums_arr_judge[i-1]=0;
            }
        }
        for(int j=1;j<9;j++){
            if(nums_arr_judge[j]!=nums_arr_judge[j-1]){
                printf("Unordered\n");
                break;
            }else{
                if(j==8){
                    printf("Ordered\n");
                }else{
                    continue;
                }
            }
        }
        count++;
    }
}
