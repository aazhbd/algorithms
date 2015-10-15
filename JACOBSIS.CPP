#include <stdio.h>
#include <conio.h>

float a[50][50], xp[50], xc[50], b[50];
int n;

void copy(float *a, float *b){
	int i;
	for(i=0; i<n; i++)
		a[i]=b[i];
}

void main(){
	int i, j, k, o, m;
	float sum=0;
	clrscr();
	printf("Enter the number of equations:\n");
	scanf("%d", &n);
	printf("Enter Co-officients:\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%f", &a[i][j]);
		}
	}
	printf("Enter constants:\n");
	for(o=0; o<n; o++){
		scanf("%f", &b[o]);
	}
	//for ten time iteration
	for(m=0; m<5; m++){
		for(k=0; k<n; k++){
			for(j=0; j<n; j++){
				if(j!=k) sum+=a[k][j]*xp[j];
			}
			xc[k]=(b[k]-sum)/a[k][k];
		}
		for(o=0; o<n; o++)
			printf("Currently XC=%f XP=%f and iteration is %d\n", xc[o], xp[o], m);
		copy(xp, xc);
	}

	for(o=0; o<n; o++)
			printf("Finally XC=%f XP=%f\n", xc[o], xp[o]);

	getch();
}