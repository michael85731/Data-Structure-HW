#include <stdio.h>
#include <stdlib.h>
int A[7][2] = { {10,7},{5,6},{8,5},{2,4},{6,2},{1,1},{8,0} }; 
int B[7][2] = { {-9,8},{5,7},{7,4},{3,3},{12,2},{1,1},{9,0} };	 

//製作節點型態 
typedef struct node{
	int coef;
	int ext;
	node *next;
}Node;

int main(void){
	Node *Afront=NULL;
	Node *Arear=NULL;
	Node *Bfront=NULL;
	Node *Brear=NULL;
	Node *Cfront=NULL;
	Node *Crear=NULL;
	
	printf("多項式A：\nA=");
	//製作A串列
	for(int i=0;i<7;i++){
		//建立一個暫時用的新節點並配置記憶體空間 
		Node *temp=NULL;
		temp=(Node*)malloc(sizeof(Node));
		//若A串列為空的，則將頭指向temp(第一個節點) 
		if(Afront==NULL && Arear==NULL){
			Afront=temp;
		}else{
		//若A串列不是空的，則將尾巴的下一個節點指向temp 
			Arear->next=temp;
		}
		
		//給A串列節點內容
		temp->coef=A[i][0];
		temp->ext=A[i][1];
		temp->next=NULL;
		//將A串列尾巴移到目前temp的位置 
		Arear=temp;
		//將A串列印出
		if(Arear->ext >= 2){	 	//大於二次次方印出係數以及次方 
			printf("%dX^%d+",Arear->coef,Arear->ext);
		}else if(Arear->ext >= 1){ 	//同上，但若像次等於1時則單純印出X一次方項，不印次方 
			printf("%dX+",Arear->coef); 
		}else{						//常數項(Arear->ext == 0)則印出常數即可 
			printf("%d\n\n",Arear->coef);
		}
	}
	
	printf("多項式B：\nB=");
	//製作B串列
	for(int i=0;i<7;i++){
		//建立一個暫時用的新節點並配置記憶體空間 
		Node *temp=NULL;
		temp=(Node*)malloc(sizeof(Node));
		//若B串列為空的，則將頭指向temp(第一個節點) 
		if(Bfront==NULL && Brear==NULL){
			Bfront=temp;
		}else{
		//若B串列不是空的，則將尾巴的下一個節點指向temp 
			Brear->next=temp;
		}
		
		//給B串列節點內容
		temp->coef=B[i][0];
		temp->ext=B[i][1];
		temp->next=NULL;
		//將B串列尾巴移到目前temp的位置 
		Brear=temp;
		//將B串列印出
		if(((abs(i-8))==Brear->ext)){							//abs(i-8)為取得目前指數並依序遞減，當跟目前節點次數相同時，就印出 
			printf("%dX^%d+",Brear->coef,Brear->ext);
		}else if(!((abs(i-8))==Brear->ext) && Brear->ext >= 2){ //當目前欲取得次數在串列內不相等時，則依然印出 
			printf("%dX^%d+",Brear->coef,Brear->ext);
		}else if(!((abs(i-8))==Brear->ext) && Brear->ext >= 1){ //同上，但若像次等於1時則單純印出X一次方項 
			printf("%dX+",Brear->coef);							//同上，但若像次等於0時則單純印出係數 
		}else{
			printf("%d\n\n",Brear->coef);
		}
	}
	
	//建立兩節點分別代表A與B串列的頭 
	Node *A=Afront;
	Node *B=Bfront;
	printf("多項式C：\nC=");
	while(A !=NULL || B !=NULL){
		//建立一個暫時用的新節點並配置記憶體空間 
		Node *temp=NULL;
		temp=(Node*)malloc(sizeof(Node));
		//若C串列為空的，則將頭指向temp(第一個節點) 
		if(Cfront==NULL && Crear==NULL){
			Cfront=temp;
		}else{
		//若C串列不是空的，則將尾巴的下一個節點指向temp 
			Crear->next=temp;
		}
		
		//給C串列節點內容
		if(A->ext==B->ext){
			temp->coef=A->coef+B->coef;
			temp->ext=A->ext;
			temp->next=NULL;
			A=A->next;
			B=B->next;
		}else if(A->ext > B->ext){
			temp->coef=A->coef;
			temp->ext=A->ext;
			temp->next=NULL;
			A=A->next;
		}else{
			temp->coef=B->coef;
			temp->ext=B->ext;
			temp->next=NULL;
			B=B->next;
		}
		
		//將C串列尾巴移到目前temp的位置 
		Crear=temp;
		
		//將C串列印出
		if(Crear->ext > 1){								//若Crear的指數大於1，則完整印出 
			printf("%dX^%d+",Crear->coef,Crear->ext);	
		}else if(Crear->ext == 1){						//若Crear的指數等於1，則只印出係數以及X 
			printf("%dX+",Crear->coef);
		}else{											//若Crear的指數<1，則指印出係數 
			printf("%d",Crear->coef);
		}
	}
	return 0;
}
