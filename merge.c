#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int low, int mid, int high){
    int i=low, j=mid+1;
    int c[500000], k=0;
    while(i<= mid && j<=high){
        if(a[i] <= a[j])
            c[k++] = a[i++];
        else 
            c[k++] = a[j++];
    }
    while(i<=mid){
        c[k++] = a[i++];
    }
    while(j<=high){
        c[k++] = a[j++];
    }
    for(i=low,j=0; i<=high; i++, j++){
        a[i] = c[j];
    }

}

void mergesort(int a[], int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main(){
    int choice, a[500000],i,j,c;
    FILE *fp;
    double extime;
    clock_t start, end;
    while(1){
        printf("\n1-> Merge sort \n2-> Recorded time for n\n3-> exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter the number of element to sort : ");
                    int n;
                    scanf("%d", &n);
                    fp = fopen("input.txt", "w");
                    for(i=0; i<n; i++){
                        fprintf(fp, "%d\t", rand()%1000);
                    }
                    printf("\nRandom numbers are stored in file");
                    fclose(fp);
                    fp = fopen("input.txt", "r");
                    j=0;
                    while(fscanf(fp, "%d", &c)!=EOF)
                        a[j++] = c;
                    fclose(fp);
                    mergesort(a, 0, n-1);
                    fp = fopen("output.txt", "w");
                    for(i=0; i<n; i++){
                        fprintf(fp, "%d\t", a[i]);
                    }
                    printf("\nSorted numbers are stored in file");
                    fclose(fp);
                    break;
            
            case 2: for(int p =10000; p<=100000; p+=10000){
                        for(i=0; i<p ; i++){
                            a[i] = rand()%100000;
                        }
                        fp = fopen("plot.dat", "a");
                        start = clock();
                        mergesort(a, 0, p-1);
                        end = clock();
                        extime = (double) (end - start)/CLOCKS_PER_SEC;
                        printf("\nexcecution time for %d is %f",p, extime);
                        fprintf(fp, "%d\t%1f\n",p, extime);
                        fclose(fp);
                    }
                    break;

            case 3: exit(0);


        }
    }
}