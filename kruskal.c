#include <stdio.h>
int i, j, n, u, v, ne = 1, a, b;
int cost[10][10], min, mincost = 0, parent[10];
int find(int);
int union1(int, int);
int main()
{
    printf("Enter the no. of vertices\n");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix, if there is no edge enter 999\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    for (i = 1; i <= n; i++)
        parent[i] = i;
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (union1(u, v))
        {
            printf("%d edge (%d %d) = %d\n", ne++, a, b, min);
            mincost = mincost + min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("MST cost = %d\n", mincost);
    return 0;
}
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
int union1(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}