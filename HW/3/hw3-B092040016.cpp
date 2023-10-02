
#include<iostream>
using namespace std;

template<class T>
class Stack{//implement a stack class
	public:
		Stack(int stackCapacity);//create a empty stack(capacity is stackCapacity)
		bool isEmpty() const;//test if the stack is empty
		T& Top() const;//return the top element of the stack
		void Push(const T& x);//Push x in the stack
		void Pop();//take the top element out of the stack
		int top;//the top element's index
	private:
		T* stack;//array of stack
		int capacity;//capacity of stack
};

template<class T>
Stack<T>::Stack(int stackCapacity):capacity(stackCapacity){//create a empty stack(capacity is stackCapacity)
	stack = new T[capacity];//dynamic allocate
	top=-1;
}
template<class T>
bool Stack<T>::isEmpty() const{//test if the stack is empty
	return top==-1;
}
template<class T>
T& Stack<T>::Top() const{//return the top element of the stack
	if(isEmpty()) throw "Stack is empty";//it errors when the stack is empty
	return stack[top];
}
template<class T>
void Stack<T>::Push(const T& x){//Push x in the stack
	if(top==capacity-1) throw "Stack is full";//it errors when the stack is full(overflow)
	stack[++top]=x;
}
template<class T>
void Stack<T>::Pop(){//take the top element out of the stack
	if(top==-1) throw "Stack is empty";//it errors when the stack is empty
	stack[top--].~T();//destructor of T
}


int i,j;

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

int main(){
	int n;//size of chess board
	int dir,dir2;//direction of move
	int noSolution;//check if it has solution or not
	int counter1,counter2,counter3;//counter
	
	for(n=1;n<=6;n++){
		cout<<"n="<<n<<":"<<endl;

		Stack<int> S(n*n);//create a capcity of n*n stack
		
		int arr[n][n];//n*n size of chess board
		
		for(counter1=0;counter1<n;counter1++){//initialize all elements to zero
			for(counter2=0;counter2<n;counter2++){
				arr[counter1][counter2]=0;
			}
		}
		
		//set strating point
		i=0;j=0;arr[i][j]=1;
		noSolution = 0;
		dir2=1; 
		
		while(S.top<n*n-2 && noSolution == 0){//moves of knights on the size n*n chess board
			counter3=S.top+3;
			dir=dir2;
			if(dir<=8) movement(dir);
			
			while((i<0 || i>=n||j<0||j>=n||arr[i][j]!=0)&&dir<=8){//find another direction that knights can move
				movement(-dir);
				dir++;
				if(dir<=8) movement(dir);
			}
			
			if(dir<=8){//put the moves into stack and array
				movement(-dir);
				S.Push((i+1)*100+(j+1)*10+dir);
				movement(dir);
				arr[i][j]=counter3;
				dir2=1;
			}
			else if(counter3>2&&dir==9){//go back to the last position and try another dirction to move and pop from the stack
				dir2=S.Top()%10+1;
				arr[i][j]=0;
				i=S.Top()/100-1;
				j=S.Top()%100/10-1;
				S.Pop();
				
			}
			else if(counter3==2&&dir==9){//no solution
				noSolution=1;
			}
			
		}
		
		if(noSolution){//print "no solution"
			cout<<"	no solution!"<<endl;
		}
		else{//print the path of knight
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

