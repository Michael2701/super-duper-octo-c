#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 3

void func(int** arr);


void main(){
    int i;
    int* p;
    int* arr = (int*)malloc(sizeof(int));

    func(&arr);

    for(i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
}

void func(int** arr){
    int i; int* p;

    for(i = 0; i < N; i++){
        p = (int*)realloc(*arr, (1+i)*sizeof(int));

        if(p){
            *arr = p;
            (*arr)[i] = i;
        }
    }
}

