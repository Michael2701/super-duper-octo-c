//michael silianov + evgeney golovachov
#include <stdio.h>
#include <stdlib.h>
# define N1 10
# define N2 5

void func(int* arr1, int* arr2);

void main(){
    int i = 0;
    int arr1[N1] = {25, 20, 15, 10, 9, 7, 5, 3, 2,-1};
    int arr2[N2] = {30, 4, 15, 1, -1};

    func(arr1,arr2);

    // while(*(arr2+i) != -1){
    //     printf("%3d", *(arr2+i));
    //     i++;
    // }
    // printf("%3d", *(arr2+i));

}

void func(int* arr1, int* arr2){
    int i = 0, j = 0, flag;
    while(*(arr2+j) != -1){
        i = 0;
        flag = 1;
        while(*(arr1+i) != -1 && flag){
            if(*(arr2+j) > *(arr1+i)){
                *(arr2+j) = i;
                flag = 0;
            }
            i++;
        }
        if(flag) *(arr2+j) = i;
        j++;
    }
}





