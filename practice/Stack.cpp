#include<iostream>
using namespace std;

template <class T>
class Stack{
	public:
		Stack(int stackCapacity = 10);
		bool IsEmpty() const;
		T& Top() const;
		void Push(const T& item);
		void Pop();
		void display() const;
	private:
		T *stack;
		int top;
		int capacity;
};

template <class T>
Stack<T>::Stack(int stackCapacity): capacity(stackCapacity){
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const{return top==-1;}

template <class T>
inline T& Stack<T>::Top() const{
	if(IsEmpty())
		throw "Stack Is Empty.";
	return stack[top];
}

template <class T>//type????
void Stack<T>::Push(const T& item){
	if(top == capacity - 1 )
		throw "Stack Overflows";
	stack[++top] = item;
}

template <class T>
void Stack<T>::Pop(){
	if(IsEmpty())
		throw "Stack IS empty. Cannot Delete.";
	stack[top--].~T();//destrcutor for T
}

template <class T>
void Stack<T>::display() const{//template??
	if(IsEmpty()) throw "Stack is empty.nothing to display.";
	for(int i=0;i<=top;i++){
		cout<<stack[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n,choice;//num
//	template <class T>
//	T num;
	int num;	
	
	cout<<"Let's make a stack data type.\n";
	cout<<"Enter the size of the Stack."<<endl;
	cin>>n;
	
	
	Stack<int> my(n);//template class??
	
	while(1){
		cout<<"1.Push item\n";
		cout<<"2.Pop item\n";
		cout<<"3.watch top element.\n";
		cout<<"4.display\n";
		cin>>choice;
		if(choice==0) break;
		
		switch(choice){
			case 1:
				cout<<"key in element you want to put in stack\n";
				cin>>num;
				my.Push(num);
				break;
			case 2:
				my.Pop();
				cout<<"Popped.\n";
				break;
			case 3:
				cout<<"top element: "<<my.Top()<<endl;
				break;
			case 4:
				cout<<"Stack:";
				my.display();
				break;
			default:
				cout<<"wrong choice"<<endl;		
		}
	}
}
