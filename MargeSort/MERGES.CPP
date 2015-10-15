#include <iostream.h>
#include <conio.h>

int a[20];
int b[20], n;

void merge(int l, int m, int h){
	int i, j, k;
	i=l;
	j=m+1;
	k=l;
	while(i<=m && j<=h){
		if(a[i]<a[j]){
			b[k]=a[i];
			i++;
			k++;
		}
		else{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	if(i>m){
		while(j<=h){
			b[k]=a[j];
			k++;
			j++;
		}
	}
	else{
		while(i<=m){
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(i=l; i<=h; i++){
		a[i]=b[i];
	}
}

void partition(int l, int h){
	int m;
	if(l<h){
		m=((l+h)/2);
		partition(l, m);
		partition(m+1, h);
		merge(l, m, h);
	}
}

void main(){
	int i;
	clrscr();
	cin>>n;
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	partition(0, n-1);
	cout<<"sorted list is"<<endl;
	for(i=0; i<n; i++){
		cout<<a[i]<<endl;
	}
	getch();
}