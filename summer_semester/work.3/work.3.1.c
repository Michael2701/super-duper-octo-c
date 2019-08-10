/*=====================================
    מיכאל סיליאנוב, יבגני גולובוציוב   
==================================== */
#include <stdio.h>
#define N 3

int calc(int arr1[N], int arr2[N], int *summ);
int fillArray(int *arr, int size);
int printArray(int arr[], int size);

void main(){
    int arr1[N], arr2[N], summ = 0;
    
    fillArray(arr1, N);
    fillArray(arr2, N);

    printArray(arr1, N);
    printArray(arr2, N);

    calc(arr1, arr2, &summ);
    printf("The summ is: %d\n", summ);
}

int calc (int arr1[], int arr2[], int *summ){
    for(int i = 0; i < N; i++){
        *summ += (arr1[i] *arr2[i]);
    }
}

int fillArray(int arr[], int size){
    static int index = 1;
    printf("Please enter %d numbers for array %d \n", size, index);
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    index++;
};

int printArray(int arr[], int size){
    printf("\n[ ");
    for(int i = 0; i < size; i++){
        i+1 == size ? printf("%d", arr[i]) : printf("%d, ", arr[i]) ;
    }
    printf(" ]\n");
}



















