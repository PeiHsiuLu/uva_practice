#include <stdio.h>
#include <stdlib.h>


int main(){
    //�ŧi�ܼƻP��J�ƾ�
    int n;
    while(scanf("%d",&n)==1){
        int arr[n];
        bool seen[n];
        for(int i=0;i<n;i++){
            seen[i]=false;
        }

        //Ū���ƦC���
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        //�p��۾F�t�ȨüаO
        for(int i=1;i<n;i++){
            int diff=abs(arr[i]-arr[i-1]);
            if(diff>=1 && diff<=n){
                seen[diff]=true;
            }else{
                seen[diff]=false;
            }
        }
            //�ˬd�O�_���ʺ|��
        bool isjump=true;
        for(int i=1;i<n;i++){
            if(seen[i]){
                isjump=true;
            }else{
                isjump=false;
                break;
            }
        }

        //��X���G
        if(isjump){
            printf("Jolly\n");
        }else{
            printf("Not jolly\n");
        }
    }


}
