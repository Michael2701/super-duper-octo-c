#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
#define M 40

int in_array(int a[], int length, int x);
int two_arrs(int a[20], int[20]);


int main()
{
    int a[N] = {1,2,2,3,4,6,2,7,8,9,9,9,9,9,2,3,4,66,2,9};
    int b[N] = {2,2,2,3,4,5,7,8,9,7,12,23,4,5,5,5,5,4,4,7};

    two_arrs(a, b);
}

int two_arrs(int a[N], int b[N]){
    int i, j, is_good = 1, temp[M], index = 0;
    for(i = 0; i < 20; i++){
        if( a[i] < 0 || b[i] < 0){
            is_good = -1;
            i = 20;
        }
    }
    if(is_good == 1){
        for(i = 0; i < N; i++){
            if(!in_array(a,N,b[i]) && !in_array(temp,M,b[i])){
                temp[index] = b[i]; index++;
            }
            if(!in_array(b,N,a[i]) && !in_array(temp,M,a[i])){
                temp[index] = a[i]; index++;
            }
        }
    }
    for(i = 0; i < index; i++){
        printf("%3d", temp[i]);
    }
    printf("\n");
    return is_good;
}

int in_array(int a[], int length, int x){
    int i, in_arr = 0;
    for(i = 0; i < length; i++){
        if(a[i] == x){
            in_arr = 1;
            i = 20;
        }
    }
    return in_arr;
}

