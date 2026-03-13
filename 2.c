#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int j = high;
    int i = low + 1;
    while (i <= j)
    {
        while ((i <= j) && (arr[i] <= pivot))
            i++;
        while ((i <= j) && (arr[j] >= pivot))
            j--;
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
int main()
{
    int n;
    printf("\n enter the no. of elements:");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    float cpu_time;
    clock_t start, end;
    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();
    float clock_per_sec = CLOCKS_PER_SEC;
    cpu_time = ((float)(end - start)) / clock_per_sec;
    printf("\n time elapsed:%f seconds", cpu_time);
    FILE *fp;
    fp = fopen("quicksortop.txt", "a");
    fprintf(fp, "%d\t\t ", n);
    fprintf(fp, "%f\n", cpu_time);
    fclose(fp);
    free(arr);
    return 0;
}