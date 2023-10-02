
#include<iostream>
using namespace std;

class Chain;

//implement a ChainNode class
class ChainNode{
	public:
		ChainNode(int data1=0,int data2=0,ChainNode* link=0);//constructor
		friend class Chain;//friend class
	private:
		int coef;//coefficient
		int exp;//exponent
		ChainNode *next;//link to next node
};
ChainNode::ChainNode(int data1,int data2,ChainNode* link):coef(data1),exp(data2),next(link){}//constructor

//implement the Chain class
class Chain{
	public:
		Chain();//constructor
		void Insert(const int x,const int y);//insert (x is coefficient and y is exponent)
		void Delete(ChainNode *x,ChainNode *y);//delete x node (x is after y)
		bool IsEmpty();//check if the chain is empty
		void Arrange();//arrange the chain
		void print();//print the chain
		Chain operator+(Chain& s);//overloading operator+(passing another chain object)
		Chain operator*(Chain& s);//overloading operatpr*(passing another chain object)
	private:
		ChainNode* first;//link to the first chainnode
};
Chain::Chain(){first = 0;}//constructor

void Chain::Insert(const int x,const int y){//x is coefficiet and y is exponent
	if(first){//insert to the first node
		first = new ChainNode(x,y,first);
	}
	else{//the chain is empty
		first = new ChainNode(x,y,0);
	}
}
void Chain::Delete(ChainNode *x,ChainNode *y=0){//delete Chainnode x (x is after y)
	if(x==first)
		first = x->next;
	else
		y->next=x->next;
	delete x;
}
bool Chain::IsEmpty(){//check if the chain is empty
	if(first)
		return false;
	else
		return true;
}
void Chain::Arrange(){
	if(!IsEmpty()){//if it is not empty,then arrange it
	
		ChainNode *k,*l;
		k=first;
		while(k->coef==0){//delete first ChainNode with 0 coefficient 
			Delete(k);
			k=first;
			if(k==0) break;
		}
	
		if(k==0)
			l=0;
		else
			l=k->next;
	
		while(l!=0){//delete ChainNode with o coefficient (between chain)
			if(l->coef==0){
				Delete(l,k);
				l=k->next;
				continue;
			}
			k=k->next;
			l=l->next;
		}
	
		
		int counter1=0;//store the highest exponent
		k=first;
		while(k!=0){
			if(k->exp>counter1){
				counter1=k->exp;
			}
			k=k->next;
		}
		
		//merge ChainNode with the same exponent,and put it in desecnding order
		int sum =0;//the coefficient of the merged ChainNode with sanme exponent
		
		
		ChainNode *arrange = first;//go through the Chain
		first = 0;//reset
		
		for(int counter2=0;counter2<=counter1;counter2++){//go through all the exponent(0~highest exponent)
			sum=0;
			k=arrange;
			while(k!=0){
				if(k->exp==counter2){//merge with the same exponent
					sum+=k->coef;
				}
				k=k->next;
			}
			if(sum!=0){//if the coefficient isn't zero,then insert it
				Insert(sum,counter2);
			}
		}
	}
}
void Chain::print(){//print the Chain
	if(!IsEmpty()){
		ChainNode *k;
		k=first;
		while(k!=0){
			cout<<k->coef<<" "<<k->exp<<endl;
			k=k->next;
		}
	}
	else//if empty,print"0 0"
		cout<<0<<" "<<0<<endl;
}
Chain Chain::operator+(Chain &s){
	
	Chain plus;//Chain to insert the result ChainNode
	ChainNode *k,*l;//link to ChainNode
	k=first;
	l=s.first;
	
	//insert all the ChainNodes
	while(k!=0){
		plus.Insert(k->coef,k->exp);
		k=k->next;
	}
	//also insert all ChainNodes of another Chain
	while(l!=0){
		plus.Insert(l->coef,l->exp);
		l=l->next;
	}
	
	plus.Arrange();//arrange it
	
	return plus;
}
Chain Chain::operator*(Chain &s){
	
	Chain multiply;//Chain to insert the result ChainNodes 
	ChainNode *k,*l;//link to ChainNodes

	k=first;
	l=s.first;
	
	if(k!=0 && l!=0){
		while(k!=0){//two while loop to run over all the ChainNodes to multiply and insert
			l=s.first;
			while(l!=0){
				multiply.Insert((k->coef)*(l->coef),(k->exp)+(l->exp));
				l=l->next;
			}
			k=k->next;
		}	
	}
	else//if k=0 or l=0 ,the result always be zero
		multiply.first=0;
	
	multiply.Arrange();//arrange it
	
	return multiply;
}

int main(){
	int counter=0;//counter for case number
	int P,Q;//first Chain has P ChainNode(s) and second Chain has Q ChainNode(s)
	int X,Y;//coefficient and exponent
	int p1,q1;//counter of time to insert into Chain
	
	do{
		Chain A,B,C,D;//constructor
		
		counter++;
		cin>>P;
		p1=P;
		while(p1>0){
			cin>>X>>Y;
			A.Insert(X,Y); //insert ChainNode into Chain A
			p1--;
		}
		
		cin>>Q;
		q1=Q;
		while(q1>0){
			cin>>X>>Y;
			B.Insert(X,Y);//insert ChainNode into Chain B
			q1--;
		}
		
		if(P!=0||Q!=0){
			C=A+B;//put the result A+B into Chain C
			D=A*B;//put the result A*B into Chain D
			
			//print the result
			cout<<"Case"<<counter<<":"<<endl;
			cout<<"ADD"<<endl;
		
			C.print();
		
			cout<<"MULTIPLY"<<endl;
		
			D.print();
			cout<<endl;
		}
		
	}while(P!=0||Q!=0);
}

