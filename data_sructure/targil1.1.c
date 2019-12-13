
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 5

/*
    clone_arr: n (size) iterations = O(n)

    bubble_sort: ( (1 + (size -1)) / 2 ) * size, 
                 ( size / 2 ) * size
                 size*size=size^2, 
                 '/2' is not important,
                 remains size^2 => O(n^2)

    find_indexes: it has two independed nested loops each one with size iterations => O(n^2)

    bottom line: O(n) + O(n^2) + O(n^2) => O(n^2)

*/

//copy values from one array to other
// both array should be the same size
void clone_arr(int arr1[], int arr2[], int size); 

// makes bubble sort of given array
void bubble_sort(int arr[], int size);

// find indexes of numbers off sorted array in original
// arr1 - original, arr2 - sorted, arr3 - result
void find_indexes(int arr1[], int arr2[], int arr3[], int size);

// print result to cmd
void print_result(int arr2[], int arr3[], int size);

void main(){
    int i,j;
    int A[N] = {2,8,12,-4,0};
    int A2[N];
    int A3[N];

    clone_arr(A, A2, N);
    bubble_sort(A2, N);
    find_indexes(A, A2, A3, N);
    print_result(A2, A3, N);
}

void find_indexes(int arr1[], int arr2[], int arr3[], int size){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(arr2[i] == arr1[j]){
                arr3[i] = j;
            }
        }
    }
}

void bubble_sort(int arr[], int size){
    int i, j, tmp;
    for(i = 0; i < size; i++){
        for(j = 1; j < (size - i); j++){
            if(arr[j] < arr[j-1]){
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}

void clone_arr(int arr1[], int arr2[], int size){
    for(int i = 0; i < size; i++){
        arr2[i] = arr1[i];
    }
}

void print_result(int arr2[], int arr3[], int size){
    for(int i = 0; i < N; i++){
        printf("%d ",arr2[i]);
    }
    printf("\n");
    for(int i = 0; i < N; i++){
        printf("%d ",arr3[i]);
    }
    printf("\n");
}











