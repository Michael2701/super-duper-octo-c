//Evgeney Golovochov & Michael Silianov

// Find which char appirenced maximum times 
// in array of pointers to arrays of characters(strings) 
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# pragma warning(disable:4996)
# define N 5

void input(char* str[N], int size);
int getCharCount(char* str[N], char s);
int getMaxAppirence(char* str[N]);

void main() {
    int i,count = 0;
    char *str[N] = {0};

    input(str, N);
    printf("Char '%c' appirenced max times\n", getMaxAppirence(str));
}

// return char appirenced maximum times in all arrays of chars
// in given array of pointers
int getMaxAppirence(char* str[N]) {
    int i,j,max=0,index;
    int nums[256] = {0};

    // run through all chars in all given strings
    // in order to count number of appirences 
    for (i = 0; i < N; i++) {
        for (j = 0; str[i][j] != '\0'; j++) {
            if(nums[str[i][j]] == 0){
                nums[str[i][j]] += getCharCount(str, str[i][j]);        
            }
        }
    }
    // find biggest counter in counter array
    // in case of same size returns frst one
    for (i = 0; i < 256; i++){
        if(nums[i] > max){
            max = nums[i];
            index = i;
        }
    }
    return index;
}

// find number of appirences of provided char in given string
int getCharCount(char* str[N], char s) {
    int i,j,count = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; str[i][j] != '\0'; j++) {
            if (str[i][j] == s) {
                count++;
            }
        }
    }
    return count;
}

// reseive array of chars(string) from user
// determine array length and save it appropriate length array 
void input(char* str[N], int size) {
    char tmp[100];
    int i;

    for (i = 0; i < N; i++) {
        gets(tmp);
        str[i] = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
        if (str[i]) {
            strcpy(str[i], tmp);
        }
    }
}