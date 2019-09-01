#include <stdio.h>
#include <string.h>
int main()
{
    char string[] = "0123456789";
    char *str;
    int i,j;
    str = string;
 for (i=0;i<strlen(string);i++)
 {
    if ((str[i]-'0')%2) i++;
    printf("%c",str[i]);
 }
 printf("\n");
 str = string;
 while (*str)
    printf("%c",string[(9-(*(str++)-'0'))]);
 
 printf("\n");
 str=string;
 for (i=0;i<(strlen(string)/2);i+=4)
    switch (str[i])
    {
    case '0': 
        printf("%c",str[i]-'0'+'a');
    case '1': 
        printf("%c",str[i]-'0'+'A');
    case '2': 
        printf("%c",str[i]);
    break;
    default: 
        printf("end\n");
    break;
    }
    printf("%d", 1+'0');
 return 0;
}