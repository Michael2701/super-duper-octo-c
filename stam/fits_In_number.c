#include <stdio.h>
#define A 26
#define B 82
#define N 2
#define M 4


void how_it_fits();

void main(){
    how_it_fits();
}


void how_it_fits(){
    int i,j;
    for(i = 0; i <= B/N; i++){
        for(j = 0; j <= B/N; j++){
            if((i*N + j*M) == B && (i + j) == A){
                printf("2: %d, 4: %d\n", i, j);
            }
        }   
    }
}














