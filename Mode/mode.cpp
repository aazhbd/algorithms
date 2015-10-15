#include <stdio.h>
#include <windows.h>

int main(){
	int data[250000], i, n, mode, f, cmode, mf;
	long st, et;
	double total;

	freopen("C:\\in.txt", "r", stdin);

	n=0;
	while( scanf("%d", &data[n])==1 ){
		n++;
	}
	
	st=GetTickCount();

	mode=data[0];
	f=1;

	for(i=1; i<n; i++){
		if( data[i]==cmode ){
			f++;
		}		
		else{
			f=1;
			cmode=data[i];
		}

		if(f>mf){
			mf=f;
			mode=data[i];
		}
	}

	et=GetTickCount();
	total=et-st;

	printf( "Mode is %d and frequency is %d\nTime taken %.17lf\n", mode, mf, total );

	return 0;
}