#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

int digits_summ(int num);
char* make_arr(char str1[], char str2[]);
void str_rev(char digits[]);


void main(){
    int j,i = 0, summ = 0;
    char letters[] = "misha";
    char  digits[] = "12345"; 

    char* p = make_arr(letters, digits);
    printf("%s\n", p);

}

char* make_arr(char str1[], char str2[]){
    int i,j,counter = 0, summ = 0;
    char* temp;
    char* p = (char*)malloc(sizeof(char));
    str_rev(str2);
    int  num = atoi(str2);
    summ = digits_summ(num);
    
    if(str2[5] == '\0' && str1[5] == '\0'){
        temp = (char*)realloc(p, summ+1);
        if(temp){
            p = temp;
            while(str1[i]){
                for(j = 0; j < num%10; j++){
                    p[counter] = str1[i];
                    counter++;
                }
                num/=10;
                i++;
            }        
            strcpy(&p[counter], "\0");
        }else{
            exit(1);
        }
    }
    return p;
}

int digits_summ(int num){
    int j,summ=0;
    for(j = 0; j < N; j++){
        summ += num%10;
        num /= 10;
    }
    return summ;
}

void str_rev(char digits[]){
    int j,i = 0, tmp, half;
    while(digits[i] != '\0'){
        i++;
    }
    half = i/2;
    for(j = 0; j < half; j++){
        tmp = digits[j];
        digits[j] = digits[--i];
        digits[i] = tmp;
    }
}

