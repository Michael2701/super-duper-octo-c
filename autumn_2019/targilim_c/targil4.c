# include <stdio.h>
# include <stdlib.h>
# define N 4


void main(){
    float arr[N] = {1,2,5,6};
    float num,c;
    int i,j,count = 2;

    printf("Please enter a number\n");
    scanf("%f", &num);

    for(i  = 0; i < N && count; i++){
        for(j = 0; j < N && count; j++){
            if( arr[j] - arr[i] == num){
                count--;
            }
        }
    }
    
    if(count){
        printf("Not\n");
    }else{
        printf("Yes\n");
    }

}

























