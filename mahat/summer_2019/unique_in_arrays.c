#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 20

void find_unique(int arr1[], int arr2[], int** r, int* length);
void search(int arr1[], int arr2[], int** r, int* length);
int in_array(int arr[], int num);
void print_array(int r[], int length);


void main ()
{
    int a[N] = {1,2,2,3,4,6,2,7,8,9,9,9,9,9,2,3,4,6,2,17};
    int b[N] = {2,2,45,3,4,5,7,8,9,7,12,23,4,5,5,5,5,4,4,7};
    int* result = (int*)malloc(sizeof(int));
    int length = 1;

    find_unique(a, b, &result, &length);
    print_array(result, length);
    free(result);
}

void find_unique(int arr1[], int arr2[], int** r, int* length)
{
    search(arr1, arr2, r, length);
    search(arr2, arr1, r, length);
};

void search(int arr1[], int arr2[], int** r, int* length)
{
    int i;
    int* tmp;

    for(i = 0; i < N; i++)
    {
        if(!in_array(arr1, arr2[i]) && !in_array(*r, arr2[i]))
        {
            tmp = (int*)realloc(*r, (*length) * sizeof(int));
            if(tmp)
            {
                *r = tmp;
                (*r)[ (*length - 1) ] = arr2[i];
            }
            (*length)++;
        }
    }
};

int in_array(int arr[], int num)
{
    int i,exists = 0;
    for(i = 0; i < N && !exists; i++)
    {
        if(arr[i] == num) 
            exists = 1;
    }
    return exists;
};

void print_array(int r[], int length)
{
    int i;
    for(i = 0; i < length - 1; i++)
    {
        printf("%d ", r[i]);
    }
    printf("\n");
}





