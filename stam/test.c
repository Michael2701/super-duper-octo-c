#include <stdio.h>

void merge(char* , char*);

void main(){
    char a[50] = "Hello";
    char b[6] = "World";
    merge(a, b);
    printf("%s", a);
}

void merge(char* a, char* b){
    for(;*a; a++);
    for(;*b; b++, a++){
        *a = *b;
    }
    *a = '\n';
}


