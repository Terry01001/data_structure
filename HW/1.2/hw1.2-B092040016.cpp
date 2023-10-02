#include<iostream>

#define max 5000
using namespace std;
void display(int *arr){//輸出結果的函式 ， 傳 一個指標指向array 作為參數 
	int test=0;//test作為判斷第一位數不是 0 的時候，便開始輸出 
	for(int i=0;i<max;i++){
		if(!test && arr[i])
			test = 1;
		if(test)
			cout<<arr[i];		
		
	}
}

void factorial(int *arr,int n){//計算階層的函式(遞迴)，參數為 一個指標指向 array ，以及 n(要乘進每個矩陣 index 的資料) 
	if(!n)
		return;
	int carry=0;//carry用來記錄進位，因為是用矩陣做計算 
	
	for(int i=max-1;i>=0;i--){//計算矩陣每個 index 的資料都乘以 n，然後處理 carry ，得到每個 index 裡都只有一位數  //i for counter
		arr[i]=arr[i]*n+carry;
		carry=arr[i]/10;
		arr[i]=arr[i]%10;
	}
	factorial(arr,n-1);//利用 recursive 的方式去計算階層  n*(n-1)*(n-2)*...*1 
}
int main(){
	int n,i;//n 為算幾階層 ,i for counter 
	
	while(cin>>n && n){//一直輸入 0~50 , 直到輸入 0 結束程式 
		for(i=1;i<=n;i++){
			//初始化矩陣，並都設為 0 
			int *a = new int[max];
			for(int j=0;j<max;j++){a[j]=0;}//j for counter
		
			//先將矩陣裡最右邊的 index 設為 1 去計算階層 
			a[max-1]=1;
			cout<<i<<"!=";
			//計算階層結果並輸出到熒幕上 
			factorial(a,i);
			display(a);
			cout<<endl;
			delete[] a;
		}
		cout<<endl;
	}
	
}

