#include<stdio.h>

//recursive
/*
int fib(int n){
	if(n<=1){
		return n;
	}
	else{
		return fib(n-1)+fib(n-2) ;
	}
}
*/
//for loop//efficient
int fib(int n){
	int i,x,lofib=0,hifib=1;
	
	if(n<=1){
		return n;
	}
	for(i=2;i<=n;i++){
		x = lofib;
		lofib = hifib;
		hifib = x+lofib;
	}
	return hifib;
}

int main(){
	int num;
	printf("key in the place to cal fibonacci seq:");
	scanf("%d",&num);
	printf("%d",fib(num));
}

