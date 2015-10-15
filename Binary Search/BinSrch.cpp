#include <stdio.h>
#include <windows.h>

int BinSrch(int *data, int n, int item){
	int index, low, mid, high;
	index=-1;
	low=0;
	high=n;

	while(low<=high){
		mid=(low+high)/2;
		if(data[mid]<item) low=mid+1;
		else high=mid-1;
	}
	if(data[mid]==item) index=mid;
	
	return index;
}

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
	
	st=GetTickCount();

	item=32767;
	
	index = BinSrch(data, n, item);
	
	et=GetTickCount();

	total=et-st;

	if(index>0) printf( "The %d is found at %d\nTime taken %.17lf\n", data[index], index, total );
	else printf( "Not found\nTime Taken %.17lf\n", total );

	return 0;
}