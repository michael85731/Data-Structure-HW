#include <stdio.h>
#include <stdlib.h>
int TreeData[11]={7,4,1,5,16,8,11,12,15,9,2};		//�إ߰}�C��� 

typedef struct Node{								//�إ߸`�I���c 
	int data=NULL;
	Node *Rnode;
	Node *Lnode;
}node;
void Preorder(node *content);			//�إ߫e�ǵ{�� 
void Inorder(node *content);			//�إߤ��ǵ{�� 
void Postorder(node *content);			//�إ߫���{�� 
int main(void){
	node *root=NULL;					//�إ߾�� 
	printf("Binary Tree���e�G\n");
		for(int i=0;i<=10;i++){                 //�C�XBinary Tree���e 
			node *temp;							//�إߤ@�{�ɸ`�ITemp��Current��root���V��� 
			temp=(node*)malloc(sizeof(node));	//�ʺA�t�m�O���� 
			if(root==NULL){						//�Y�ثeroot���ŭȱo�ܡA�h�Nroot���Vtemp 
				root=temp;
			}else{								
				node *current;							//�إߤ@current�`�I�Ψӷ�@�𪺾ާ@�I 
				current=(node*)malloc(sizeof(node));
				current=root;							//�C��@�Ӹ`�I�����A�N�A�����s�ŧicurrent����root 
				while(1==1){
				if(current->data >TreeData[i]){			//��ثe���e����(�Ĥ@����root�����e)�j��}�C��ƮɡA�Ncurrent���V������ 
						if(current->Lnode==NULL){		//�Y�ثe���l�𬰪Ū��ܡA�h�إ߸`�I(�Ncurrent���Vtemp�A����A�N�ȶ�Jtemp) 
							current->Lnode=temp;		
							break;						 
						}else{
							current=current->Lnode;		//�Y�ثe�`�I����ƪ��ܡA�h�Ncurrent�~�򥪤�`�I���� 
						}
				}else{
						if(current->Rnode==NULL){		//��ثe���e����(�Ĥ@����root�����e)�p��}�C��ƮɡA�Ncurrent���V�k���� 
							current->Rnode=temp;		//�Y�ثe�k�l�𬰪Ū��ܡA�h�إ߸`�I(�Ncurrent���Vtemp�A����A�N�ȶ�Jtemp) 
							break;
						}else{
							current=current->Rnode;		//�Y�ثe�`�I����ƪ��ܡA�h�Ncurrent�~��k��`�I���� 
						}
					}	
				}
			}
			temp->data=TreeData[i];						//�Ntemp��J��ơA����root��current������� 
			temp->Lnode=NULL;
			temp->Rnode=NULL;
			printf("[%d] ",TreeData[i]);
		}
		printf("\n\n�e�Ǩ��X���G\n");
		Preorder(root);									//���ǵ��e�Ǩ��X�{�� 
		printf("\n\n���Ǩ��X���G\n");					
		Inorder(root);									//���ǵ����Ǩ��X�{�� 
		printf("\n\n��Ǩ��X���G\n");
		Postorder(root);								//���ǵ���Ǩ��X�{�� 
	return 0;
}
void Preorder(node *content){
	if(content !=NULL){							//�Y�ثe�`�I�O����ƪ��ܡA�h�L�X 
		printf("%d ",content->data);			//���L�X��� 
		Preorder(content->Lnode);				//���ۦL�X���`�I����� 
		Preorder(content->Rnode);				//���`�I��Ƨ����L�X�ɡA�b�L�X�k�`�I��� 
	}
}
void Inorder(node *content){
	if(content !=NULL){
		Inorder(content->Lnode);				//���N���`�I��Ƨ����L�X 
		printf("%d ",content->data);			//���ۦA�N��ڦL�X 
		Inorder(content->Rnode);				//�̫�A��k�`�I��ƥ��ƦL�X 
	}
}
void Postorder(node *content){
	if(content !=NULL){
		Postorder(content->Lnode);				//���N���`�I��ƦL�X 
		Postorder(content->Rnode);				//���ۦA�N�k�`�I��ƦL�X 
		printf("%d ",content->data);			//�̫�A�N��ڸ�ƦL�X 
	}
}
