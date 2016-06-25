#include <stdio.h>
#include <stdlib.h>
int TreeData[11]={7,4,1,5,16,8,11,12,15,9,2};		//建立陣列資料 

typedef struct Node{								//建立節點結構 
	int data=NULL;
	Node *Rnode;
	Node *Lnode;
}node;
void Preorder(node *content);			//建立前序程式 
void Inorder(node *content);			//建立中序程式 
void Postorder(node *content);			//建立後續程式 
int main(void){
	node *root=NULL;					//建立樹根 
	printf("Binary Tree內容：\n");
		for(int i=0;i<=10;i++){                 //列出Binary Tree內容 
			node *temp;							//建立一臨時節點Temp給Current跟root指向資料 
			temp=(node*)malloc(sizeof(node));	//動態配置記憶體 
			if(root==NULL){						//若目前root為空值得話，則將root指向temp 
				root=temp;
			}else{								
				node *current;							//建立一current節點用來當作樹的操作點 
				current=(node*)malloc(sizeof(node));
				current=root;							//每當一個節點完成，就再次重新宣告current等於root 
				while(1==1){
				if(current->data >TreeData[i]){			//當目前內容的值(第一次為root的內容)大於陣列資料時，將current指向左指數 
						if(current->Lnode==NULL){		//若目前左子樹為空的話，則建立節點(將current指向temp，之後再將值填入temp) 
							current->Lnode=temp;		
							break;						 
						}else{
							current=current->Lnode;		//若目前節點有資料的話，則將current繼續左方節點移動 
						}
				}else{
						if(current->Rnode==NULL){		//當目前內容的值(第一次為root的內容)小於陣列資料時，將current指向右指數 
							current->Rnode=temp;		//若目前右子樹為空的話，則建立節點(將current指向temp，之後再將值填入temp) 
							break;
						}else{
							current=current->Rnode;		//若目前節點有資料的話，則將current繼續右方節點移動 
						}
					}	
				}
			}
			temp->data=TreeData[i];						//將temp填入資料，並讓root及current都有資料 
			temp->Lnode=NULL;
			temp->Rnode=NULL;
			printf("[%d] ",TreeData[i]);
		}
		printf("\n\n前序走訪結果\n");
		Preorder(root);									//把樹傳給前序走訪程式 
		printf("\n\n中序走訪結果\n");					
		Inorder(root);									//把樹傳給中序走訪程式 
		printf("\n\n後序走訪結果\n");
		Postorder(root);								//把樹傳給後序走訪程式 
	return 0;
}
void Preorder(node *content){
	if(content !=NULL){							//若目前節點是有資料的話，則印出 
		printf("%d ",content->data);			//先印出樹根 
		Preorder(content->Lnode);				//接著印出左節點的資料 
		Preorder(content->Rnode);				//當左節點資料完全印出時，在印出右節點資料 
	}
}
void Inorder(node *content){
	if(content !=NULL){
		Inorder(content->Lnode);				//先將左節點資料完全印出 
		printf("%d ",content->data);			//接著再將樹根印出 
		Inorder(content->Rnode);				//最後再把右節點資料全數印出 
	}
}
void Postorder(node *content){
	if(content !=NULL){
		Postorder(content->Lnode);				//先將左節點資料印出 
		Postorder(content->Rnode);				//接著再將右節點資料印出 
		printf("%d ",content->data);			//最後再將樹根資料印出 
	}
}
