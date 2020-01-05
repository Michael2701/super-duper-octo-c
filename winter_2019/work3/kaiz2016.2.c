//michael silianov + evgeney golovachov
#include <stdio.h>
#include <stdlib.h>


int check_input(char* str);// check if input is valid, return 0 or 1
int func(char* str); // return -1 or number of numbers printed
int print(char* str); // calculate and print numbers, return 0 or how much numbers printed

void main(){
    int result;
    char str[] = {"123x2 2x5 567 6x6"};

    result = func(str);
    printf("%d numbers\n",result);
}

int func(char* str){
    int count = -1;
    if(check_input(str)){ // if string is valid
        count = print(str);
    }
    return count;
}

int print(char* str){
    int i = 0,j,count=0;
    while(*str){ // pass through all given string 
        if(*str > 48 && *str < 58){ // check if char is number
            printf("%c", *str);
        }else{
            if(*str == 120){ // check if char is 'x'
                for(j = 0; j < *(str+1)-49; j++){ // print prev number 'x'-1 times
                   printf("%c",*(str-1)); 
                } 
                str++;
            }else{
                count = count == 0 ? 1 : count+1; // inrement count
                printf("\n");
            }
        }
        str++;
    }
    printf("\n");
    return count;
}


int check_input(char* str){
    int flag = 1;
    while(*str && flag){ // pass through array untill finds not valid char or to the end
        if(*str < 48 && *str != 32)
        {
            flag = 0;
        }else{
            if( *str > 57 && *str != 120)
            {
                flag = 0;
            }else{
                if(*str == 120 && *(str-1) == 32){
                    flag = 0;
                }
            }
        }  
        str++;
    }
    return flag;
}


