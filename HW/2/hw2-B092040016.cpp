#include<iostream>
#include<string>
using namespace std;

class TSet{
	public:
		TSet();//constructor
		TSet(int in[]);//constructor �ѼƶǤJ�@�ӯx�} 
		const TSet operator+(const TSet& set);//overlaod operator +(union)       , �ѼƶǤJ�t�@�� class ���� 
		const TSet operator*(const TSet& set);//overlaod operator *(intersection), �ѼƶǤJ�t�@�� class ����
		const TSet operator-(const TSet& set);//overlaod operator -(difference)  , �ѼƶǤJ�t�@�� class ����
		bool operator>=(const TSet& set);//overload opeator >=(contains) , �ѼƶǤJ�t�@��class���� 
		bool in(char s);//to check whether the 's' element is in the set or not , �ѼƶǤJ�n�P�_������ s 
		friend istream& operator>>(istream& in,TSet& c);//input stream overloading,�ѼƶǤJ input stream �� �@�� class ���� 
		friend ostream& operator<<(ostream& out,TSet& c);//output stream overloading,�ѼƶǤJ output stream �� �@�� class ����
	private:
		char arr[256];//��ascii�Ȧs�J�Ÿ� 
		int amount = 0;//���X�̲Ÿ����ƶq 
		int sign[256]={0};//��l�ȳ]�� 0 �A���X�̲Ÿ��� ascii�ȹ�����}�C�� index�A�Y���ӲŸ��h�� index ���ȳ]�� 1 �F�Ϥ��A�S���h�]�� 0 
};

TSet::TSet(){}//constructor
TSet::TSet(int in[]){//constructor for passing an array
	for(int i =0;i<256;i++){
		sign[i]=0;
		if(in[i]==1){
			sign[i]=1;
			arr[amount]=char(i);//ascii���ഫ char �κA �A�æs�Jarr �}�C���C 
			amount++;//��s �U�@�ӭn��J arr �̪� index 
		}
	}
	
}
istream& operator>>(istream& in,TSet& c){//input stream overloading for passing input stream and a class object
	string str;
	getline(cin,str);//���o�@��檺��J 
	
	for(int i=0;i<str.length();i++){//�N�r��C�ӲŸ��ഫ�� ascii �æs�J sign �}�C�� 
		int index=(int)str[i];
		c.sign[index]=1;
	}
	for(int i=0;i<256;i++){//ascii���ഫ char �κA �A�æs�J arr �}�C��
		if(c.sign[i]==1){
			c.arr[c.amount]=char(i);
			c.amount++;
		}
	}
	return in;
}
ostream& operator<<(ostream& out,TSet& c){
	out<<"{";
	for(int i=0;i<c.amount;i++){//��X arr �}�C�̪��Ҧ��Ÿ� 
		out<<c.arr[i];
	}
	out<<"}"<<endl;
	return out;
}
const TSet TSet::operator+(const TSet& set){
	int list[256]={0};//list �}�C�@���N�ӭn�ǤJconstructor���Ѽ� 
	for(int i=0;i<256;i++){
		if(sign[i]==1 || set.sign[i]==1){//�p���� ������������ �� �t�@�Ӷ��X�������� �]�@�Ӧ��N�i�H�^ 
			list[i]=1;
		}
	}
	return TSet(list);//�^�� constructor  �гy�s���� 
} 
const TSet TSet::operator*(const TSet& set){
	int list[256]={0};//list �}�C�@���N�ӭn�ǤJconstructor���Ѽ�
	for(int i=0;i<256;i++){
		if(sign[i]==1 && set.sign[i]==1){//�涰�� ������������ �A�t�@�Ӷ��X�]�n�� �]��ӳ��n���^ 
			list[i]=1;
		}
	}
	return TSet(list);//�^�� constructor  �гy�s����
} 
const TSet TSet::operator-(const TSet& set){
	int list[256]={0};//list �}�C�@���N�ӭn�ǤJconstructor���Ѽ�
	for(int i=0;i<256;i++){//�t���� ������������ �A �t�@�Ӷ��X�S�� 
		if(sign[i]==1){
			list[i]=1;
			if(set.sign[i]==1)
				list[i]=0;
		}
	}
	return TSet(list);//�^�� constructor  �гy�s����
} 
bool TSet::operator>=(const TSet& set){
	int flag =0;//flag �@���Ÿ��ۦP���ɭԴN�[ 1 �A�̫��ˬd�O�_�� set �]�Ƕi�Ӫ��Ѽơ^���󪺤����ӼƬO�_�@�� 
	for(int i = 0;i<256;i++){
		if(set.sign[i]==1){
			if(sign[i]==1)
				flag++;
		}
	}
	if(flag==set.amount)//�Y�@�˫h�]�t�� 
		return true;
	else//���@�˫h�S���]�t�� 
		return false;
}
bool TSet::in(char s){
	if(sign[int(s)]==1)//�ˬd�Ƕi�ӲŸ���ascii�� ������  sign�}�C�̪�index��   �Asign[int(s)]�O�_�� 1 
		return true;
	else 
		return false;
}

int main(){
	int n;//n �@���X����� 
	cin>>n;
	
	for(int i=0 ; i<n;i++){
		char x;//x�@���ݬO�_�b���X�������� 
		
		TSet A,B;//constructor 
		
		cin.ignore();
		cin>>A>>B;//��JA��B�ⶰ�X������ 
		cin.get(x); //��Jx 
		
		//do +�B* then output 
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

