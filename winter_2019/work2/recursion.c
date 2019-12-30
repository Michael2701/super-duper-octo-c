#include <stdio.h>
#include <stdlib.h>
#define N 9

void swap(int* max, int* arr);
int* find_max(int* arr, int* max, int i);
void max_sort(int* arr, int i);
int binary_search(int arr[], int num, int start, int end);
int print(int arr[], int i);

void main(){
    int index;
    int arr[] = {100,3,5,22,8,87,5,1,7};
    
    max_sort(arr, N);
    print(arr, N);

    index = binary_search(arr, 8, 0, N);

    if(index != -1){
        printf("index is: %d\n", index);
    }else{
        printf("Number not found\n");
    }
}

int binary_search(int arr[], int num, int start, int end){
    int length = end - start;
    int mid = start+length/2+length%2;

    if(length == 1) return -1; 

    if(arr[mid] == num){
        return mid;
    }else{
        if(arr[mid] > num){
            binary_search(arr, num, start, mid);
        }else{
            if(arr[mid] < num){
                binary_search(arr, num, mid, end);
            }
        }
    }
}

void max_sort(int* arr, int i){
    int* max;int temp;
    int* max_index;

    if(i > 0){
        max = &arr[0];
        max_index = find_max(arr,max,i);

        if(*max_index > arr[i]){
            swap(max_index, &arr[i]);
        }

        max_sort(arr, i-1);
    }
}

void swap(int* max, int* arr){
    int temp = *arr;
    *arr = *max; 
    *max = temp;
}

int* find_max(int* arr, int* max, int i){
    if(*max < *arr){
        max = arr;
    }

    if(i > 0 ){
        find_max(arr+1, max, i-1);
    }else{
        return max;
    }
}

int print(int arr[], int i){
    if(i > 0){
        printf("%d ", arr[N-i]);
        print(arr, i-1);
    }
    else{
        printf("\n");
    }
}
