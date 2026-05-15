#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int  t = *a;
    *a = *b;
    *b = t;
}
int partision(int a[], int low, int high){
    int pi = a[low];
    int i=low+1, j=high;
    while(i<=j){
        while((i<=j) && (a[i] <= pi)) i++;
        while((i<=j) && (a[i] >= pi)) j--;
        if(i<j) swap(&a[i++], &a[j--]);
    }
    swap(&a[j] , &a[low]);
    return j;
}

void quicksort(int a[], int low, int high){
    if( low < high){
        int pi = partision(a, low, high);
        quicksort(a, low, pi-1);
        quicksort(a, pi+1, high);
    }
}

int main(){
    int choice, i, j=0, c;
    int a[500000];
    FILE *fp;
    clock_t start, end;
    double extime;
    while(1){
        printf("\n1-> Quicksort\n2-> Record time for n\n3-> exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter the number of elements to sort :");
                    int n;
                    scanf("%d", &n);
                    fp = fopen("input.txt", "w");
                    for(i=0; i<n; i++){
                        fprintf(fp, "%d\t", rand()%10000);
                    }
                    printf("\nRandum numbers are stored in file");
                    fclose(fp);
                    fp =fopen("input.txt", "r");
                    while(fscanf(fp, "%d", &c)!=EOF){
                        a[j++] = c;
                    }
                    fclose(fp);

                    quicksort(a, 0, n-1);
                     
                    fp = fopen("output.txt", "w");
                    for(i=0; i<n; i++){
                        fprintf(fp, "%d\t", a[i]);
                    }
                    fclose(fp);
                    printf("\nSorted number are stored in file");
                    break;

            case 2: for(int p=10000; p<=100000; p+=10000){
                        for(i=0; i<n; i++){
                            a[i] = rand()%10000;
                        }
                        start = clock();
                        quicksort(a, 0, p-1);
                        end = clock();
                        extime = (double)(end - start)/CLOCKS_PER_SEC;
                        fp = fopen("quick.dat", "a");
                        fprintf(fp , "%d\t%f\n", p, extime);
                        printf("\nExecution time for %d is %1f", p, extime);
                        fclose(fp);
                    }
                    break;
            case 3: exit(0);
        }   
    }
}