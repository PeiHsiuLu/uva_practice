#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d",&N);
    getchar();
    for(int i=1;i<=N; i++){
        char ch=getchar();
        int degree_alpha=2;
        int degree_digit=3;
        int sum_alpha=0;
        int sum_digit=0;
        int diff=0; //alpha
        while(ch != '\n'){

            if(isalpha(ch)){
                sum_alpha+=int((ch-'A')*pow(26,degree_alpha));
                degree_alpha--;
            }

            if(isdigit(ch)){
                sum_digit+=int((ch-'0')*pow(10,degree_digit));
                degree_digit--;
            }
            ch=getchar();
        }
        diff=abs(sum_alpha-sum_digit);
        if(diff<=100){
            printf("nice\n");
        }else{
            printf("not nice\n");
        }
    }
}
