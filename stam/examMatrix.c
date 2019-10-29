#include <stdio.h>
#define N 4

void print2D(int* m);
void input(int m[][N]);
int matrix(int m[][N]);

void main(){
    int mrx[N][N];
    input(mrx);
    print2D((int*)mrx);
    printf("%d\n",matrix(mrx));
}


int matrix(int m[][N]){
    int end = N-1;
    int isTop = 1;
    int isBot = 2;

    for(int i = 0; i < N; i++, end--)
    {
        for(int j = 0; j < end; j++)
        {
            if(m[i][j] != 0)
            {
                isTop = 0;
            } 
        }
    }

    end = 1;

    for(int i = N-1; i >= 0; i--, end++)
    {
        for(int j = end; j < N; j++)
        {
            if(m[i][j] != 0)
            {
                isBot = 0;
            } 
        }
    }

    return (isTop + isBot);
}


void input(int m[][N]){
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}

void print2D( int* a ){
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", *(a+i*N+j) );
        }
        printf("\n");
    }
}








