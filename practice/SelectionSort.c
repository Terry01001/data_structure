#include<stdio.h>

void SelectionSort(int* arr,int n){
	int index,i,j;
	for(i=0;i<n-1;i++){
		index=i;//min
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[index]){
				index=j;
			}
		}
		if(index!=i){
			int temp=arr[i];
			arr[i]=arr[index];
			arr[index]=temp;
		}
	}
} 

int main(){
	int num,i;
	printf("key in the number of your data:");
	scanf("%d",&num);
	
	int *a=malloc(num*sizeof(int));
	
	for(i=0;i<num;i++){
		scanf("%d",&a[i]);
	}
	
	SelectionSort(a,num);
	
	//print sorted
	for(i=0;i<num;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
