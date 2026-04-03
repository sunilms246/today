#include <stdio.h>

int main() {
    int a[100], n, i, j, flag = 1;

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            break; 
    }

    if(flag == 1)
        printf("\nUnique\n");
    else
        printf("\nNot Unique\n");

    return 0;
}
