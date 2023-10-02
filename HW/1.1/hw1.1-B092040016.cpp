#include<iostream>

using namespace std;

void magic_square(int n); //做魔方陣的函式 傳幾階（n）作為參數 

int main(){
	int n;//變數 n 作為幾階 利用迴圈 （一次更新加二） 跑出 1、3、5、7、9 階的魔方陣 
	for(n=1;n<=9;n+=2){
		magic_square(n); 
	}
}

void magic_square(int n){
	
	int arr[n][n];//arr 作為存放魔方陣的二維陣列 
	int i,j;//variables i , j for counter 
	
	for(i=0;i<n;i++){//初始化陣列（都設為 0） 
		for(j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	
	int row = 0,col = n/2;//row 、 col 作為陣列裡的 index ,並初始化設為 最上面 row 的中間處（row=0 col=n/2） 
	int k;//k 作為要存放進去陣列裡的數 
	
	arr[row][col]=1;//最上面 row 的中間處 先設為 1 
	
	for(k=2;k<=n*n;k++){
		//下一個數字放在(row-1,col-1)的位置 
		row-=1;
		col-=1;
		//方陣的上下環狀相連，左右亦環狀相連
		if(row<0)
			row+=n;
		if(col<0)
			col+=n;
		
		if(arr[row][col]==0){//若該位置尚未放入資料則放入 
			arr[row][col]=k;
		}
		else{//若該位置已有資料了，則應放在（row+1,col）位置  （上一筆資料在（row,col）） 
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
	//最後格式化印出魔方陣 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%2d ",arr[i][j]);
		}	
		cout<<endl;
	}
	cout<<endl;
}
