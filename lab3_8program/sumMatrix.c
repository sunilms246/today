#include <stdio.h>
int main(){
	int a[100][100], r, c, i, j, sum=0;
	printf("Enter row and colum : ");
	scanf("%d %d", &r, &c);
printf("Enter matrix : \n");
	
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &a[i][j]);
			sum = sum+ a[i][j];
		}
	}
	printf("\nSum = %d", sum);
	return 0;
}
