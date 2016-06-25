#include <stdio.h>
#include <stdlib.h>
#define Num 5 			//定義環狀佇列大小為5,以及為了方便柱列大小更改而設的常數變數 

void Enqueue();	
void Dequeue();	
void Add();	
void Sub();	
void List();
void Front_item();

int q[Num];
int rear=0;
int front=0;
char choice;
int tag=0; 		//使用改良環狀柱列所產生的變數 

int main(void){
	printf("Enqueue->e,  Dequeue->d,  Add->a,  Sub->s,  List->l,  Front_item->f,  Exit-x\n");
	while(1==1){
		printf("請輸入你選擇的工作：");
		scanf("%s",&choice);
		switch(choice){ 
			case 'e':
				Enqueue();
				break;
			case 'd':
				Dequeue();
				break;
			case 'a':
				Add();
				break;
			case 's':
				Sub();
				break;
			case 'l':
				List();
				break;
			case 'f':
				Front_item();
				break;
			case 'x':
				printf("Bye Bye");
				exit(1);
			default:
				printf("無此代碼,請輸入正確代碼\n");
			} 
	}
	system("pause");
	return 0;
}
void Enqueue(){
	int n;
	if(rear==front && tag==1){	//使用改良型環狀柱列的判斷法則 
		printf("佇列滿了\n");
		return;
	}else{
		rear=(rear+1)%Num;
		printf("請輸入數值：");
		scanf("%d",&n);
		q[rear]=n;
		if(rear==front){tag=1;}
	}
}
void Dequeue(){
	if(front==rear && tag==0){	//使用改良型環狀柱列的判斷法則 
		printf("柱列空了\n");
		return;
	}else{
		front=(front+1)%Num;
		printf("取出的元素為%d\n",q[front]);
		if(front==rear){tag=0;}
	}
}
void Add(void){
	if(((rear==front && tag==1) || (abs(rear-front)>=2) || rear<front) && !(rear==0 && front==4)){
		int tmp; 
		tmp=q[(front+1)%Num]+q[(front+2)%Num];
		front=(front+2)%Num;											//將頭端往後兩位(因提出兩個元素) 
		rear=(rear+1)%Num;												//尾端往後加一個位置(因為要存放相加後的資料) 
		q[rear]=tmp;
	}else{
		printf("資料不足，不能相加\n"); 
	}
}

void Sub(void){
	if(((rear==front && tag==1) || (abs(rear-front)>=2) || rear<front) && !(rear==0 && front==4)){
		int tmp;
		tmp=q[(front+1)%Num]-q[(front+2)%Num];
		front=(front+2)%Num;											//將頭端往後兩位(因提出兩個元素) 
		rear=(rear+1)%Num;												//尾端往後加一個位置(因為要存放相加後的資料) 
		q[rear]=tmp;
	}else{
		printf("資料不足，不能相減\n");	
	}
}

void List(void){
	printf("目前佇列的內容(由Rear至Front)為：");
	if(rear==front){													//判斷頭尾是否相等
		if(tag==1){														//頭尾相等且柱列是滿的 
			printf("%d\t",q[rear]); 
			for(int i=(rear+Num-1)%Num; i!=front; i=(i+Num-1)%Num){		//從尾端的前一個位置開始,印到頭端 
				printf("%d\t", q[i]);
			}	
		}else{															//頭尾相等但柱列是空的
			printf("目前沒有值"); 
		}
	}else{																//佇列非滿的且非空的 
		for(int i=rear; i!=front; i=(i+Num-1)%Num){						//從尾端開始,印到頭端 
			printf("%d\t", q[i]);
		}
	}
	printf("\n");
}
void Front_item(){
	printf("Front端的元素為%d\n",q[(front+1)%Num]);
}
