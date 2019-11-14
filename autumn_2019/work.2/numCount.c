//Evgeney Golovochov & Michael Silianov
#include <stdio.h>
#define N 3

void input(int arr[][N]);

void main() {
    int i, j, a;
    int arr[N][N];
    int count[10] = {0};
    input(arr);

    // counts how many times appears each number
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            count[ arr[i][j] ]++;
        }
    }

    // prints an array of the counters 
    for (a = 0; a < 10; a++) {
        printf("number %d appears %d times \n", a, count[a]);
    }
}

//Function collects the number to the matrix  
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