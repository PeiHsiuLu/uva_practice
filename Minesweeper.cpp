#include <stdio.h>
#include <string.h>

#define MAX 100
int main(){
    int m=0;
    int n=0;
    int caseeNo=0;
    char field[MAX][MAX];
    int  result[MAX][MAX];
    while(true){
        scanf("%d %d",&n,&m);
        if(m==0 && n==0){
            break;
        }

        if(caseeNo>0){
            printf("\n"); //每個案例之間空行
        }
        caseeNo++;

        //初始化矩陣
        memset(field,0,sizeof(field));
        memset(result,0,sizeof(result));

        //讀取輸入
        for(int i=0; i<n; i++){
            scanf("%s",field[i]);
        }

        //定義方向數組(8個方向)
        int dx[] = {-1,-1,-1,0,1,1,1,0};
        int dy[] = {-1,0,1,1,1,0,-1,-1};


        //計算地雷數
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(field[i][j]=='*'){
                    //將周圍8格地雷數加1
                    for(int k=0; k<8; k++){
                        int x= i+dx[k];
                        int y= j+dy[k];
                        if(x>=0 && x<n && y>=0 && y<m && field[x][y] != '*'){
                            result[x][y]++;
                        }
                    }
                }
            }
        }

        //輸出結果
        printf("Field #%d:\n",caseeNo);
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                if(field[i][j]=='*'){
                    printf("*");
                }else{
                    printf("%d",result[i][j]);
                }
            }
            printf("\n");
        }
    }

}
