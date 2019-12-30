//michael silianov + evgeney golovachov
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

void swap(int* max, int* arr);
int* find_max(int* arr, int* max, int i);
void max_sort(int* arr, int i);
int binary_search(int* arr, int num, int start, int end);
int print(int* arr, int i, int N);
void input(int* arr, int N);

void main() {
    int max_index;
    int N, * arr, num;

    printf("enter the size of the arr\n");
    scanf("%d", &N);
    arr = (int*)malloc(sizeof(int) * N); // create arr in the lenght the user choice
    input(arr, N);
    max_sort(arr, N); // sort the arr from mion at 0 and max at end of arr
    print(arr, N, N); // prints the arr

    printf("enter the number you whant to find in the arr\n");
    scanf("%d", &num);

    max_index = binary_search(arr, num, 0, N); // serch from the number that the user entered before
    if (max_index != -1) {// if the number found print its index
        printf("the number %d is in index:%d\n", num, max_index);
    }
    else { // if not found than prints a message
        printf("Number not found\n");
    }
}

int binary_search(int* arr, int num, int start, int end) {
    int length = end - start;
    int mid = start + length / 2 + length % 2; // count the midle of the courect arr

    if (length == 1) return -1; // 

    if (arr[mid] == num) { //will return the index were the nuber is if he in the arr
        return mid;
    }
    else {// if he dont will check if it biger or leser than the corect number
        if (arr[mid] > num) {
            binary_search(arr, num, start, mid);// if lesser than will put the mid index as the end of arr 
        }
        else {
            if (arr[mid] < num) {
                binary_search(arr, num, mid, end);//if biger than will put the mid index as the start if arr
            }
        }
    }
}

void max_sort(int* arr, int i) {
    int* max; int temp;
    int* max_index;

    if (i > 0) {
        max = &arr[0]; //stor the 0 number as max 
        max_index = find_max(arr, max, i); // call function to comper max to all numbers

        if (*max_index > arr[i]) {
            swap(max_index, &arr[i]); //swap function
        }

        max_sort(arr, i - 1);
    }
}

void swap(int* max, int* arr) {//swap function
    int temp = *arr;
    *arr = *max;
    *max = temp;
}

int* find_max(int* arr, int* max, int i) {
    if (*max < *arr) {// if the corect max lesser than the number in the arr will stor the number in max
        max = arr;
    }

    if (i > 0) { //gose from lust place in the arr to 0 
        find_max(arr + 1, max, i - 1);
    }
    else {
        return max;
    }
}

int print(int* arr, int i, int N) {// print the arr
    if (i > 0) {
        printf("%d ", arr[N - i]);
        print(arr, i - 1, N);
    }
    else {
        printf("\n");
    }
}
void input(int* arr, int N)// inpuit function
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("enter the %d number:\n", i);
        scanf("%d", &arr[i]);
    }
}