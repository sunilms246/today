#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int t  = *a;
    *a = *b;
    *b = t;
}

void heapify(int h[], int n, int low){
    int i, j, k, v, heap;
    for(i=n/2; i>=low; i--){
        k = i;
        v = h[k];
        heap = 0;
        while(!heap && (2*k)<=n){
            j = 2 *k;
            if(j<n){
                if(h[j] < h[j+1])
                    j= j+1;
            }
            if (v >= h[j]){
                heap = 1;
            }
            else{
                h[k] = h[j];
                k=j;
            }
        }
        h[k] = v;
    }
}

void heapsort(int h[], int n){
    int i;
    heapify(h, n, 1);
    for(i=n; i>=1; i--){
        swap(&h[1], &h[i]);
        heapify(h, i-1, 1);
    }
}

int main(){
    int n, h[500000], choice, i,j;
    FILE *fp;
    double extime;
    clock_t start, end;
    while(1){
        printf("\n\n1-> Heap sort\n2-> Recorded time for diffarent n\n3-> exit\nEnter your choice :");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter the number of elements to be sorted: ");
                    scanf("%d", &n);
                    fp = fopen("input.txt", "w");
                    for(i=1; i<=n; i++){
                        fprintf(fp, "%d\t", rand()%10000);
                    }
                    printf("\nRandum genarated numbers are stored in file");
                    fclose(fp);
                    fp = fopen("input.txt", "r");
                    int c;
                    j=1;
                    while(fscanf(fp, "%d", &c)!=EOF)
                        h[j++] = c;
                    fclose(fp);
                    heapsort(h, n);

                    fp = fopen("output.txt", "w");
                    for(i=1; i<=n; i++){
                        fprintf(fp, "%d\t", h[i]);
                    }
                    fclose(fp);
                    printf("\nsorted numbers are stored in file");
                    break;
            case 2: for(int p = 10000; p<=100000; p+=10000){
                        for(i=1; i<=p; i++){
                            h[i] = rand()%10000;
                        }
                        fp = fopen("heap.dat", "a");
                        start = clock();
                        heapsort(h, p);
                        end = clock();
                        extime = (double)(end-start)/CLOCKS_PER_SEC;
                        fprintf(fp, "%d\t%f\n", p, extime);
                        printf("\nexection time for %d is %f", p, extime);
                        fclose(fp);
                    }
                    break;
            case 3: exit(0);
        }
    }
}