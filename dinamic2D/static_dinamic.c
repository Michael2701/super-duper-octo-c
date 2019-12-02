#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 2

void static_dinamic(char* str1[], int num);
void print_array(char* str[], int num);


void main(){
    // create 2D array with static number of rows
    // and dinamic number of columns ( str1 )
    char* str1[N] = {0};
    static_dinamic(str1, N);
    print_array(str1, N);
}

void static_dinamic(char* str1[], int num)
{
    char tmp[100];
    int i; 

    for(i = 0; i < num; i++)
    {
        do{
            printf("Enter a string\n");
        }
        while(!scanf("%s", tmp));
        
        if(tmp){
            str1[i] = (char*)malloc((strlen(tmp)+1)*sizeof(char));
            strcpy(str1[i], tmp);
        }
    }
};

void print_array(char* str[], int num)
{
    int i;
    for(i = 0; i < num; i++)
    {
        printf("%s\n",str[i]);
    }
};












