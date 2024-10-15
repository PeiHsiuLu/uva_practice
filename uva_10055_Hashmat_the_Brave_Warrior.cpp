#include <stdio.h>
#include <stdlib.h>
int main(){
    long long int Hashmat;
    long long int Enemy;
    long long int substraction;
    char input[40];
    while(fgets(input,sizeof(input),stdin)){
        if(input[0]==10){
            return 0;
        }
        sscanf(input,"%lld %lld",&Hashmat,&Enemy);
        substraction = abs(Hashmat-Enemy);
        printf("%lld\n",substraction);
    }
}