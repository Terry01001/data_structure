#include<iostream>

#define max 5000
using namespace std;
void display(int *arr){//��X���G���禡 �A �� �@�ӫ��Ы��Varray �@���Ѽ� 
	int test=0;//test�@���P�_�Ĥ@��Ƥ��O 0 ���ɭԡA�K�}�l��X 
	for(int i=0;i<max;i++){
		if(!test && arr[i])
			test = 1;
		if(test)
			cout<<arr[i];		
		
	}
}

void factorial(int *arr,int n){//�p�ⶥ�h���禡(���j)�A�ѼƬ� �@�ӫ��Ы��V array �A�H�� n(�n���i�C�ӯx�} index �����) 
	if(!n)
		return;
	int carry=0;//carry�ΨӰO���i��A�]���O�ίx�}���p�� 
	
	for(int i=max-1;i>=0;i--){//�p��x�}�C�� index ����Ƴ����H n�A�M��B�z carry �A�o��C�� index �̳��u���@���  //i for counter
		arr[i]=arr[i]*n+carry;
		carry=arr[i]/10;
		arr[i]=arr[i]%10;
	}
	factorial(arr,n-1);//�Q�� recursive ���覡�h�p�ⶥ�h  n*(n-1)*(n-2)*...*1 
}
int main(){
	int n,i;//n ����X���h ,i for counter 
	
	while(cin>>n && n){//�@����J 0~50 , �����J 0 �����{�� 
		for(i=1;i<=n;i++){
			//��l�Ưx�}�A�ó��]�� 0 
			int *a = new int[max];
			for(int j=0;j<max;j++){a[j]=0;}//j for counter
		
			//���N�x�}�̳̥k�䪺 index �]�� 1 �h�p�ⶥ�h 
			a[max-1]=1;
			cout<<i<<"!=";
			//�p�ⶥ�h���G�ÿ�X�캷���W 
			factorial(a,i);
			display(a);
			cout<<endl;
			delete[] a;
		}
		cout<<endl;
	}
	
}

