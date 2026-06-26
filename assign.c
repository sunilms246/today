#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

int cost[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int minCost = INT_MAX;
int bestAssign[N];   

int lowerBound(int level, bool assigned[]) {
    int bound = 0;

    for (int i = level; i < N; i++) {
        int min = INT_MAX;

        for (int j = 0; j < N; j++) {
            if (!assigned[j] && cost[i][j] < min) {
                min = cost[i][j];
            }
        }
        bound += min;
    }

    return bound;
}

void assign(int level, int currentCost, bool assigned[], int currentAssign[]) {

    if (level == N) {
        if (currentCost < minCost) {
            minCost = currentCost;

            for (int i = 0; i < N; i++)
                bestAssign[i] = currentAssign[i];
        }
        return;
    }

    for (int j = 0; j < N; j++) {

        if (!assigned[j]) {

            assigned[j] = true;
            currentAssign[level] = j;

            int newCost = currentCost + cost[level][j];
            int bound = newCost + lowerBound(level + 1, assigned);

            if (bound < minCost) {
                assign(level + 1, newCost, assigned, currentAssign);
            }

            assigned[j] = false; 
        }
    }
}

int main() {

    bool assigned[N] = {false};
    int currentAssign[N];

    int initialBound = lowerBound(0, assigned);
    printf("Initial Lower Bound = %d\n\n", initialBound);

    assign(0, 0, assigned, currentAssign);

    printf("Minimum Cost = %d\n", minCost);

    printf("\nOptimal Assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Job %d\n", i + 1, bestAssign[i] + 1);
    }

    return 0;

}