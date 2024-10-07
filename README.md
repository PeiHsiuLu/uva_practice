# uva_practice

# Daily Practice

## 10/06  Google is Feeling Lucky
**學習重點**  
- 陣列的儲存
- 字串的運用

**字串宣告**
```C++
char 字串[字串長度]
```

**陣列的寫法**  
```C++
type arrayName[arraySize]; //陣列的長度
type arrayName[arraySize][eachvaluesize]; //陣列的長度，以及每一個元素可容納的字符長度
```

**陣列元素值儲存**  
```C++
array[從0開始的索引值] = 賦予的值
```

**strcpy**  
在 <string.h> 標頭檔底下的標準庫函數，可以將一段字串複製到另一段字串。  
```C++
strcpy("字串2","字串1") //將字串1複製到字串2內
```


**解題思路**  
step 1: 用 while 迴圈包起來  
step 2: 先利用 for 迴圈將字串與數字各自儲存入數字陣列 or 字串陣列  
step 3: 用 if 判斷最大值，時刻更新  
step 4: 再用一個 for 迴圈抓取數字陣列中的索引值，如果等於 max 值，則輸出對應的字串索引值  
step 5: 依此類推，持續下去到所有的Case跑完。  

**程式碼如下：**  
```C++
#include <stdio.h>
#include <string.h>
int main(){
    int Case;
    scanf("%d",&Case);
    int n=0;
    char net_arr[10][101]; //net array
    int num_arr[10]; //number array
    while(n<Case){
        int max=0;
        for(int i=0;i<10;i++){
            int relative;
            char net[101];
            scanf("%s %d",net,&relative);
            strcpy(net_arr[i],net);
            num_arr[i]=relative;
            if(relative>max){
                max = relative;
            }
        }
        n++;
        printf("Case #%d:\n",n);
        for(int j=0;j<10;j++){
            if(num_arr[j]==max){
                printf("%s\n",net_arr[j]);
            }
        }
        
    }
    
    return 0;
}
```

## 10/07 Parity 
**學習重點**  
- 尋找陣列長度：sizeof(arr)/sizeof(arr[0])  
- 2的31次方(32位元)：2147483648
**解題思路**  
step 1: 先設置一個涵蓋32個數值的數字陣列  
step 2: 設置一個 while 迴圈將所有的程式碼包覆其中
step 3: 設置 if 判斷，若整數為 0 ，則立即中止所有的運算
step 4: 用 for 迴圈從 30 開始遞減計算(因為最大數值是 2147483647 ，僅涵31位元。)(然後記得要設定 #include <math.h> 的標頭檔，才能進行 pow 的計算)
step 5: 判斷整數減去2的次方數是否>=0，有則設為1(並將sum值+1)，將整數值減去 2 的次方數；沒有的話則設為0，整數維持原樣(但如果 num_arr[0] 不為 1 則用 else if 跳過。)
step 6: 用 for 迴圈輸出陣列中的數值

**程式碼如下：**  
```C++
#include <stdio.h>
#include <math.h>
int main(){
    int num_arr[31];
    while(true){
        num_arr[0]=0;
        int n=0;
        int integer;
        scanf("%d",&integer);
        int sum=0;
        int calculation=integer;
        if(integer == 0){
            return 0;
        }
        for(int i=30;i>=0;i--){
            if(calculation-pow(2,i)>=0){
                calculation=calculation-pow(2,i);
                num_arr[n]=1;
                sum+=1;
                n++;
            }else if(num_arr[0]!=1){
                continue;
            }else{
                num_arr[n]=0;
                n++;
            }
        }
        int size_len = sizeof(num_arr)/sizeof(num_arr[0]);
        printf("The parity of ");
        for(int j=0;j<n;j++){
            printf("%d",num_arr[j]);
        }
        printf(" is %d (mod 2).\n",sum);
    }

}
```
