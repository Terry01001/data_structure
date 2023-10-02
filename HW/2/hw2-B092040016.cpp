#include<iostream>
#include<string>
using namespace std;

class TSet{
	public:
		TSet();//constructor
		TSet(int in[]);//constructor 參數傳入一個矩陣 
		const TSet operator+(const TSet& set);//overlaod operator +(union)       , 參數傳入另一個 class 物件 
		const TSet operator*(const TSet& set);//overlaod operator *(intersection), 參數傳入另一個 class 物件
		const TSet operator-(const TSet& set);//overlaod operator -(difference)  , 參數傳入另一個 class 物件
		bool operator>=(const TSet& set);//overload opeator >=(contains) , 參數傳入另一個class物件 
		bool in(char s);//to check whether the 's' element is in the set or not , 參數傳入要判斷的元素 s 
		friend istream& operator>>(istream& in,TSet& c);//input stream overloading,參數傳入 input stream 跟 一個 class 物件 
		friend ostream& operator<<(ostream& out,TSet& c);//output stream overloading,參數傳入 output stream 跟 一個 class 物件
	private:
		char arr[256];//按ascii值存入符號 
		int amount = 0;//集合裡符號的數量 
		int sign[256]={0};//初始值設為 0 ，集合裡符號的 ascii值對應到陣列的 index，若有該符號則該 index 的值設為 1 ；反之，沒有則設為 0 
};

TSet::TSet(){}//constructor
TSet::TSet(int in[]){//constructor for passing an array
	for(int i =0;i<256;i++){
		sign[i]=0;
		if(in[i]==1){
			sign[i]=1;
			arr[amount]=char(i);//ascii值轉換 char 形態 ，並存入arr 陣列中。 
			amount++;//更新 下一個要放入 arr 裡的 index 
		}
	}
	
}
istream& operator>>(istream& in,TSet& c){//input stream overloading for passing input stream and a class object
	string str;
	getline(cin,str);//取得一整行的輸入 
	
	for(int i=0;i<str.length();i++){//將字串每個符號轉換成 ascii 並存入 sign 陣列裡 
		int index=(int)str[i];
		c.sign[index]=1;
	}
	for(int i=0;i<256;i++){//ascii值轉換 char 形態 ，並存入 arr 陣列中
		if(c.sign[i]==1){
			c.arr[c.amount]=char(i);
			c.amount++;
		}
	}
	return in;
}
ostream& operator<<(ostream& out,TSet& c){
	out<<"{";
	for(int i=0;i<c.amount;i++){//輸出 arr 陣列裡的所有符號 
		out<<c.arr[i];
	}
	out<<"}"<<endl;
	return out;
}
const TSet TSet::operator+(const TSet& set){
	int list[256]={0};//list 陣列作為將來要傳入constructor的參數 
	for(int i=0;i<256;i++){
		if(sign[i]==1 || set.sign[i]==1){//聯集為 本身有的元素 或 另一個集合有的元素 （一個有就可以） 
			list[i]=1;
		}
	}
	return TSet(list);//回傳 constructor  創造新物件 
} 
const TSet TSet::operator*(const TSet& set){
	int list[256]={0};//list 陣列作為將來要傳入constructor的參數
	for(int i=0;i<256;i++){
		if(sign[i]==1 && set.sign[i]==1){//交集為 本身有的元素 ，另一個集合也要有 （兩個都要有） 
			list[i]=1;
		}
	}
	return TSet(list);//回傳 constructor  創造新物件
} 
const TSet TSet::operator-(const TSet& set){
	int list[256]={0};//list 陣列作為將來要傳入constructor的參數
	for(int i=0;i<256;i++){//差集為 本身有的元素 ， 另一個集合沒有 
		if(sign[i]==1){
			list[i]=1;
			if(set.sign[i]==1)
				list[i]=0;
		}
	}
	return TSet(list);//回傳 constructor  創造新物件
} 
bool TSet::operator>=(const TSet& set){
	int flag =0;//flag 作為符號相同的時候就加 1 ，最後檢查是否跟 set （傳進來的參數）物件的元素個數是否一樣 
	for(int i = 0;i<256;i++){
		if(set.sign[i]==1){
			if(sign[i]==1)
				flag++;
		}
	}
	if(flag==set.amount)//若一樣則包含於 
		return true;
	else//不一樣則沒有包含於 
		return false;
}
bool TSet::in(char s){
	if(sign[int(s)]==1)//檢查傳進來符號的ascii值 對應到  sign陣列裡的index值   ，sign[int(s)]是否為 1 
		return true;
	else 
		return false;
}

int main(){
	int n;//n 作為幾筆資料 
	cin>>n;
	
	for(int i=0 ; i<n;i++){
		char x;//x作為看是否在集合內的元素 
		
		TSet A,B;//constructor 
		
		cin.ignore();
		cin>>A>>B;//輸入A跟B兩集合的元素 
		cin.get(x); //輸入x 
		
		//do +、* then output 
		TSet C,D;//constructor
		C=A+B;
		D=A*B;
		
		cout<<"Test Case "<<(i+1)<<":"<<endl;
		cout<<"A: "<<A;
		cout<<"B: "<<B;
		cout<<"A+B: "<<C;
		cout<<"A*B: "<<D;
		
		//do - then output
		TSet E=(A-B),F=(B-A);
		
		cout<<"A-B: "<< E;
		cout<<"B-A: "<< F;
		
		//do contains then output
		if(A>=B)
			cout<<"A contains B"<<endl;
		else
			cout<<"A does not contain B"<<endl;
		
		if(B>=A)
			cout<<"B contains A"<<endl;
		else
			cout<<"B does not contain A"<<endl;
		
		//do check in or not then output	
		if(A.in(x))
			cout<<"\'"<<x<<"\' is in A"<<endl;
		else
			cout<<"\'"<<x<<"\' is not in A"<<endl;
		
		if(B.in(x))
			cout<<"\'"<<x<<"\' is in B"<<endl;
		else
			cout<<"\'"<<x<<"\' is not in B"<<endl;
			
		cout<<endl;
	}
}

