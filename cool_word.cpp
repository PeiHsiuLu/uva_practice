#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n=1;
    int Case=1;
    while(scanf("%d",&n)==1){
        getchar(); //�M������Ÿ�
        int coolword=0;
        for(int i=0;i<n;i++){
            char str[31];
            int freq[26]={0};
            int count[31]={0}; //�ˬd�����W�v
            scanf("%s",str); //Ū�����
            int len=strlen(str);

            //�p��C�Ӧr�����W�v
            for(int i=0;i<len;i++){
                freq[str[i]-'a']++;
            }

            //�ˬd�W�v�O�_�ߤ@
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

            //�ˬd�O�_����ؤ��P���r��
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
