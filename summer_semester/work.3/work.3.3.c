/*=====================================
    מיכאל סיליאנוב, יבגני גולובוציוב   
==================================== */
#include <stdio.h>
#define N 3

void input(int *arr);
int  exist(int *arr, int n, int elem);
int  common(int *arr1, int *arr2, int *arr3, int size);
void print(int *arr);

void main(){
    int arr1[N][N], arr2[N][N], arr3[N][N], elem;

    input((int *)arr1);
    print((int *)arr1);

    input((int *)arr2);
    print((int *)arr2);

    input((int *)arr3);
    print((int *)arr3);

    if( common( *arr1,  *arr2, *arr3, N) ){
        printf("Number exists\n");
    }else{
        printf("Number does not exist\n");
    }
}

void input(int *arr){
    printf("Please enter %d numbers\n",N*N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", ( arr+i*N )+j );
        }
    }
}

int exist(int *arr, int n, int elem){
    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if( *((arr+i*N)+j) == elem ) res = 1;
        }
    }
    return res;
}

int common(int *arr1, int *arr2, int *arr3, int size){
    int flag = 0;
    for(int i = 0; i < size && !flag; i++){
        for(int j = 0; j < N && !flag; j++){
            if( exist((int *)arr1, size, *((arr2+i*N)+j) ) ){ 
                flag = 1;
            }else if( exist((int *)arr1, size, *((arr3+i*N)+j) ) ){ 
                flag = 1;
            }else if( exist((int *)arr2, size, *((arr3+i*N)+j) ) ){ 
                flag = 1;
            }
        }
    }
    return flag;
}

void print(int *arr){
    printf("[");
    for(int i = 0; i < N; i++){
        printf("[ ");    
        for(int j = 0; j < N; j++){
            printf("%d ", *(( arr+i*N )+j) );
        }
        printf("]");
    }
        printf("]\n");
}












