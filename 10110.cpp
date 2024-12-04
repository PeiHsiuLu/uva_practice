#include <stdio.h>
#include <math.h>
int main(){
    long long int number=-1;
    while(true){
        scanf("%lld",&number);
        if(number==0){
            return 0;
        }
        long long int root = (long long int)sqrt(number);
        if(root*root==number){
            printf("yes\n");
        }else{
            printf("no\n");
        }

    }
}
