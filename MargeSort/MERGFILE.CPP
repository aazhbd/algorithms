#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

#define n 3000

int a[3020];
int b[3020];

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

void BubbleSort(){
	int i, j, temp;
	for(i=0; i<n; i++){
		for(j=i+1; j<=n; j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void main(){
	int i=0;
	clrscr();
	FILE *f=fopen("num.txt", "r");
	FILE *f2=fopen("out.txt", "w");

	for(i=0; i<n; i++){
		fscanf(f, "%d", &a[i]);
	}
//	partition(0, n-1);
	BubbleSort();

	for(i=0; i<n; i++){
		fprintf(f2, "%d\n", a[i]);
	}
	getch();
}