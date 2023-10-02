
#include<iostream>
using namespace std;

int i,j;//array index
int noSolution;//test if it has solution
int dir;//direction
int counter3;//counter


void movement(int num){
	switch(num){
		case 1://move of K1
			i-=2;
			j+=1;
			break;
		case 2://move of K2
			i-=1;
			j+=2;
			break;
		case 3://move of K3
			i+=1;
			j+=2;
			break;
		case 4://move of K4
			i+=2;
			j+=1;
			break;
		case 5://move of K5
			i+=2;
			j-=1;
			break;
		case 6://move of K6
			i+=1;
			j-=2;
			break;
		case 7://move of K7
			i-=1;
			j-=2;
			break;
		case 8://move of K8
			i-=2;
			j-=1;
			break;
		
		case -1://reverse move of K1 
			i+=2;
			j-=1;
			break;
		case -2://reverse move of K2
			i+=1;
			j-=2;
			break;
		case -3://reverse move of K3
			i-=1;
			j-=2;
			break;
		case -4://reverse move of K4
			i-=2;
			j-=1;
			break;
		case -5://reverse move of K5
			i-=2;
			j+=1;
			break;
		case -6://reverse move of K6
			i-=1;
			j+=2;
			break;
		case -7://reverse move of K7
			i+=1;
			j+=2;
			break;
		case -8://reverse move of K8
			i+=2;
			j+=1;
			break;
	}
}

//find way to move
void move(int n , int **arr,int path[]){//passing the size n and the array of the size n*n (chessboard) and the path that records thekinghts passed by 
	if(dir<=8) movement(dir);
	
	while((i<0||i>=n||j<0||j>=n||arr[i][j]!=0)&&dir<=8){//find the dirction that knight can move
		movement(-dir);
		dir++;
		if(dir<=8) movement(dir);
	}
	
	if(dir<=8){//put the value of this move into array and path
		arr[i][j]=counter3;
		path[counter3-2]=dir;
		dir=1;//try direction1 for the next round
		counter3++;
		
	}
	else if(counter3>2 && dir==9){//go back to the last position and try another direction to move
		arr[i][j]=0;//go back
		movement(-path[counter3-3]);//go back
		dir=path[counter3-3]+1;//using the former direction+1 to try
		counter3--;
		
		move(n,arr,path);//recursion
		
	}
	else if(counter3 == 2 && dir==9){//no solution
		noSolution = 1;
	}	
	
}

int main(){
	int n;//size of chess board
	int counter1,counter2;//counter
	
	for(n=1;n<=6;n++){
		cout<<"n="<<n<<":"<<endl;
		
		int **arr;
		arr=new int*[n];//dynamic allocate
		for(counter1=0;counter1<n;counter1++)
			arr[counter1]=new int[n];
			
		int path[n*n-1];//a path to record the knights passed by
		
		for(counter1=0;counter1<n;counter1++){//initialize all elements to zero
			for(counter2=0;counter2<n;counter2++){
				arr[counter1][counter2]=0;
			}
		}
		for(counter1=0;counter1<n*n-1;counter1++){//initialize
			path[counter1]=0;
		}
		
		//set starting point
		i=0;j=0;arr[i][j]=1;
		noSolution=0;
		dir=1;
		counter3=2;
			
		while(counter3<=n*n  && noSolution==0){
			move(n,arr,path);//function call
		}
		
		
		//print "no solution"
		if(noSolution==1){
			cout<<"no solution"<<endl;
		}
		//print the path of knight
		else{
			for(counter1=0;counter1<n;counter1++){
				for(counter2=0;counter2<n;counter2++){
					printf("%4d",arr[counter1][counter2]);
				}
				cout<<endl;
			}
		}
		cout<<endl;

	}
	 
} 
