#include <stdio.h>
char str_len(char *str);
char str_cmp(char *str1, char *str2);
int _atoi(char *str);
long _atol(char *str);
float _atof(char *str);
char* strcpy(char *str1, char *str2);

void main(){
    // int len = str_len("abc");
    // printf("%d\n",len);

    char s[3] = "901";
    char s2[3];
    char *ps = s;
    char *ps2 = s2;
    
    // int str = _atoi(ps);
    // printf("%i\n",str);

    // long l;
    // l = _atol(ps);
    // printf("%ld",l);

    // float f;
    // f = _atol(ps);
    // printf("%.2f\n",f);

    
    printf("%s\n", strcpy(ps2, ps) );

}

char str_len(char *str){
    int len = 0;
    for(;*(str+len);len++);
    return len;
}
char str_cmp(char *str1, char *str2){
    return str_len(str1) - str_len(str2); 
}
int _atoi(char *str){
    int res = 0;
    while( *str != '\0' && *str-'0' < 10 ){
        res = res*10 + *str-'0';
        str++;
    }        
    return res; 
}
long _atol(char *str){
    int res = _atoi(str);
    return (long)res;
}
float _atof(char *str){
    int res = _atoi(str);
    return (float)res;
}
char* strcpy(char *str1, char *str2){
    char *ptr = str1;
    if(str_len(str1) == str_len(str1)){
        while(*str2 != '\0'){
            *str1 = *str2;
            str1++;
            str2++;
        }
        *str1 = '\0';
    }
    return ptr;
}



