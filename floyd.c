#include <stdio.h>
void main()
{
    int x, i, j, k, n, a[20][20];
    printf("Enter no.of nodes\n");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The cost adjacency matrix is\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    // k must be the outermost loop
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    printf("Shortest path matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}
