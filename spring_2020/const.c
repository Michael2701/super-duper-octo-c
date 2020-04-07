#include <stdio.h>
#include <string.h>

void sp_to_dash(char* s);


void main (){
    const int fixed1 = 10;
    int const fixed2 = 10;

    sp_to_dash("this is test");

}

void  sp_to_dash(char* str){
    while(*str)
    {
        if(*str == ' ')
        {
            strcpy(str, "-");
            printf("%c", '-');
        } 
        else printf("%c", *str);

        str++;
    }
}






