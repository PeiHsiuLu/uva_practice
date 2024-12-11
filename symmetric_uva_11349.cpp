#include <stdio.h>
#include <string.h>
int main(){
    int T=0;
    scanf("%d",&T);
    for(int Case=1;Case<=T;Case++){
        int N=0;
        int judge=1; //判斷是否對稱
        scanf(" N = %d",&N);
        long long int arr[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%lld",&arr[i][j]);
                if(arr[i][j]<0){
                    judge=0;
                }
            }
        }
        //檢查對稱性
        for(int i=0;i<N && judge;i++){
            for(int j=0;j<N && judge;j++){
                if(arr[i][j] != arr[N-1-i][N-1-j]){
                    judge=0;
                }
            }
        }

        printf("Test #%d: ",Case);
        if(judge){
            printf("Symmetric.\n");
        }else{
            printf("Non-symmetric.\n");
        }
    }


}
