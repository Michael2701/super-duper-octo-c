/*=====================================
    מיכאל סיליאנוב, יבגני גולובוציוב   
==================================== */
#include <stdio.h>
#define LENG 3

int equal_arrays(int [], int []);
void input(int [], int);

void main(){
    int j,num, arr1[LENG], arr2[LENG];

    printf("Please enter number of array pairs\n");
    scanf("%d", &num);
    for(j = 0; j < num; j++){
        input(arr1, LENG);
        input(arr2, LENG);
        if(equal_arrays(arr1, arr2))
        {
            printf("Arrays are equal\n");
        }
        else
        {
            printf("Arrays are not equal\n");
        }
    }
    getchar();
}

int equal_arrays(int arr1[], int arr2[]){
    int i,flag = 1;
    for(i = 0; i < LENG; i++)
    {
        if(arr1[i] != arr2[i])
        {
            flag = 0;
            i = LENG;
        }
    }
    return flag;
};

void input(int arr[], int length){
    int i;
    printf("Please enter %d array items\n", length);
    for(i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
}

