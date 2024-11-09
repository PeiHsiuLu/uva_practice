#include <stdio.h>

int main(){
    char str_num[6];
    int N;
    int R;
    int survive_id;
    int judge=0;
    while(scanf("%d %d",&N,&R)==2){
        judge=N-R;
        int divers[N]={0};
        for(int i=0;i<R; i++){
            scanf("%d",&survive_id);
            divers[survive_id-1]=survive_id;
        }
        if(judge>0){
            for(int i=0;i<N;i++){
                if(divers[i]==0){
                    divers[i]=i+1;
                    printf("%d ",divers[i]);
                }
            }
        }else{
            printf("*");
        }
        printf("\n");
    }
}
