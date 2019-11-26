//michael silianov + evgeney golovachov
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 2
#define B 100
#pragma warning(disable:4996)



typedef struct {
	char name[20];
	char author[25];
	char producer[20];
	int count;

} book;

void make_book_list(book b[], int size);
void input(char temp[], int size);
void less_five(book b[]);


void main(){
    int i;
    book books[L];

    make_book_list(books, L);
    less_five(books);
}

void input(char temp[], int size){
    do{
        gets(temp);
    }
    while(strlen(temp) >= size); 
}

void less_five(book b[]){
    int i;
    for(i = 0; i < L; i++){
        if(b[i].count < 5){
            printf("%s\n", b[i].name);
            printf("%s\n", b[i].author);
            printf("%s\n", b[i].producer);
            printf("//============================//");
        }
    }
};

void make_book_list(book b[L], int size){
    
    int i;
    char temp[B];

    for(i = 0; i < L; i++){
        printf("Enter book name\n");
        input(temp, 20);
        strcpy(b[i].name, temp);
        
        printf("Enter book author name\n");
        input(temp, 25);
        strcpy(b[i].author, temp);

        printf("Enter book producer name\n");
        input(temp, 20);        
        strcpy(b[i].producer, temp);

        printf("Enter books number\n");
        scanf("%d", &b[i].count);
        int c = getchar();
    }

};



