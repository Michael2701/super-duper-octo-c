#include <stdio.h>

int indexOf(char* str1, char* str2);

void main(){
    int i;
    char s1[] = "a cc aba xxx"; 
    char s2[] = "ba";

    i = indexOf(s1, s2);
    printf("%d\n", i);
}

int indexOf(char* str1, char* str2){
    int i = -1;
    char* temp1, *temp2, *sp = str1;

    for(; *str1; str1++ )
    {
        temp1 = str1;
        temp2 = str2;
        if(*temp1 == *temp2)
        {
            for(; *temp2 && ( *temp1 == *temp2 ); temp1++, temp2++);
        }
        if(*temp2 == '\0')
        {
            i = str1 - sp;
            break;
        }
    }
    return i;
}


