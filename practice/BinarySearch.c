#include<stdio.h>

//int BinarySearch(int* ,int,const int);
int BinarySearch(int* a,int x,const int left,const int right);

/*
int main(){
	int n,i;
	int search;
	printf("key in your number of data:");
	scanf("%d",&n);
	
	int* arr = malloc(n*sizeof(int));//dynamic
	
	printf("then key in data:");//sorted**
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]); 
	}
	printf("key in number you want to search:");
	scanf("%d",&search);
	
	int outcome;
	outcome=BinarySearch(arr,search,n);
	if(outcome==-1){
		printf("we can't find it.\n");
		return 0;
	}
	else{
		printf("we find at %d places and its amount is %d\n",outcome+1,arr[outcome]);
		return 0;
	}
}

int BinarySearch(int *a,int x,const int n){
	int left=0,right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x<a[middle]){
			right=middle-1;
		}
		else if(x>a[middle]){
			left=middle+1;
		}
		else{
			return middle;
		}
	}
	return -1;
}
*/
int main(){
	int n,i;
	int search;
	printf("key in your number of data:");
	scanf("%d",&n);
	
	int* arr = malloc(n*sizeof(int));//dynamic
	
	printf("then key in data:");//sorted**
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]); 
	}
	printf("key in number you want to search:");
	scanf("%d",&search);
	
	int outcome;
	outcome=BinarySearch(arr,search,0,n-1);
	if(outcome==-1){
		printf("we can't find it.\n");
		return 0;
	}
	else{
		printf("we find at %d places and its amount is %d\n",outcome+1,arr[outcome]);
		return 0;
	}
}

int BinarySearch(int* a,int x,const int left,const int right){
	int middle = (left+right)/2;
	if(left<=right){
		if(x<a[middle]){
			return BinarySearch(a,x,left,middle-1);
		}
		else if(x>a[middle]){
			return BinarySearch(a,x,middle+1,right);
		}
		else{
			return middle;
		}
	}
	return -1;
}


