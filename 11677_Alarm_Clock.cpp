#include <stdio.h>
int main(){
    int H1;
    int M1;
    int H2;
    int M2;
    while(true){
        int count=0;
        int minute=0;
        scanf("%d %d %d %d",&H1,&M1,&H2,&M2);
        if(H1==0&&M1==0&&H2==0&&M2==0){
            return 0;
        }

        if(H1>H2 || (H1==H2)&&(M1>M2)){
            H1++;
            H2+=24;
            minute=(60-M1)+M2;
            count=(H2-H1)*60+minute;
        }else{
            count=(H2-H1)*60+(M2-M1);
        }
        printf("%d\n",count);
    }
}