//michael silianov + evgeney golovachov
#include <stdio.h>
#include <stdlib.h>
#define N 5


// find and print beginning of siquences
// of same numbers 'size' length
void func(int mat[N][N], int size);

void main() {
    int mat[N][N] = {
        {1,2,3,4,5},
        {2,1,1,1,1},
        {2,1,5,6,7},
        {2,1,6,7,8},
        {2,8,7,8,9}
        };
    func(mat, 3);
}

void func(int mat[N][N], int size) 
{
    int i, j, c = 0, d = 0;
    for (i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            if (mat[i][j] == mat[i][j+1] ) {
                ++c;
                if (c >= size-1) {
                    printf("%11s [%d][%d]\n", "horizontal", i, j-size+2);
                }
            }else{
                c = 0;
            }
            if (mat[j][i] == mat[j+1][i]) {
                ++d;
                if (d >= size - 1) {
                    printf("%11s [%d][%d]\n","vertical", j-size+2, i);
                }
            }else{
                d = 0;
            }
        }
    }
}
