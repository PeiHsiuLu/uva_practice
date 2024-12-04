#include <stdio.h>
#include <math.h>

void sieve(bool *is_prime,int limit){
    //Initialize: pretend every number is prime
    for(int i=0; i<=limit; i++){
        is_prime[i]=true;
    }
    //0 and 1 is not the prime
    is_prime[0]=false;
    is_prime[1]=false;

    //start searching
    for(int i=2;i*i<=limit;i++){
        if(is_prime[i]){
            //將i的倍數設為非質數
            for(int j=i*i;j<=limit;j+=i){
                is_prime[j]=false;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int t=0; t<n; t++){
        long long int low;
        long long int high;
        int count=0;
        scanf("%lld %lld",&low,&high);

        //計算質數
        int limit = (int)sqrt(high);
        bool is_prime[limit+1];
        sieve(is_prime,limit);
        //對每個質數，計算次方
        for(int j=2; j<=limit; j++){
            if(is_prime[j]){
                long long power = (long long) j*j;//從平方開始
                while(power<=high){
                    if(power>=low){
                        count++;
                    }
                    //防止次方溢出
                    if(power> high/j){
                        break;
                    }
                    power*=j;
                }
            }
        }
        printf("%d",count);
    }

}
