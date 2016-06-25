#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quickSort(int[], int, int);
int count=0;
int main(void){
	srand( (unsigned)time(NULL)); //亂數種子：目的為讓每次執行之結果都不同 
	int data[10];
	printf("隨機產生之原始資料是：");
	for(int i=0;i<10;i++){
		/*產生亂數並填入陣列data*/ 
		data[i]=((rand()%100)+1)-1;
		printf("%d ",data[i]);
	}
	printf("\n\n\n");
	/*列出第一次比對結果(即原資料)*/
	printf("[PASS %d]=> ",count);
	for(int i=0;i<10;i++){
		printf("[%d] ",data[i]);
	}
	printf("\n");	
	count++;
	/*開始排序，傳欲排序之陣列、最左邊元素索引值及最右邊元素索引值*/
	quickSort(data,0,9);
	printf("\n排序結果：");	
	for(int i=0; i<10 ; i++){	
		printf("%d ",data[i]);
	}
}
void quickSort(int data[], int left, int right) {
	/*若right>left，則對調位置；否則，便跳出排序→即排序完成*/
	if(right>left){
		/*宣告l,r的目的為子集合的最左邊索引及最右邊索引*/
		int l = left + 1;   //+1的目的是不跟自己比 
		int r = right;
		/*宣告中間值*/
		int mid = data[left];
		/*換位子要用的*/
		int temp;
    do{
    	/*找出left跟right*/ 
        while(l < right && data[l] <= mid) l++;
        while(r > left && data[r] > mid) r--; 
        if(l < r){	
		/*如果l<r,則l,r索引的內容互相交換*/ 
          temp = data[l]; 
		data[l] = data[r]; 
		data[r] = temp; 
		/*印出當前排序結果*/
          printf("[PASS %d]=> ",count);
		for(int i=0; i<10 ; i++){		
   			printf("[%d] ",data[i]);	
		}
		printf("\n");						
		count++; 
        }
    }while(l < r);
    /*r<l，data[0]和data[j]互換，以r為基準點分為兩個集合*/
    temp = data[r]; 
		data[r] = data[left]; 
		data[left] = temp;
		
		//印出當前排序結果 
		printf("[PASS %d]=> ",count);
		for(int i=0; i<10 ; i++){	
   			printf("[%d] ",data[i]);
		}
		printf("\n");
		count++; 
		
        quickSort(data,left,r-1); 	//左邊的集合繼續做排序 
        quickSort(data,r+1,right); 	//右邊的集合繼續做排序 
	}
}
