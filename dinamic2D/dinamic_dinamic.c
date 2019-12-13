#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 2


void dinamic_dinamic(char** arr, int* n);
void print_array(char* arr[], int num);

void main(){
    int n = 0;
    char** arr;
    // create 2D array with dinamic number of rows
    // and dinamic number of columns ( arr )
    dinamic_dinamic(arr, &n);
    printf("=%d=\n",n);
    print_array(arr, n);
}

void dinamic_dinamic(char** arr, int* n){
    int i;
    char tmp[100] = {0};

    do{
        printf("Enter a number: ");
        scanf("%d", n);
    }
    while(n < 0);

    printf("n=%d\n",*n);
    *arr = (char*)malloc((*n) * sizeof(char*));
    
    for(i = 0; i < *n; i++)
    {
        printf("Enter a string: ");
        scanf("%s", tmp);
        if(tmp){
            arr[i] = (char*)malloc((strlen(tmp)+1)*sizeof(char));
            strcpy(arr[i], tmp); 
        }
    }
}

void print_array(char* arr[], int num)
{
    int i;
    for(i = 0; i < num; i++)
    {
        printf("%s\n", arr[i]);
    }
};


