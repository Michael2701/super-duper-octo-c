#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

void int_input(int* leng);
void char_input(char** str, int len);
void print_chars(char** str, int len);
void free_chars(char** str, int len);

void analize(char** str, int len);
void check_lang(char* str, int len);
int filipino(char* str, int len);
int korean(char* str, int len);
int japanese(char* str, int len);
int compare(char* str1, char* str2, int i);

void main(){
    int length;
    char** str;

    int_input(&length);
    str = (char**)malloc(length*(sizeof(char*)));
    char_input(str, length);
    // print_chars(str, length);

    analize(str, length);
}

void check_lang(char* str, int len){
    switch(str[len-1]){
        case 'o':
            filipino(str, len-1);
        break;
        case 'u':
            japanese(str, len-1);
        break;
        case 'a':
            korean(str, len-1);
        break;
        default:
            printf("Not known language\n");
    }
}

int compare(char* str1, char* str2, int i){
    if(i){
        if(*str1 != *str2){
            return 0;
        }else{
            compare(str1-1, str2-1, i-1);
        }
    }else{
        return 1;
    }
}

int filipino(char* str, int len){
    char suff[] = "po";
    char output[] = "FILIPINO\n";
    if( compare(suff+(strlen(suff)-1), str+len, strlen(suff)) ){
        printf("%s", output);
    }else{
        printf("Not known language\n");
    }
}

int japanese(char* str, int len){
    char suff1[] = "desu";
    char suff2[] = "masu";
    char output[] = "JAPANESE\n";
    if( 
        compare(suff1+(strlen(suff1)-1), str+len, strlen(suff1)) || 
        compare(suff2+(strlen(suff2)-1), str+len, strlen(suff2)) 
    ){
        printf("%s", output);
    }else{
        printf("Not known language\n");
    }
}

int korean(char* str, int len){
    char suff[] = "mnida";
    char output[] = "KOREAN\n";
    if( compare(suff+(strlen(suff)-1), str+len, strlen(suff)) ){
        printf("%s", output);
    }else{
        printf("Not known language\n");
    }
}

void analize(char** str, int len){
    if(len){
        int str_len = strlen(*str);
        check_lang(*str, str_len);   
        analize(str+1, len-1);
    }else{
        free_chars(str, len);
    }
}

void char_input(char** str, int len){
    char temp[N];
    if(len){
        printf("Enter a string: ");
        scanf("%s",temp);
        *str = (char*)malloc( (strlen(temp)+1)*sizeof(char) );
        if(*str){
            strcpy(*str, temp);
        }else{
            exit(1);
        }
        char_input(str+1, len-1);
    }
}

void int_input(int* leng){
    int num;
    printf("Enter input length: ");
    scanf("%d",&num);

    if(num >= 1 && num <= 30){
        *leng = num;
    }else{
        int_input(leng);
    }
}

void print_chars(char** str, int len){
    if(len){
        printf("%s\n", *str);
        print_chars(str+1, len-1);
    }
}

void free_chars(char** str, int len){
    if(len){
        free(*str);
        free_chars(str+1, len-1);
    }
}



