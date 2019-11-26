#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 3


typedef struct{
    char* name;
    char phone[12];
} phone_list;

int input(phone_list *a);
void free_name(phone_list *a, int size);
void print_phone_list(phone_list *a, int size);

void main(){
    phone_list PhoneList[N];
    int i,flag = 1;

    for(i = 0; i < N && flag; i++){
        flag = input(&PhoneList[i]);
    }

    // print_phone_list(PhoneList, N);
    // free_name(PhoneList, N);
}


int input(phone_list *p){
    int res = 0;
    char tmp[100] = {0};

    printf("Please enter name\n");
    gets(tmp);
    p->name = (char*) malloc((strlen(tmp)+1)*sizeof(char));
    if(p->name){
        strcpy(p->name, tmp);
        printf("Please enter phone number");
        gets(p->phone); 
    }
    return res;
}

void print_phone_list(phone_list *a, int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%s: %s\n", a[i].name, a[i].phone);
    }
}

void free_name(phone_list *a, int size){
    int i;
    for(i = 0; i < size; i++){
        free(a[i].name);
    }
}













