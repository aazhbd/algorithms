//	Jacobi's method


#include<stdio.h>
#include<conio.h>


void main()
{
	float a[20][20], b[20], xp[20]={0}, xc[20], sum;
	int n, i, j, k, l, m;

	printf("How many equations? ");
	scanf("%d",&n);

	printf("\nEnter the co-efficient matrix...\n\n");

	for(l=1;l<=n;l++) {

		for(m=1;m<=n;m++) scanf("%f",&a[l][m]);

		scanf("%f",&b[l]);			// for b
	}

	for(i=0;i<10;i++) {         //How many iteration?

		printf("\nIteration #%2d --> ", i);

		for(k=1;k<=n;k++){

			sum=0;
			for(j=1;j<=n;j++)
				if(j!=k) sum=sum+a[k][j]*xp[j];

			xc[k]=(b[k]-sum)/a[k][k];

			printf("%f\t",xc[k]);
		}
		printf("\n");

		for(k=1; k<=n; k++) xp[k]=xc[k];      		//	Transfer
	}

	getch();
}
