#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

int funcA(int mat[][N], int* perimeter);
int funcB(int mat[][N]);

int main()
{
    int perimenter = 3;
    int mat[N][N] = { 
        {1,1,1,1,1},
        {2,2,2,2,2},
        {3,3,3,3,3},
        {4,4,4,4,4},
        {5,5,5,5,5}
    };

    printf("perimeter summ = %d\n", funcA(mat, &perimenter));
    printf("smalest sum has perimeter: %d\n", funcB(mat));
}

int funcB(int mat[][N]){
    int i = 0, min, tmp, index = 0;
    min = funcA(mat, &index);
    for(i = 1; i < (N/2+N%2); i++){
        tmp = funcA(mat,&i);
        if(tmp < min){
            min = tmp;
            index = i;
        }
    }
    return index;
}

int funcA(int mat[][N], int* perimeter){
    int i,j,result = 0;
    if(*perimeter > (N/2+N%2)){
        *perimeter = -1;
    }else{
        for(i = *perimeter; i < (N-*perimeter); i++){
            for(j = *perimeter; j < (N-*perimeter); j++){
                if(i == *perimeter || i == (N-(*perimeter+1))){
                    result += mat[i][j];
                }else{
                    if(j == *perimeter || j == (N-(*perimeter+1))){
                        result += mat[i][j];
                    }
                }
            }
        }
    }
    return result;
}
