// dinamic rows number / static columns
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 2

typedef int one_row[N];

int fill_arr(one_row* arr[]);
void free_arr(one_row* arr[], int lng);
void mprint(one_row* arr, int lng);

void main(){
    int lng;
    one_row* arr = (one_row*)malloc(sizeof(one_row));

    lng = fill_arr(&arr);
    mprint(arr, lng);
    free_arr(&arr,lng);
}

int fill_arr(one_row* arr[]){
    int i = 0, j = 0, flag = 1;
    one_row* p;

    while(flag){
        for(i = 0; i < N; i++){
            printf("Please enter a number: ");
            scanf("%d", &(*arr)[j][i]);
        }
        printf("To continue press 1, to stop and print 0: ");
        scanf("%d", &flag);
        if(flag){
            p = (one_row*)realloc(*arr, sizeof(one_row)*(j+2));
            if(p){
                *arr = p;
                j++;
            }
        }
    }
    return j+1;
}

void mprint(one_row* arr, int lng){
    int i,j;
    for(j = 0; j < lng; j++){
        for(i = 0; i < N; i++){
            printf("arr[%d][%d] = %d ", j, i, arr[j][i]);
        }
        printf("\n");
    }
}

void free_arr(one_row* arr[], int lng){
    int j;
    for(j = 0; j < lng; j++){
        free((*arr)[j]);
    }
}



