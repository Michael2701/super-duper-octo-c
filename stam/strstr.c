#include <stdio.h>

int indexOf(char*, char*);
void print(char*);

void main(){
    int i;
    char s1[] = "a cc aba xxx baaa"; 
    char s2[] = "ba";

    print(s1);
    printf("%d\n", indexOf(s1, s2));
}

// find index of first occurence of second string in first
int indexOf(char* str1, char* str2){
    int i = -1;
    char* temp1, *temp2, *sp = str1;

    for(; *str1; str1++)
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

void print(char* s)
{
    for(; *s; s++) printf("%c", *s);
    printf("\n");
}
