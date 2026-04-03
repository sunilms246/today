#include <stdio.h>
int main(){
	int a[100], n, i, key;
	int low, high, mid, pos =-1;
	printf("\nEnter the no of elements : ");
	scanf("%d", &n);
	printf("\nenter each elemets : ");
	for(i =0; i<n; i++)
		scanf("%d", &a[i]);
	printf("\nenter key : ");
	scanf("%d", &key);
	
	low =0;
	high=n-1;
	while(low<=high){
		mid = (low +high)/2;
		if(a[mid] ==key){
			pos = mid;
			break; }
		else if(key < a[mid])
		high = mid-1;
		else low = mid +1;
	}
	
	if (pos!= -1)
	printf("\nElement found at position %d", pos+1);
	else 
	printf("\nElements not found");
	return 0;
}
