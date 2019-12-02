#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 2

typedef int one_row[N];  

void fill(one_row** a, int n);

void main(){
    int n = 0,i,j;
    one_row* arr;
    one_row* p;

    do{
        printf("Enter a number: %d ", n);
        scanf("%d", &n);
    }
    while(n < 0);

    arr = (one_row*)malloc(n * sizeof(one_row));
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("Enter a number: ");
            scanf("%d", &arr[i][j]);
        }
    }

    // fill(&arr, n);

    for(i = 0; i < n; i++)
    {
        printf("\n");
        for(j = 0; j < N; j++)
        {
            printf("%2d", arr[i][j]);
        }
        printf("\n");
    }

}

void fill(one_row** a, int n){
    one_row* p; int i,j;

    p = (one_row*)malloc(n * sizeof(one_row));
    
    if(p){
        *a = p;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("Enter a number: %d/%d ", i,j);
            scanf("%d", &((*a)[i][j]));
        }
    }
}

















