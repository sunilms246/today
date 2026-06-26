#include <stdio.h>

int n, wt[10], v[10], W, V[10][10], x[10];

int max(int a, int b);
void knapsack();
void printsolution();

int main() {
    int i;

    printf("Enter the no of objects: ");
    scanf("%d", &n);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    printf("Enter the object weights and profits:\n");
    for(i = 1; i <= n; i++) {
        scanf("%d%d", &wt[i], &v[i]);
    }

    knapsack();
    printsolution();

    printf("\nObjects selected in knapsack:\n");
    printf("Object\tWeight\tProfit\n");

    for(i = 1; i <= n; i++) {
        if(x[i] == 1)
            printf("%d\t%d\t%d\n", i, wt[i], v[i]);
    }

    printf("\nMaximum profit = %d\n", V[n][W]);

    return 0;
}

int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

void knapsack() {
    int i, j;

    printf("\nGenerating solution matrix:\n");

    for(i = 0; i <= n; i++) {
        for(j = 0; j <= W; j++) {
            if(i == 0 || j == 0)
                V[i][j] = 0;
            else if(j < wt[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j],
                              V[i - 1][j - wt[i]] + v[i]);

            printf("%3d", V[i][j]);
        }
        printf("\n");
    }
}

void printsolution() {
    int i = n, j = W;

    while(i != 0 && j != 0) {
        if(V[i][j] != V[i - 1][j]) {
            x[i] = 1;
            j = j - wt[i];
        }
        i--;
    }
}