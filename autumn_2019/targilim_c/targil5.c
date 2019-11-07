# include <stdio.h>
# include <stdlib.h>
# define N 4


void main(){
    int arr[N] = {1,2,5,6,10};
    int num,c;
    int i,j;

    printf("Please enter a number\n");
    scanf("%d", &num);

    for(i  = 0; i < N && arr[i] < num; i++){
        for(j = i+1; j < N && arr[j]; j++){
            if( arr[j] + arr[i] == num ){
                printf("%d:%d\n", arr[i], arr[j]);
            }
        }
    }
    

}

























