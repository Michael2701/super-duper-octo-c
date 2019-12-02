#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 50

typedef struct{
    int id;
    char* first_name;
    char* last_name;
    char* phone;
} user;

typedef struct{
    char id[25];
    char first_name[25];
    char last_name[25];
    char phone[25];
} titles;

void insert_users(user** Users, int* size);
void get_last_name(char** last_name);
void get_first_name(char** first_name);
void get_phone(char** phone);
void print_users(user Users[], int size);
void save_to_csv(user Users[], int size);

void main()
{
    user* Users;
    int size = 1;
    Users = (user*)malloc(sizeof(user));

    insert_users(&Users, &size);
    print_users(Users, size);
    save_to_csv(Users, size);
}

void save_to_csv(user Users[], int size)
{
    int i;
    FILE* pwright = fopen("file.csv", "a");
    titles Titles = {
        "Id", "First Name", "Last Name", "Phone"
    };

    fprintf(pwright, "%s,%s,%s,%s\n", Titles.id, Titles.first_name, Titles.last_name, Titles.phone);

    for(i = 0; i < size; i++)
    {
        fprintf(pwright, "%d,%s,%s,%s\n", Users[i].id, Users[i].first_name, Users[i].last_name, Users[i].phone);
    }

    fclose(pwright);
}

void print_users(user Users[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("id:%3d\n", Users[i].id);
        printf(", first name:%3s\n", Users[i].first_name);
        printf(", last name:%3s\n", Users[i].last_name);
        printf(", phone:%3s\n", Users[i].phone);
    }
}

void insert_users(user** Users, int* size)
{
    int i = 0,more_users = 1;
    user* temp;
    while(more_users){
        temp = (user*)realloc(*Users,(i+2)*sizeof(user));
        if(temp){
            *Users = temp;
        }
        (*Users)[i].id = i+1;
        get_first_name( &(*Users)[i].first_name );
        get_last_name( &(*Users)[i].last_name );
        get_phone( &(*Users)[i].phone);
        printf("\n");

        printf("To stop press 0(zero)\n");
        printf("To continue press 1(one)\n");
        scanf("%d", &more_users);
        i++;
        *size = i;
    }
};

void get_first_name(char** first_name)
{
    char temp[N];
    do{
        printf("Enter first name(3-25 chars):\n");
        scanf("%s", temp);
    }
    while(strlen(temp) < 3 || strlen(temp) > 25);

    *first_name = (char*)malloc(strlen(temp + 1)*sizeof(char));
    strcpy(*first_name, temp);
};

void get_last_name(char** last_name)
{
    char temp[N];
    do{
        printf("Enter last name(3-25 chars):\n");
        scanf("%s", temp);
    }
    while(strlen(temp) < 3 || strlen(temp) > 25);

    *last_name = (char*)malloc(strlen(temp + 1)*sizeof(char));
    strcpy(*last_name, temp);
};

void get_phone(char** phone)
{
    char temp[N];
    do{
        printf("Enter phone number(7 nums):\n");
        scanf("%s", temp);
    }
    while(strlen(temp) < 9 || strlen(temp) > 9);

    *phone = (char*)malloc(strlen(temp + 1)*sizeof(char));
    strcpy(*phone, temp);
};
