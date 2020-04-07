#include <stdio.h>
#include <math.h>
#define isUpper(a)((a) >= ('A') && a <= ('Z') ? 1 : 0)
#define toLowerCase(a) isUpper((a)) ? (a)+32 : (a)


void main(){

    char a = 'K';
    int c =  toLowerCase(a);

    printf("%c", c);

}