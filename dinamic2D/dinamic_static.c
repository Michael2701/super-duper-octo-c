#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 2

typedef int one_row[N];  

void dinamic_static(one_row** arr, int* n, int num);
void print_array(one_row* arr, int num1, int num2);

void main(){
    // create 2D array with dinamic number of rows
    // and static number of columns ( str1 )
    int n = 0;
    one_row* arr;
    dinamic_static(&arr, &n, N);
    print_array(arr, n, N);

}

void dinamic_static(one_row** arr, int* n, int num){
    int i,j;
    one_row* p;
    do{
        printf("Enter a number: ");
        scanf("%d", n);
    }
    while(n < 0);

    *arr = (one_row*)malloc((*n) * sizeof(one_row));
    
    for(i = 0; i < *n; i++)
    {
        for(j = 0; j < num; j++)
        {
            printf("Enter a number: %d/%d ", i,j);
            scanf("%d", &(*arr)[i][j]);
        }
    }

}

void print_array(one_row* arr, int num1, int num2)
{
    int i,j;
    for(i = 0; i < num1; i++)
    {
        for(j = 0; j < num2; j++)
        {
            printf("%2d", arr[i][j]);
        }
        printf("\n");
    }
};


