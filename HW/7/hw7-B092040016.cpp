
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
//A selection sort
void SelectionSort(int arr[], int num) {
	int i,j;
    for (i=0; i<num-1; i++) {
        int minIndex = i;
        for (j=i+1; j<num; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // swap
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
//B mergesort
void Merge(int arr[],int p,int q,int r){
	int index1=q-p+1,index2=r-q;
	int left[index1],right[index2];
	int i,j;
	for(i=0;i<index1;i++){
		left[i]=arr[p+i];
	}
	for(j=0;j<index2;j++){
		right[j]=arr[q+j+1];
	}
	i=0;j=0;
	int k=p;
	while(i<index1 && j<index2){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			i++;
		}
		else{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	//Copy the remaining elements into arr[], if left[] haven't finished scanning
  	while(i < index1){
   		arr[k] = left[i];
    	i++;
    	k++;
  	}
  	//Copy the remaining elements into arr[], if right[] haven't finished scanning
  	while(j < index2){
    	arr[k] = right[j];
    	j++;
    	k++;
  	}	
}
void MergeSort(int arr[],int p,int r){
	if(p<r){
		int q=(p+r)/2;
		MergeSort(arr,p,q);
		MergeSort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}
//C radix sort
int getmax(int arr[],int num){
	int max=arr[0];
	for(int i=1;i<num;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
void CountSort(int arr[],int num,int exp){
	int i;
	int output[num];
	int count[10]={0};
	
	for(i=0;i<num;i++)
		count[(arr[i]/exp)%10]++;
	for(i=1;i<10;i++)
		count[i]+=count[i-1];//accumulate
	
	for(i=num-1;i>=0;i--){
		output[count[(arr[i]/exp)%10]-1]=arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(i=0;i<num;i++){
		arr[i]=output[i];
	}	
}
void RadixSort(int arr[],int num){
	int exp,m;
	
	m=getmax(arr,num);//get max element
	
	for(exp=1;m/exp>0;exp*=10){
		CountSort(arr,num,exp);
	}
}
//D qsort()
int compare(const void *a, const void *b)//the function that qsort will use 
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}               
      else if (c == d) {return 0;}      
      else return 1;                          
}






int main(){
	ifstream input1;//input file stream
	input1.open("input.txt");
		
	int N;
	input1>>N;
	int arr[N],arr2[N],arr3[N],arr4[N],arr5[N];
	for(int i=0;i<N;i++){
		input1>>arr[i];
		arr2[i]=arr3[i]=arr4[i]=arr5[i]=arr[i];
	}
	input1.close();
	
	//for(int i=0;i<N;i++){cout<<arr2[i]<<endl;}
	
	//selection sort
	SelectionSort(arr,N);
	
	ofstream out1;//output file stream
	out1.open("outputA.txt");
	out1<<"Selection Sort"<<endl;
	for(int i=0;i<N;i++){
		out1<<arr[i]<<endl;
	}
	out1.close();
	
	//merge sort
	MergeSort(arr2,0,N-1);
	
	ofstream out2;
	out2.open("outputB.txt");
	out2<<"Merge Sort"<<endl;
	for(int i=0;i<N;i++){
		out2<<arr2[i]<<endl;
	}
	out2.close();
	
	//Radix sort
	RadixSort(arr3,N);
	
	ofstream out3;
	out3.open("outputC.txt");
	out3<<"Radix Sort"<<endl;
	for(int i=0;i<N;i++){
		out3<<arr3[i]<<endl;
	}
	out3.close();
	
	//C qsort()
	qsort(arr4,N,sizeof(int),compare);
	
	ofstream out4;
	out4.open("outputD.txt");
	out4<<"C qsort()"<<endl;
	for(int i=0;i<N;i++){
		out4<<arr4[i]<<endl;
	}
	out4.close();
	
	//C++ sort()
	sort(arr5,arr5+N);
	
	ofstream out5;
	out5.open("outputE.txt");
	out5<<"C++ sort()"<<endl;
	for(int i=0;i<N;i++){
		out5<<arr5[i]<<endl;
	}
	out5.close();
	
	
	
} 
