#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 7;
char* cut_from_string(char* str, int start, int len);

int main()
{
    char *str2,str1[] = "question number two";
    int start = 20, len = 10;

    str2 = cut_from_string(str1, start, len);
    printf("%s\n", str2);
    printf("%s\n", str1);
}

char* cut_from_string(char* str, int start, int len){
    int j = 0,i = 0, x = 0, size = 0, end;
    char* p = (char*)malloc(sizeof(char));
    strcpy(&p[0]," ");

    for(;str[size];size++);
    printf("length: %d\n",size);
    

    if(start < size){
        end = (start+len) > size ? size : (start+len);
        p = (char*)realloc(p, (end+1)*sizeof(char));

        while(str[i]){
            if( i >= start && i <= end)
            {
                p[x] = str[i];
                x++;
            }else
            {
                str[j] = str[i];
                j++;
            }
            i++;
        }
        strcpy(&p[x],"\0");
        strcpy(&str[j], "\0");

    }
    

    return p;
}
