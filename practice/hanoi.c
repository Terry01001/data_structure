#include<stdio.h>
#include<time.h>

void towers(int,char,char,char);

int main(){
	int n;
	scanf("%d",&n);
	
	clock_t start,stop;
	double duration;
	start=clock();
	
	
	towers(n,'A','B','C');
	
	stop=clock();
	duration = ((double)(stop-start)/CLOCKS_PER_SEC );
	printf("\n we spent %lf time\n",duration);
}

/*
int main(){
	int n;
	scanf("%d",&n);
	
	time_t start,stop;
	start=time(NULL);
	double duration;
	
	towers(n,'A','B','C');
	
	stop=time(NULL);
	duration = ((double) difftime(stop,start));
	printf("\n we spent %lf time\n",duration);
}
*/
void towers(int n,char A,char B,char C){
	if(n==1){
		printf("\n%s%c%s%c","move disk 1 from peg ",A," to peg ",C);
		return;
	}
	
	towers(n-1,A,C,B); 
	
	printf("\n%s%d%s%c%s%c","move disk ",n," from peg ",A," to peg ",C);
	
	towers(n-1,B,A,C);
}
