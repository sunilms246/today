#include<stdio.h>
#include <stdlib.h>
#include <math.h>
int n, x[20];
int solutioncount = 0;
void nqueen(int);
int place(int , int);
void printsolution();
int main(){
    printf("\nEnter the no of queens: ");
    scanf("%d", &n);
    if(n<=3){
        printf("Solution not exits");
        exit(1);
    }
    nqueen(1);
    printf("total no of solution:%d", solutioncount);
}

void nqueen(int k){
    int j;
    for(j=1; j<=n; j++){
        if(place(k, j)){
            x[k] = j;
            if(k==n){
                ++solutioncount;
                printsolution();
                printf("\n");
            }
            else{
                nqueen(k+1);
            }
        }
    }
}

int place(int k, int xk){
    int i;
    for(i=1; i<k; i++){
        if((x[i]==xk) || abs(i-k) == abs(x[i]- xk)){
            return 0;
        }
    }
    return 1;
}

void printsolution(){
    int i,j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(x[i]==j){
                printf("Q ");
            }
            else{
                printf("* ");
            }
        }
        printf("\n");
    }
}