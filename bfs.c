#include<stdio.h>
#include<stdlib.h>

int a[10][10], q[10], notvisited[10], visited[10], f= -1, r=-1, n;
void bfs(int v){
    for(int i=0; i<n; i++){
        if(a[v][i]!=0 && visited[i]==0){
            r = r+1;
            q[r] = i;
            visited[i] = 1;
            printf("%d  ", i);
        }
    }
    f= f+1;
    if(f<=r){
        bfs(q[f]);
    }
}

int main(){
    int i,j,k,v;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        visited[i] = 0;
    }
    printf("\nEnter the adjacency martix for the given graph:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter the starting vertex :");
    scanf("%d", &v);
    f=r=0;
    q[r] = v;
    printf("\nBFS traversal is : ");
    printf("%d  ", v);
    visited[v] = 1;
    bfs(v);
    
    j=0;
    for(i=0; i<n; i++){
        if(visited[i]==0){
            notvisited[j++] = i;
        }
    }
    if(j==0){
        printf("\nAll vertices are reachable from staritng vertex %d ", v);
    }
    else{
        printf("\nFollowing vertices are not reachable form starting vertex %d\n", v);
        for(i=0 ; i<j; i++){
            printf("%d  ", notvisited[i]);
        }
    }
}