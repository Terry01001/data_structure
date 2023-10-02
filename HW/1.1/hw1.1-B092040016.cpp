#include<iostream>

using namespace std;

void magic_square(int n); //���]��}���禡 �ǴX���]n�^�@���Ѽ� 

int main(){
	int n;//�ܼ� n �@���X�� �Q�ΰj�� �]�@����s�[�G�^ �]�X 1�B3�B5�B7�B9 �����]��} 
	for(n=1;n<=9;n+=2){
		magic_square(n); 
	}
}

void magic_square(int n){
	
	int arr[n][n];//arr �@���s���]��}���G���}�C 
	int i,j;//variables i , j for counter 
	
	for(i=0;i<n;i++){//��l�ư}�C�]���]�� 0�^ 
		for(j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	
	int row = 0,col = n/2;//row �B col �@���}�C�̪� index ,�ê�l�Ƴ]�� �̤W�� row �������B�]row=0 col=n/2�^ 
	int k;//k �@���n�s��i�h�}�C�̪��� 
	
	arr[row][col]=1;//�̤W�� row �������B ���]�� 1 
	
	for(k=2;k<=n*n;k++){
		//�U�@�ӼƦr��b(row-1,col-1)����m 
		row-=1;
		col-=1;
		//��}���W�U�����۳s�A���k�������۳s
		if(row<0)
			row+=n;
		if(col<0)
			col+=n;
		
		if(arr[row][col]==0){//�Y�Ӧ�m�|����J��ƫh��J 
			arr[row][col]=k;
		}
		else{//�Y�Ӧ�m�w����ƤF�A�h����b�]row+1,col�^��m  �]�W�@����Ʀb�]row,col�^�^ 
			row+=1;
			col+=1;
			if(row>=n)
				row-=n;
			if(col>=n)
				col-=n;
			
			row+=1;
			
			arr[row][col]=k;
			
		}
	}
	//�̫�榡�ƦL�X�]��} 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%2d ",arr[i][j]);
		}	
		cout<<endl;
	}
	cout<<endl;
}
