#include <stdio.h>

int main(){
    int x;
    int y;
    int field_count=0;
    while(true){
        scanf("%d %d",&x,&y);
        if(x==0 && y==0){
            break;
        }
        char arr[x][y];
        int board[x][y];

        //將方格內的値全部先設為0 並偵測輸入
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                scanf(" %c",&arr[i][j]);
                board[i][j]=0;
            }
        }

        //遍歷每個方格並更新周圍格子
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(arr[i][j]=='*'){
                    //如果是地雷，更新周圍8格
                    for(int dx=-1; dx<=1; dx++){
                        for(int dy=-1; dy<=1; dy++){
                            int ni= i+dx;
                            int nj= j+dy;
                            if(ni>=0 && ni<x && nj>=0 && nj<y && arr[ni][nj]!='*'){
                                board[ni][nj]++;
                            }
                        }
                    }
                }
            }
        }

        //輸出結果
        if(field_count>0){
            printf("\n"); //每個測試案例之間空行
        }
        printf("Field #%d:\n", ++field_count);
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(arr[i][j]=='*'){
                    printf("*");
                }else{
                    printf("%d",board[i][j]);
                }
            }
            printf("\n");
        }

    }
}
