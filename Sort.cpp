#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quickSort(int[], int, int);
int count=0;
int main(void){
	srand( (unsigned)time(NULL)); //�üƺؤl�G�ت������C�����椧���G�����P 
	int data[10];
	printf("�H�����ͤ���l��ƬO�G");
	for(int i=0;i<10;i++){
		/*���Ͷüƨö�J�}�Cdata*/ 
		data[i]=((rand()%100)+1)-1;
		printf("%d ",data[i]);
	}
	printf("\n\n\n");
	/*�C�X�Ĥ@����ﵲ�G(�Y����)*/
	printf("[PASS %d]=> ",count);
	for(int i=0;i<10;i++){
		printf("[%d] ",data[i]);
	}
	printf("\n");	
	count++;
	/*�}�l�ƧǡA�Ǳ��ƧǤ��}�C�B�̥��䤸�����ޭȤγ̥k�䤸�����ޭ�*/
	quickSort(data,0,9);
	printf("\n�Ƨǵ��G�G");	
	for(int i=0; i<10 ; i++){	
		printf("%d ",data[i]);
	}
}
void quickSort(int data[], int left, int right) {
	/*�Yright>left�A�h��զ�m�F�_�h�A�K���X�Ƨǡ��Y�Ƨǧ���*/
	if(right>left){
		/*�ŧil,r���ت����l���X���̥�����ޤγ̥k�����*/
		int l = left + 1;   //+1���ت��O����ۤv�� 
		int r = right;
		/*�ŧi������*/
		int mid = data[left];
		/*����l�n�Ϊ�*/
		int temp;
    do{
    	/*��Xleft��right*/ 
        while(l < right && data[l] <= mid) l++;
        while(r > left && data[r] > mid) r--; 
        if(l < r){	
		/*�p�Gl<r,�hl,r���ު����e���ۥ洫*/ 
          temp = data[l]; 
		data[l] = data[r]; 
		data[r] = temp; 
		/*�L�X��e�Ƨǵ��G*/
          printf("[PASS %d]=> ",count);
		for(int i=0; i<10 ; i++){		
   			printf("[%d] ",data[i]);	
		}
		printf("\n");						
		count++; 
        }
    }while(l < r);
    /*r<l�Adata[0]�Mdata[j]�����A�Hr������I������Ӷ��X*/
    temp = data[r]; 
		data[r] = data[left]; 
		data[left] = temp;
		
		//�L�X��e�Ƨǵ��G 
		printf("[PASS %d]=> ",count);
		for(int i=0; i<10 ; i++){	
   			printf("[%d] ",data[i]);
		}
		printf("\n");
		count++; 
		
        quickSort(data,left,r-1); 	//���䪺���X�~�򰵱Ƨ� 
        quickSort(data,r+1,right); 	//�k�䪺���X�~�򰵱Ƨ� 
	}
}
