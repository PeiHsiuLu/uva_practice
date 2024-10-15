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

## 10/09 Language Detection
**學習重點**  
- 字串相等使用方法:strcmp()
**strcmp()**
  這是一個在<string.h>底下的標準函式庫，若是兩字串相等則會返還一個 0 ，不相等則返回非零值。
  使用方式：
  ```C++
  strcmp(word1, word2) == 0
  ```
  用逗號而不是==隔開，因為==是比較指針位置，而非字串內容，所以若是想要比較兩字串，得使用逗號隔開。
  strcmp也是找相等字串的標準方式

**解題程式碼**  
```C++
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
```

## 10/12 11677 Alarm Clock
### 解題程式碼  
```C++
#include <stdio.h>
int main(){
    int H1; //開始小時  
    int M1; //開始分鐘  
    int H2; //結束小時  
    int M2; //結束分鐘  
    while(true){
        int count=0;
        int minute=0;
        scanf("%d %d %d %d",&H1,&M1,&H2,&M2);
        if(H1==0&&M1==0&&H2==0&&M2==0){
            return 0;
        }

        if(H1>H2 || ((H1==H2)&&(M1>M2))){
            H1++;
            H2+=24;
            minute=(60-M1)+M2;
            count=(H2-H1)*60+minute;
        }else{
            count=(H2-H1)*60+(M2-M1);
        }
        printf("%d\n",count);
    }
}
```
### 解題思路
考慮兩種情形：一種是開始時間<=結束時間(也就是今天的意思)；一種是開始時間>結束時間(橫跨到隔天)  
用 if condition & while condition 來破題:  

while 迴圈持續下去，直到 H1 H2 M1 M2 同時都是 0 為止。  

**今天的解法**  
(結束小時 - 開始小時)*60+(結束分鐘 - 開始分鐘)  
**跨天的解法**  
60 - 開始的分鐘數，並將開始小時+1。結束小時+24(因為跨到隔天)  
之後再計算總分鐘數(結束小時 - 開始小時)*60+(結束分鐘 - 開始分鐘)  

## 10/13 12019 - Doom's Day Algorithm
### 解題思路
1. 計算日期到1月1日距離多少天，因為1月1日是星期六，所以計算總天數時要先-1再+6。  
2. 位於2月以後的日期需要加上經過幾個月的天數，例如：3月必須加上1月到2月的天數(即31+28)  
3. 之後再單獨加上目前的天(day)
4. 用陣列儲存日期的天數，有需要時再使用for迴圈加起來
### 解題程式碼  
```C++
#include <stdio.h>

int main(){
    //2011年1月1日是禮拜六
    int M;
    int D;
    int month_array[11]={31,28,31,30,31,30,31,31,30,31,30};//從1月到11月，因為12月基本上不會被計算到，所以不用記錄到12月
    int Case;
    int weekday;
    scanf("%d",&Case);
    int n=1;
    while(n<=Case){
        int count=0;
        scanf("%d %d",&M,&D);
        count+=(D+6-1);//距離1月1日多少天，且1月1日是禮拜六，所以要 +6
        if(M>1){
            for(int i=0;i<M-1;i++){
                count+=month_array[i];
            }
        }
        weekday = count%7;
        switch(weekday){
            case 1:
                printf("Monday");
                break;
            case 2:
                printf("Tuesday");
                break;
            case 3:
                printf("Wednesday");
                break;
            case 4:
                printf("Thursday");
                break;
            case 5:
                printf("Friday");
                break;
            case 6:
                printf("Saturday");
                break;
            case 0:
                printf("Sunday");
                break;
        }
        printf("\n");
        n++;
    }


    return 0;
}
```
## 10/14 00494 - Kindergarten Counting Game
### 學習重點
- ASCll number (from 'a' to 'z', from 'A' to 'Z')
- fgets: 獲取完整的 string
#### ASCll number
**Uppercase Letters (A-Z)**  
| Character | ASCII Value |
|-----------|-------------|
| A         | 65          |
| B         | 66          |
| C         | 67          |
| D         | 68          |
| E         | 69          |
| F         | 70          |
| G         | 71          |
| H         | 72          |
| I         | 73          |
| J         | 74          |
| K         | 75          |
| L         | 76          |
| M         | 77          |
| N         | 78          |
| O         | 79          |
| P         | 80          |
| Q         | 81          |
| R         | 82          |
| S         | 83          |
| T         | 84          |
| U         | 85          |
| V         | 86          |
| W         | 87          |
| X         | 88          |
| Y         | 89          |
| Z         | 90          |

**Lowercase Letters (a-z)**  
| Character | ASCII Value |
|-----------|-------------|
| a         | 97          |
| b         | 98          |
| c         | 99          |
| d         | 100         |
| e         | 101         |
| f         | 102         |
| g         | 103         |
| h         | 104         |
| i         | 105         |
| j         | 106         |
| k         | 107         |
| l         | 108         |
| m         | 109         |
| n         | 110         |
| o         | 111         |
| p         | 112         |
| q         | 113         |
| r         | 114         |
| s         | 115         |
| t         | 116         |
| u         | 117         |
| v         | 118         |
| w         | 119         |
| x         | 120         |
| y         | 121         |
| z         | 122         |

**Others**  

| Character | ASCII Value |
|-----------|-------------|
|\n         |10           |
|(結束)     |0           |

**fgets**  
fgets主要的作用是用來抓取完整的字串，每個字串中的字符都會被儲存在一個陣列內  
fgets(字串變數名,sizeof(字串變數),stdin)  
#### 解題思路
- 因為是要尋找連續的單字，所以用if判斷句判斷二十六個字母大小寫的ASCll number 的值
- 非二十六個字母的符號可以被視為空格，空格則終止字母連續
- 用fgets抓取連續文字，每個文字都會被視為一個陣列中的值，抓到空格則停止連續
#### 解題程式碼  
```C++
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
```
## 10/15 10055 - Hashmat the Brave Warrior
### 學習重點
- 儲存較大的資料型態
- 在儲存整數資料時，如何中止輸入

#### 儲存較大的資料型態
儲存較大的資料型態，像是整數的時候，我們必須使用 long 這個變數。  
像是64位元、32位元。  
以下是常見的整數型態：  
| 型態        | 大小 (位元組) | 數值範圍                                               |位元     |
|-------------|--------------|-------------------------------------------------------|---------|
| int         | 4 bytes      | -2,147,483,648 到 2,147,483,647                        |32位元   |
| long int    | 4 or 8 bytes | 依系統而異 (通常和 int 相同或更大)                       |32 or 64位元|
|long long int| 8 bytes      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807|64位元   |  
#### 如何讓整數停止輸入？  
1. 先利用 fgets 抓取字串，再利用 sscanf 將字串轉為儲存整數
2. 利用fgets抓到的ASCLL number: 10(Enter \n)，用 if condition 判斷，若是符合則 return 0。(只能夠用 fgets 抓到的字串進行判斷，scanf會自動跳過空白或是換行符。)

```C++
sscanf(字串變數名,"%d",想儲存的整數)
