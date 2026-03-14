#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pi = arr[low];
	int i=low+1, j=high;
	while(i <= j){
		while((i<=j) && (arr[i] <= pi))
			i++;
		while((i<=j) && (arr[j] >= pi))
			j--;
		if(i<j){
			swap(&arr[i++], &arr[j--]);
		}
	}
	swap(&arr[j], &arr[low]);
	return j;
}

void quicksort(int arr[], int low, int high){
	if(low < high){
	int pi = partition(arr, low, high);
	quicksort(arr, low, pi-1);
	quicksort(arr, pi+1, high);
	}
}

int main()
 {
  int a[500000], i, n, m, ch, c, j=0, p;
  double extime;
  FILE *fp, *fp1;
  clock_t start, end;
  while(1)
   {
    printf("1. Quicksort sort \n 2. Recording time for differnt n \n 3. Exit \n");
    printf("Enter your choice :");
    scanf("%d",&ch);
    switch(ch)
     {
       case 1 : printf("Enter the number of elements to be sorted:");
                scanf("%d",&n);
                fp=fopen ("input.txt","w");
                for(i=0;i<n;i++)
                 {
                  m=random()%10000;
                  fprintf(fp,"%d\t",m);
                 }
                 printf("\n Random numbers generated are stored in file \n");
                 fclose(fp);
                 fp=fopen("input.txt","r"); 
                 while(fscanf(fp,"%d", &c)!=EOF)
                     a[j++]=c;
                     
                  fclose(fp);
                  quicksort(a,0,n-1);
                  fp=fopen("output.txt","w");
                  for(i=0;i<n;i++)
                    fprintf(fp,"%d\t", a[i]);
                  printf("Sorted elements are stored in file\n");
                  fclose(fp);
		break;
        case 2:
                for(p=10000;p<=100000;p+=10000)
                {
                  for(i=0;i<p;i++)
                 {
                  m=rand()%10000;
                  a[i]=m;
                  
                 }
                 
                fp1=fopen("plot.dat","a");
                start=clock();
                quicksort(a,0,p-1);
                end=clock();
                extime=(double)(end-start)/CLOCKS_PER_SEC;
                printf("\nExecution time for %d elements: %f\n",p,extime);
                fprintf(fp1,"%d\t%lf\n",p,extime);
                fclose(fp1);
               }
               break;
               case 3:exit(0); 
       }
     }
  
  return 0;
  } 
  
  
          
