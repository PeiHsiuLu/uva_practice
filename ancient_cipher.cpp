#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//比較函數，用於排序頻率陣列
int cmp(const void *a, const void *b){
    return (*(int *)a- *(int *)b);
}
int main(){
    while(true){

        int judge=1;
        char string_1[101]={};
        char string_2[101]={};
        if(scanf("%s",string_1) !=1 || scanf("%s",string_2) !=1){
            break;
        }
        int count_1[26]={};
        int count_2[26]={};
        int len=strlen(string_1);

        //計算每個字母的出現次數
        for(int i=0;i<len;i++){
            count_1[string_1[i]-'A']++;
            count_2[string_2[i]-'A']++;
        }

        //排序頻率陣列
        qsort(count_1, 26, sizeof(int), cmp);
        qsort(count_2, 26, sizeof(int), cmp);

        //比較兩個頻率陣列
        for(int i=0;i<26;i++){
            if(count_1[i]!=count_2[i]){
                judge=0;
                break;
            }
        }
        if(judge==1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
