#include <stdio.h>
#include <windows.h>

int main(){
	int data[250000], i, n, item, index;
	long st, et;
	double total;
	bool b=false;

	freopen("C:\\in.txt", "r", stdin);

	n=0;
	while( scanf("%d", &data[n])==1 ){
		n++;
	}
	
	// Algorithm implementation for searching a data linearly.

	st=GetTickCount();

	item=32767;

	for(i=0; i<n; i++){
		if(data[i]==item){
			index=i;
			b=true;
			break;
		}
	}

	et=GetTickCount();

	total=et-st;

	if(b==true) printf( "The %d is found at %d\nTime taken %.17lf\n", data[index], index, total );
	else printf( "Not found\nTime Taken %.17lf\n", total );

	return 0;
}