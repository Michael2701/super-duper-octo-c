#include <stdio.h>
#define N 3

void input(int arr[][N]);


void main() {
    int i, j, a;
    int arr[N][N];
    int count[10];
    input(arr);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            count[ arr[i][j] ]++;
        }
    }

    for (a = 0; a < 10; a++) {
        printf("number %d appears %d times \n", a, count[a]);
    }
}




void input(int arr[][N]){
    int i,j;
    for(i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Enter a number 0-9\n");
            do {
                scanf("%d", &arr[i][j]);
            } 
            while (arr[i][j] < 0 || arr[i][j] > 9);
        }
    }
}