#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 6

void swap(int a1[], int a2[]);
void sort(int a[], int lng);
int binary_search(int a[], int lng, int num);

void main(){
    int b[6]={6,5,4,3,2,1};
    
    sort(b, N);

    for(int i = 0; i < N; i++){
        printf("%d ", b[i]);
    }

    printf("%d", binary_search(b, N, 3));
}

int binary_search(int a[], int lng, int num){
    int start = 0, end = lng-1, mid, res = -1;
    while(res == -1 && end > start){
        mid = start + (end - start)/2 + (end - start)%2;
        if(a[mid] > num){
            end = mid;
        }else{
            if(a[mid] < num){
                start = mid;
            }else{
                res = mid;
            }
        } 
    }
    return res;
}

void sort(int a[], int lng){
    int i,j;
    for(i = 0; i < lng; i++){
        for(j = 0; j < (lng-i-1); j++){
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void swap(int a1[], int a2[]){
    int p;
    p = *a1;
    *a1 = *a2;
    *a2 = p;
}