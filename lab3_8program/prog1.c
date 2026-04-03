#include <stdio.h>
int main(){
	int sum=0 , n, i;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	int a[100];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	for(i=0; i<n; i++)
		sum += a[i];
	printf("\nSum of array is : %d\n", sum);
	return 0;
	}
