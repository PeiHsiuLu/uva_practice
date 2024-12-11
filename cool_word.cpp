#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n=1;
    int Case=1;
    while(scanf("%d",&n)==1){
        getchar(); //清除換行符號
        int coolword=0;
        for(int i=0;i<n;i++){
            char str[31];
            int freq[26]={0};
            int count[31]={0}; //檢查重複頻率
            scanf("%s",str); //讀取單詞
            int len=strlen(str);

            //計算每個字母的頻率
            for(int i=0;i<len;i++){
                freq[str[i]-'a']++;
            }

            //檢查頻率是否唯一
            int cool=1;
            for(int i=0; i<26; i++){
                if(freq[i]>0){
                    if(count[freq[i]]>0){
                        cool=0;
                        break;
                    }
                    count[freq[i]]++;
                }
            }

            //檢查是否有兩種不同的字母
            int uniqueLetters=0;
            for(int i=0; i<26; i++){
                if(freq[i]>0){
                    uniqueLetters++;
                }
            }

            if(uniqueLetters<2){
                cool=0;
            }

            if(cool){
                coolword++;
            }

        }
        printf("Case %d: %d\n",Case++,coolword);
    }
}
