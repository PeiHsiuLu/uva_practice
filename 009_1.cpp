#include<stdio.h>
#include <string.h>
int main(){
    char s[15];
    int n=0;
    while(true){
        scanf("%s",s);
        if(strcmp("#",s)==0){
            return 0;
        }
        n++;
        printf("Case %d: ",n);
        if(strcmp(s, "HELLO") == 0){
            printf("ENGLISH");
        }else if(strcmp(s, "HOLA") == 0){
            printf("SPANISH");
        }else if(strcmp(s, "HALLO") == 0){
            printf("GERMAN");
        }else if(strcmp(s, "BONJOUR") == 0){
            printf("FRENCH");
        }else if(strcmp(s, "CIAO") == 0){
            printf("ITALIAN");
        }else if(strcmp(s,"ZDRAVSTVUJTE")==0){
            printf("RUSSIAN");
        }else{
            printf("UNKNOWN");
        }
        printf("\n");
    }

}