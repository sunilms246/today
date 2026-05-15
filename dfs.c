#include <stdio.h>
#include <stdlib.h>

int a[10][10], notvisted[10], visited[10], n, i,j;
void dfs(int v){
    for(i=0; i<n; i++){
        if(a[v][i]!=0 && visited[i] ==0){
            visited[i] = 1;
            printf("%d  ", i);
            dfs(i);
        }
    }
}

int main(){
    int v;
    printf("\nEnter the number of vertices : ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        visited[i] =0;
    }
    printf("\nEnter adjacency matrix for the given graph:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter starting vertex : ");
    scanf("%d", &v);
    printf("\nDFS traversal is :");
    visited[v] = 1;
    printf("%d  ", v);
    dfs(v);

    j=0;
    for(i=0; i<n; i++){
        if(visited[i]==0)
            notvisted[j++] = i;
    }
    if(j==0){
        printf("\nAll vertices are reachable from starting vertex %d ", v);
    }
    else{
        printf("\nFollowing verteces are not reachable form starting vertex %d \n", v);
        for(i=0; i<j; i++){
            printf("%d  ", notvisted[i]);
        }
    }
}