//	Bisection Method


#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<process.h>

int X[10];

float F(float a, int n)
{
	float f=0.0;

	for(int i=0; i<n; i++)

		f += X[i]*pow(a,n-i);

	f += X[i];

	return f;
}

float diff(float a, float b)
{
	if(a<0) a = -a;

	if(b<0) b = -b;

	if(a>b) return (a-b);

	return (b-a);
}


void main(void)
{
	int n;
	float f, a, b, c;

	printf("\n\n\n\nGive n :: ");
	scanf("%d", &n);

	printf("\nGive all co-efficients :: ");
	for(int i=0; i<=n; i++) scanf("%d", &X[i]);

	printf("\nGive 'a' such that f(a) is positive :: ");
	scanf("%f", &a);

	printf("\nGive 'b' such that f(b) is negative :: ");
	scanf("%f", &b);

	while( diff(a, b) > 0.001) {

		c = (a+b)/2.0;
		f = F(c, n);

		if(f>0) a = c;
		else if(f<0) b = c;

			else {
				printf("\n\nExact root is %f", c);
				getch();
				exit(0);
			}
	}

	printf("\n\nRoot (approx.) for this equation is %f", a);

	printf("\n\nValue of function for this root is %f", F(a, n));

	getch();

}
