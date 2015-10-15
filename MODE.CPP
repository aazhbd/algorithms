#include <stdio.h>
#include <conio.h>
#include <time.h>

int main(){
	clrscr();
	int data[30000], i, n, tmp, m, f, j, c, mc;
	clock_t st, et;
	double total;

	freopen("C:\\in.txt", "r", stdin);

	n=0;
	while( scanf("%d", &data[n])==1 ){
		n++;
	}
	
	st=clock();

	f=1;
	m=0;
	j=0;
	for(i=0; i<n; i++){
		tmp=data[i];
		c=(i+f)%n;
		j=c;
		mc=0;
		if( data[c]==tmp ){
			while(data[j]==tmp){
				mc++;
				j++;
			}
			if(mc>f){
				m=tmp;
				f=mc;
			}
		}
	}

	et=clock();
	total= ( (et-st)/CLK_TCK );

	printf( "Mode is %d and frequency is %d\nTime taken %.17lf\n", m, f, total );

	return 0;
}