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
            printf("\n"); //�C�ӮרҤ����Ŧ�
        }
        caseeNo++;

        //��l�Ưx�}
        memset(field,0,sizeof(field));
        memset(result,0,sizeof(result));

        //Ū����J
        for(int i=0; i<n; i++){
            scanf("%s",field[i]);
        }

        //�w�q��V�Ʋ�(8�Ӥ�V)
        int dx[] = {-1,-1,-1,0,1,1,1,0};
        int dy[] = {-1,0,1,1,1,0,-1,-1};


        //�p��a�p��
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(field[i][j]=='*'){
                    //�N�P��8��a�p�ƥ[1
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

        //��X���G
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
