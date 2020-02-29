#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 25
#define M 100

typedef struct foo{
    char str[N];
    int val;
}Foo;

int input_struct(Foo** arr);

void main(){
    int lng, i;
    Foo* arr;
    arr = (Foo*)malloc(sizeof(Foo));
    lng = input_struct(&arr);
    for(i = 0; i < lng; i++){
        printf("%s: %d\n", arr[i].str, arr[i].val);
    }
}

int input_struct(Foo** arr){
    int i = 0, flag = 1;
    char tmp[M];
    while(flag){
        printf("Please enter string ");
        scanf("%s",tmp);
        strcpy((*arr)[i].str, tmp);
        printf("Please enter number ");
        scanf("%d", &(*arr)[i].val);
        printf("Continue: 1, Stop: 0 ");
        scanf("%d", &flag);
        if(flag){
            *arr = (Foo*)realloc(*arr, sizeof(Foo)*(i+2));
            i++;
        }
    }
    return i+1;
}



