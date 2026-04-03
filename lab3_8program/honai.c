#include <stdio.h>
int count=0;
void TOH(int n, char s, char a, char d){
	if(n==1){
	printf("Move disk %d form %c to %c \n", n, s, d);
	count++;
	return;}
	
	TOH(n-1, s,d,a);
	printf("Move disk %d form %c to %c \n", n, s, d);
	count++;
	TOH(n-1, a, s, d);
	}
	
int main(){
	int n;
	printf("Enter the number of disk :");
	scanf("%d", &n);
	TOH(n, 'A', 'B' , 'C');
	printf("\nTotal number of moves taken : %d\n", count);
	return 0;
	 }
