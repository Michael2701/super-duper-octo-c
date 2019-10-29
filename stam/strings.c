#include <stdio.h>
#define L 25
#define N 3

void input(char s[][L], int n[]);
void inputNum();
int max(int*);

void main(){
    char names[N][L];
    int  nums[N];
    int  m;

    input(names, nums);
    m = max(nums);

    if(m != -1){
        printf("Best student is %s with %d degree\n", names[m], nums[m]);
    }else{
        printf("Buggy code");
    }

    for(int g = 0; g < N; g++){
        printf("%s\n", names[g]);
    }
}

int max(int* n){
    int max = 0, j = -1;
    for(int i = 0; i < N; n++, i++){
        if(*n > max){
            max = *n;
            j = i;
        } 
    }
    return j;
}

void input(char names[][L], int nums[]){
    for(int i = 0; i < N; i++){
        printf("Enter a name\n");
        scanf("%s", &names[i][L]);
        printf("Enter grade\n");
        scanf("%d", &nums[i]);
    }
}
