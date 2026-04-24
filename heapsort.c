#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b)
 {
   int t=*a;
   *a=*b;
   *b=t;
 }
 
 void heapify(int H[], int n, int low)
   {
     int i,j,k,v,heap;
     for(i=n/2;i>=low;i--)
      {
        k=i;
        v=H[k];
        heap=0;
         while(!heap && (2*k)<=n)
           {
             j=2*k;
             if (j<n)
                {
                  if(H[j]<H[j+1])
                       j=j+1;
                 }
             if(v>=H[j])
                heap=1;
             else
               {
                 H[k]=H[j];
                 k=j;
               }
             }//end of while
         H[k]=v;
       } //end of for    
     } //end of heapify
 void heapsort(int H[], int n)
   {
     int i;
     heapify(H,n,1);
     for(i=n;i>=1;i--)
      {
        swap(&H[1],&H[i]);
        heapify(H, i-1,1);
      }
   }
int main()
{
 int H[50], n,i,j;
 printf("Enter the number of elements to be sorted:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
  scanf("%d",&H[i]);
 heapsort(H,n);
 printf("Sorted elements are \n");
 for(i=1;i<=n;i++)
   printf("%d\t", H[i]);
   
   printf("\n");
 return 0;
}                        //end of main
