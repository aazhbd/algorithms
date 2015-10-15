#include <stdio.h>
#include <windows.h>

int main(){
	int data[250000], i, j, n, temp;

	long st, et;
	double total;

	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);

	n=0;
	while( scanf("%d", &data[n])==1 ){
		n++;
	}

	st=GetTickCount();
	
	for(i=0; i<n; i++){
		for(j=i+1; j<=n; j++){
			if( data[i]>data[j] ){
				temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
	}
	
	et=GetTickCount();

	total=et-st;

	for(i=0; i<n; i++){
		printf("%d\n", data[i]);
	}

	printf("Time taken %.17lf", total);

	return 0;
}
