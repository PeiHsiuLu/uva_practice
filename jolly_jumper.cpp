#include <stdio.h>
#include <stdlib.h>


int main(){
    //宣告變數與輸入數據
    int n;
    while(scanf("%d",&n)==1){
        int arr[n];
        bool seen[n];
        for(int i=0;i<n;i++){
            seen[i]=false;
        }

        //讀取數列資料
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        //計算相鄰差值並標記
        for(int i=1;i<n;i++){
            int diff=abs(arr[i]-arr[i-1]);
            if(diff>=1 && diff<=n){
                seen[diff]=true;
            }else{
                seen[diff]=false;
            }
        }
            //檢查是否有缺漏值
        bool isjump=true;
        for(int i=1;i<n;i++){
            if(seen[i]){
                isjump=true;
            }else{
                isjump=false;
                break;
            }
        }

        //輸出結果
        if(isjump){
            printf("Jolly\n");
        }else{
            printf("Not jolly\n");
        }
    }


}
