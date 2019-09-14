#include <stdio.h>

void flip(char*, int);
int myAtoi(char*);
char myItoa(int*, char*);

void main(){

    char ch[100] = "80d7";
    int  num = 1234;
    char* p = ch;
    int* pn = &num;

    // printf("%d\n",myAtoi(p));

    myItoa(pn,ch);

    printf("%s", ch);

}


char myItoa(int* num, char* c){
    int i = 0;
    while(*num){
        *c = *num%10 + 48;
        *num/=10;
        c++;
        i++;
    }
    *c = '\n';
    flip(c-i, i);
}


int myAtoi(char* p){
    int res = 0;
    while(*p){
        if(*p > 57 || *p < 48) return res;
        res *= 10;
        res += (*p-48);
        p++;
    }
    return res;
}

void flip(char* start, int i){
    char temp;
    char* end = start + i;
    for(;start < end; start++, end--){
        temp = *start;
        *start = *end;
        *end = temp; 
    }
}











