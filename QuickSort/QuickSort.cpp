#include <stdio.h>
#include <time.h>

int partition(int *A,int p,int q){
	int x,i,j,temp;
	x=A[p];
	i=p;
	for(j=p+1;j<=q;j++)
	{
		if(A[j]<=x){
			i=i+1;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	temp=A[p];
	A[p]=A[i];
	A[i]=temp;
	return i;
}



void quicksort(int *A,int p,int r){
	int q;
	if(p<r){
	     q=partition(A,p,r);
	     quicksort(A,p,q-1);
	     quicksort(A,q+1,r);
	}
}

int main(){
	int data[25000], i, j, n, temp;

	clock_t st, et;
	double total;

	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);

	n=0;
	while( scanf("%d", &data[n])==1 ){
		n++;
	}

	st=clock();
	quicksort(data, 0, n);	
	et=clock();

	total=( (et-st)/CLK_TCK );

	for(i=0; i<n; i++){
		printf("%d\n", data[i]);
	}

	printf("Time taken %.17lf", total);

	return 0;
}
