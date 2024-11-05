#include <stdio.h>
#include <string.h>

#define Max_LEN 21

//定義鏡像對照表
char mirror_map[128];

void init_mirror_map(){
    memset(mirror_map,0,sizeof(mirror_map));
    mirror_map['A']='A';
    mirror_map['E']='3';
    mirror_map['H']='H';
    mirror_map['I']='I';
    mirror_map['J']='L';
    mirror_map['L']='J';
    mirror_map['M']='M';
    mirror_map['O']='O';
    mirror_map['S']='2';
    mirror_map['T']='T';
    mirror_map['U']='U';
    mirror_map['V']='V';
    mirror_map['W']='W';
    mirror_map['X']='X';
    mirror_map['Y']='Y';
    mirror_map['Z']='5';
    mirror_map['1']='1';
    mirror_map['2']='S';
    mirror_map['3']='E';
    mirror_map['5']='Z';
    mirror_map['8']='8';
}

int main(){
    char string[Max_LEN];
    int length; //陣列長度
    int mirror_judge;
    int palindrome_judge;
    init_mirror_map();
    while(fgets(string,sizeof(string),stdin)){
        if(string[0]==10){
            break;
        }
        //移除換行符號
        length=strlen(string);
        if(string[length-1]=='\n'){
            string[length-1]='\0';
            length--;
        }

        mirror_judge=1;
        palindrome_judge=1;
        for(int i=0;i<=(length)/2;i++){
            char left= string[i];
            char right=string[length-i-1];

            //回文判斷
            if(left!=right){
                palindrome_judge=0;
            }

            //鏡像判斷
            if(mirror_map[(int)left]==0 || mirror_map[(int)left]!=right){
                mirror_judge=0;
            }

            //如果鏡像判斷和回文判斷後的值皆是0，則立刻跳出迴圈
            if(palindrome_judge==0 && mirror_judge==0){
                break;
            }

        }

        if(palindrome_judge==0&&mirror_judge==0){
            printf("%s -- is not a palindrome.\n\n",string);
        }else if(palindrome_judge==1&&mirror_judge==0){
            printf("%s -- is a regular palindrome.\n\n",string);
        }else if(palindrome_judge==0&&mirror_judge==1){
            printf("%s -- is a mirrored string.\n\n",string);
        }else{
            printf("%s -- is a mirrored palindrome.\n\n",string);
        }
}
}

