//Evgeney Golovochov & Michael Silianov
#include <stdio.h>
#define N 3

// functions definitions
void input(int arr[][N]);
int checkTop(int arr[][N]);
int checkBottom(int arr[][N]);

void main() {//Main function declares the array, calls to upper and lower funcs and prints the result depends on return of both funcs 
    int is_top, is_bottom, result;
    int arr[N][N];
    input(arr);


    is_top    = checkTop(arr);
    is_bottom = checkBottom(arr);

	result = is_top + is_bottom;
	switch (result)
	{
	    case 0: printf("Matrix is not upper and not lower.");
		     	break;
	    case 1: printf("Matrix is upper.");
		    	break;
    	case 2: printf("Matrix is lower.");
			    break;
		case 3: printf("Matrix is upper & lower.");
	} 
}

// check if matrix belongs to upper type
// returns  0 or 1
int checkTop(int arr[][N]) {
    int flag = 1, i,j;
    for (i = 0; i < N && flag; i++ ) {
        for (j = i+1; j < N && flag; j++) {
            if (arr[i][j] != 0) flag = 0;
        }
    }
    return flag;
}
// check if matrix belongs to lower type
// returns  0 or 1
int checkBottom(int arr[][N]) {
    int flag = 2, i, j;
    for (i = 1; i < N && flag; i++) {
        for (j = 0; j < i && flag; j++) {
            if (arr[i][j] != 0) flag = 0;
        }
    }
    return flag;
}

// 2d matrix input
void input(int arr[][N]){//Collects numbers to the array 
    int i,j;
    for(i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Enter a number\n");
            scanf("%d", &arr[i][j]);
        }
    }
}