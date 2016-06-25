#include <stdio.h>
#include <stdlib.h>
int A[7][2] = { {10,7},{5,6},{8,5},{2,4},{6,2},{1,1},{8,0} }; 
int B[7][2] = { {-9,8},{5,7},{7,4},{3,3},{12,2},{1,1},{9,0} };	 

//�s�@�`�I���A 
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
	
	printf("�h����A�G\nA=");
	//�s�@A��C
	for(int i=0;i<7;i++){
		//�إߤ@�ӼȮɥΪ��s�`�I�ðt�m�O����Ŷ� 
		Node *temp=NULL;
		temp=(Node*)malloc(sizeof(Node));
		//�YA��C���Ū��A�h�N�Y���Vtemp(�Ĥ@�Ӹ`�I) 
		if(Afront==NULL && Arear==NULL){
			Afront=temp;
		}else{
		//�YA��C���O�Ū��A�h�N���ڪ��U�@�Ӹ`�I���Vtemp 
			Arear->next=temp;
		}
		
		//��A��C�`�I���e
		temp->coef=A[i][0];
		temp->ext=A[i][1];
		temp->next=NULL;
		//�NA��C���ڲ���ثetemp����m 
		Arear=temp;
		//�NA��C�L�X
		if(Arear->ext >= 2){	 	//�j��G������L�X�Y�ƥH�Φ��� 
			printf("%dX^%d+",Arear->coef,Arear->ext);
		}else if(Arear->ext >= 1){ 	//�P�W�A���Y��������1�ɫh��¦L�XX�@���趵�A���L���� 
			printf("%dX+",Arear->coef); 
		}else{						//�`�ƶ�(Arear->ext == 0)�h�L�X�`�ƧY�i 
			printf("%d\n\n",Arear->coef);
		}
	}
	
	printf("�h����B�G\nB=");
	//�s�@B��C
	for(int i=0;i<7;i++){
		//�إߤ@�ӼȮɥΪ��s�`�I�ðt�m�O����Ŷ� 
		Node *temp=NULL;
		temp=(Node*)malloc(sizeof(Node));
		//�YB��C���Ū��A�h�N�Y���Vtemp(�Ĥ@�Ӹ`�I) 
		if(Bfront==NULL && Brear==NULL){
			Bfront=temp;
		}else{
		//�YB��C���O�Ū��A�h�N���ڪ��U�@�Ӹ`�I���Vtemp 
			Brear->next=temp;
		}
		
		//��B��C�`�I���e
		temp->coef=B[i][0];
		temp->ext=B[i][1];
		temp->next=NULL;
		//�NB��C���ڲ���ثetemp����m 
		Brear=temp;
		//�NB��C�L�X
		if(((abs(i-8))==Brear->ext)){							//abs(i-8)�����o�ثe���ƨȩ̀ǻ���A���ثe�`�I���ƬۦP�ɡA�N�L�X 
			printf("%dX^%d+",Brear->coef,Brear->ext);
		}else if(!((abs(i-8))==Brear->ext) && Brear->ext >= 2){ //��ثe�����o���Ʀb��C�����۵��ɡA�h�̵M�L�X 
			printf("%dX^%d+",Brear->coef,Brear->ext);
		}else if(!((abs(i-8))==Brear->ext) && Brear->ext >= 1){ //�P�W�A���Y��������1�ɫh��¦L�XX�@���趵 
			printf("%dX+",Brear->coef);							//�P�W�A���Y��������0�ɫh��¦L�X�Y�� 
		}else{
			printf("%d\n\n",Brear->coef);
		}
	}
	
	//�إߨ�`�I���O�N��A�PB��C���Y 
	Node *A=Afront;
	Node *B=Bfront;
	printf("�h����C�G\nC=");
	while(A !=NULL || B !=NULL){
		//�إߤ@�ӼȮɥΪ��s�`�I�ðt�m�O����Ŷ� 
		Node *temp=NULL;
		temp=(Node*)malloc(sizeof(Node));
		//�YC��C���Ū��A�h�N�Y���Vtemp(�Ĥ@�Ӹ`�I) 
		if(Cfront==NULL && Crear==NULL){
			Cfront=temp;
		}else{
		//�YC��C���O�Ū��A�h�N���ڪ��U�@�Ӹ`�I���Vtemp 
			Crear->next=temp;
		}
		
		//��C��C�`�I���e
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
		
		//�NC��C���ڲ���ثetemp����m 
		Crear=temp;
		
		//�NC��C�L�X
		if(Crear->ext > 1){								//�YCrear�����Ƥj��1�A�h����L�X 
			printf("%dX^%d+",Crear->coef,Crear->ext);	
		}else if(Crear->ext == 1){						//�YCrear�����Ƶ���1�A�h�u�L�X�Y�ƥH��X 
			printf("%dX+",Crear->coef);
		}else{											//�YCrear������<1�A�h���L�X�Y�� 
			printf("%d",Crear->coef);
		}
	}
	return 0;
}
