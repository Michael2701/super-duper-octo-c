//michael silianov + evgeney golovachov
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define N 10

/* 
    find_max: n (size) iterations = O(n)
    
    find_sequences: 6 + 8 * size
    6 and 8 are not important => O(n) 

    O(n)
*/

// finds all accending and descending sequences in given array
void find_sequences(int a[], int b[], int size);

// find longest sequence of any type
void find_max(int a[], int size, int* max);


void main(){
    int i, max, c[N] = {0};
    int arr[N] = {10,8,6,7,14,12,5,3,1,9};

    find_sequences(arr, c, N);
    find_max(c, N, &max);

    printf("%d\n", max);
}

void find_max(int a[], int size, int* max){
    int i;  
    *max = a[0];
    
    for(i = 1; i < N; i++){
        if(a[i] > *max){
            *max = a[i];
        }
    }    
}


void find_sequences(int a[], int b[], int size){
    int i,j = 0, prev, c1 = 0, c2 = 0;

    prev = a[0];
    for(i = 1; i < N; i++){
        if(a[i] > prev){
            c1++;
            if(c2 != 0){
                b[j] = c2;
                c2 = 0;
                j++;
            }
        }
        if(a[i] < prev){
            c2++;
            if(c1 != 0){
                b[j] = c1;
                c1 = 0;
                j++;
            }
        }
        prev = a[i];
    }
}
















