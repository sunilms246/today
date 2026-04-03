#include <stdio.h>
int main(){
int a[100], n, i,key;
int low, high, mid, pos =-1;
scanf("%d",&n);
scanf("%d",&key);

for(i=0; i<n; i++)
scanf("%d", &a[i]);

for(i=0; i<n; i++){
if(a[i] == key){
pos = i;
break;
}
}

if(pos!=-1)
	printf("\nElement found at position %d", pos+1);
else 
printf("\nElement not found");
return 0;
}
