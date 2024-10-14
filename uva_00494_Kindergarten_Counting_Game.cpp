#include <stdio.h>
#include <string.h>
int main(){
    char string[1001];
    int count=0;
    int judge=0;
    while(fgets(string,sizeof(string),stdin)){
        if(string[0]==10){
            break;
        }
        for(int i=0;string[i]!=0;i++){
            if(string[i]>=65&&string[i]<=90 || string[i]>=97&&string[i]<=122){
                if(judge==0){//確保只在單字開頭時加1
                    count++;
                    judge=1;//標誌加入新單詞
                }
            }else{
                //遇到非字母表示單詞結束
                judge=0;
            }
        }
        printf("%d\n",count);
        count=0;
        
    }
}