#include <stdio.h>
#include <stdlib.h>
#define Num 5 			//�w�q������C�j�p��5,�H�ά��F��K�W�C�j�p���ӳ]���`���ܼ� 

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
int tag=0; 		//�ϥΧ�}�����W�C�Ҳ��ͪ��ܼ� 

int main(void){
	printf("Enqueue->e,  Dequeue->d,  Add->a,  Sub->s,  List->l,  Front_item->f,  Exit-x\n");
	while(1==1){
		printf("�п�J�A��ܪ��u�@�G");
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
				printf("�L���N�X,�п�J���T�N�X\n");
			} 
	}
	system("pause");
	return 0;
}
void Enqueue(){
	int n;
	if(rear==front && tag==1){	//�ϥΧ�}�������W�C���P�_�k�h 
		printf("��C���F\n");
		return;
	}else{
		rear=(rear+1)%Num;
		printf("�п�J�ƭȡG");
		scanf("%d",&n);
		q[rear]=n;
		if(rear==front){tag=1;}
	}
}
void Dequeue(){
	if(front==rear && tag==0){	//�ϥΧ�}�������W�C���P�_�k�h 
		printf("�W�C�ŤF\n");
		return;
	}else{
		front=(front+1)%Num;
		printf("���X��������%d\n",q[front]);
		if(front==rear){tag=0;}
	}
}
void Add(void){
	if(((rear==front && tag==1) || (abs(rear-front)>=2) || rear<front) && !(rear==0 && front==4)){
		int tmp; 
		tmp=q[(front+1)%Num]+q[(front+2)%Num];
		front=(front+2)%Num;											//�N�Y�ݩ�����(�]���X��Ӥ���) 
		rear=(rear+1)%Num;												//���ݩ���[�@�Ӧ�m(�]���n�s��ۥ[�᪺���) 
		q[rear]=tmp;
	}else{
		printf("��Ƥ����A����ۥ[\n"); 
	}
}

void Sub(void){
	if(((rear==front && tag==1) || (abs(rear-front)>=2) || rear<front) && !(rear==0 && front==4)){
		int tmp;
		tmp=q[(front+1)%Num]-q[(front+2)%Num];
		front=(front+2)%Num;											//�N�Y�ݩ�����(�]���X��Ӥ���) 
		rear=(rear+1)%Num;												//���ݩ���[�@�Ӧ�m(�]���n�s��ۥ[�᪺���) 
		q[rear]=tmp;
	}else{
		printf("��Ƥ����A����۴�\n");	
	}
}

void List(void){
	printf("�ثe��C�����e(��Rear��Front)���G");
	if(rear==front){													//�P�_�Y���O�_�۵�
		if(tag==1){														//�Y���۵��B�W�C�O���� 
			printf("%d\t",q[rear]); 
			for(int i=(rear+Num-1)%Num; i!=front; i=(i+Num-1)%Num){		//�q���ݪ��e�@�Ӧ�m�}�l,�L���Y�� 
				printf("%d\t", q[i]);
			}	
		}else{															//�Y���۵����W�C�O�Ū�
			printf("�ثe�S����"); 
		}
	}else{																//��C�D�����B�D�Ū� 
		for(int i=rear; i!=front; i=(i+Num-1)%Num){						//�q���ݶ}�l,�L���Y�� 
			printf("%d\t", q[i]);
		}
	}
	printf("\n");
}
void Front_item(){
	printf("Front�ݪ�������%d\n",q[(front+1)%Num]);
}
