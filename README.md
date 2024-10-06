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
