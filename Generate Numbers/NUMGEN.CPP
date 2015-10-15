#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i;

	freopen("C:\\in.txt", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("%d\n", rand() % n);
	}
	return 0;
}