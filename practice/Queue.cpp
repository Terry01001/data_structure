#include<iostream>
using namespace std;

template<class T>
class Queue{
	public:
		Queue(int queueCapacity = 10);
		bool IsEmpty() const;
		T& Front() const;
		T& Rear() const;
		void Push(const T& item);
		void Pop();
		void display() const;
	private:
		T *queue;
		int front;
		int rear;
		int capacity;
};

template<class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity){
	queue = new T[capacity];
	front = rear = capacity - 1;//0 is also OK.
}

template<class T>
inline bool Queue<T>::IsEmpty() const{return front == rear;}

template<class T>
inline T& Queue<T>::Front() const{
	if(IsEmpty())
		throw "Queue is empty.";
	return queue[(front+1)%capacity];
}

template<class T>
inline T& Queue<T>::Rear() const{
	if(IsEmpty())
		throw "Queue is empty.";
	return queue[rear];
}

template<class T>
void Queue<T>::Push(const T& item){
	if((rear+1)%capacity == front)
		throw "Queue is full.";
	rear = (rear+1)%capacity;
	queue[rear] = item;
}

template<class T>
void Queue<T>::Pop(){
	if(IsEmpty())
		throw "Queue is empty.";
	front = (front+1)% capacity;
	queue[front].~T();//destrcutor fot T
}

template<class T>
void Queue<T>::display() const{
	if(IsEmpty())
		throw "Queue is empty. cannot be displayed.";
	int i = (front+1)%capacity;
	while(1){
		cout<<queue[i]<<" ";
		if(i==rear) break;
		else{
			i=(i+1)%capacity;
		}
	}
	cout<<endl;
}

int main(){
	int n,choice;//num
//	template <class T>
//	T num;
	int num;	
	
	cout<<"Let's make a queue data type.\n";
	cout<<"Enter the size of the Queue."<<endl;
	cin>>n;
	
	
	Queue<int> my(n);//template class??
	
	while(1){
		cout<<"1.Push item\n";
		cout<<"2.Pop item\n";
		cout<<"3.watch front element.\n";
		cout<<"4.display\n";
		cout<<"5.watch rear element.\n";
		cin>>choice;
		if(choice==0) break;
		
		switch(choice){
			case 1:
				cout<<"key in element you want to put in queue\n";
				cin>>num;
				my.Push(num);
				break;
			case 2:
				my.Pop();
				cout<<"Popped.\n";
				break;
			case 3:
				cout<<"front element: "<<my.Front()<<endl;
				break;
			case 4:
				cout<<"Queue:";
				my.display();
				break;
			case 5:
				cout<<"rear element:"<<my.Rear()<<endl;
				break;
			default:
				cout<<"wrong choice"<<endl;		
		}
	}
}
