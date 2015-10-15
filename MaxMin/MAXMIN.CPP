#include <stdio.h>
#include <windows.h>

int main(){
	int data[250000], max, min, i, n;
	long st, et;
	double total;

	freopen("C:\\in.txt", "r", stdin);

	n=0;
	while( scanf("%d", &data[n])==1 ){
		n++;
	}

	/* algorithm implementation for finding maximum and minimum */
	
	st=GetTickCount();

	max=min=data[0];

	for(i=1; i<n; i++){
		if( data[i]<min ) min=data[i];
		else if( data[i]>max ) max=data[i];
	}

	et=GetTickCount();

	total=et-st;

	printf("Maximum is %d\nMinimum is %d\nTotal Time Taken %.17lf\n", max, min, total );

	return 0;
}