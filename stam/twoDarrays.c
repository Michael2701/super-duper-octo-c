#include <stdio.h>
#define R 2
#define C 2 

void fillArr1( int a[][C] , int, int);
void fillArr2( int* );
void print2D( int* );

void main(){
    int a[R][C];

    // fillArr1(a, 2, 2);
    fillArr2( (int*)a );
    print2D( (int*)a );
}


void print2D( int* a ){
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("%d ", *(a+i*C+j) );
        }
    }
}


void fillArr1( int a[][C], int i2, int j2){

    printf("Enter an integer \n");
    for(int i = 0; i < i2; i++)
    {
        for(int j = 0; j < j2; j++)
        {
            scanf("%d", &a[i][j] ); 
        }
    }
}

void fillArr2( int* a ){
    printf("Enter an integer \n");
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            scanf("%d", a+i*C+j ); 
        }
    }
}

