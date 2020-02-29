// static rows number / dinamic columns
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 2
#define M 100

void input_arr(char* arr[], int l);
void free_arr(char* arr[], int l);

void main(){
    char* arr[N] = {0};
    input_arr(arr,N);
    free_arr(arr,N);
}

void input_arr(char* arr[], int l){
    char tmp[M] = {0};
    int i;
    for(i = 0; i < l; i++){
        printf("Please enter a string ");
        scanf("%s", tmp);
        arr[i] = (char*)malloc(sizeof(char)*(strlen(tmp)+1));
        if( arr[i] ){
            strcpy(arr[i], tmp);
        }
        else{
            exit(1);
        }
    }
}

void free_arr(char* arr[], int l){
    int i;
    for(i = 0; i < l; i++){
        printf("%s\n",arr[i]);
        free(arr[i]);
    }
}


