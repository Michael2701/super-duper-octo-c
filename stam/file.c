#include <stdio.h>

int str_len(char*);
void flip(char*, char*);
void parser(char*);

void main(){
 char a[50] = "Hello <world>, <Michael> !";
 parser(a);
 printf("%s", a);
}

void parser(char* a){
    char* temp; char* p = a;
    
    for(;*p;p++){
        if(*p == '<'){
            *p = ' ';
            temp = p;
        }
        if(*p == '>'){
            *p = ' ';
            flip(temp, p);
        }
    }

}
void flip(char* start, char* end){
    char temp;
    for(;start <= end; start++, end--){
        temp = *start;
        *start = *end;
        *end = temp; 
    }
}

int str_len(char* a){
    int len = 0;
    for(;*(a+len);len++);
    return len;
}
















