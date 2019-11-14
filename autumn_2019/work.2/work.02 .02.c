#include <stdio.h>
#define N 3

void input(int arr[][N]);
int checkTop(int arr[][N]);
int checkBottom(int arr[][N]);

void main() {
    int is_top, is_bottom;
    int arr[N][N];
    input(arr);

    is_top    = checkTop(arr);
    is_bottom = checkBottom(arr);

    if (is_top && is_bottom) {
        printf("Matrix is top and bottom");
    }
    else if (is_top) {
        printf("Matrix is top");
    }
    else if (is_bottom) {
        printf("Matrix is bottom");
    }
    else {
        printf("Matrix is not top and not bottom");
    }

}


int checkTop(int arr[][N]) {
    int flag = 1, i,j;
    for (i = 0; i < N && flag; i++ ) {
        for (j = i+1; j < N && flag; j++) {
            if (arr[i][j] != 0) flag = 0;
        }
    }
    return flag;
}

int checkBottom(int arr[][N]) {
    int flag = 1, i, j;
    for (i = 1; i < N && flag; i++) {
        for (j = 0; j < i && flag; j++) {
            if (arr[i][j] != 0) flag = 0;
        }
    }
    return flag;
}

void input(int arr[][N]){
    int i,j;
    for(i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Enter a number\n");
            scanf("%d", &arr[i][j]);
        }
    }
}