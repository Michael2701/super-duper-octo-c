# include <stdio.h>
# include <stdlib.h>
# define N 10


void main(){
    int arr[N] = {1,2,10,10,5,6,10,10,4,3};
    int i,max,len = 1;
    int* c;

    c = (int*)malloc(sizeof(int));
    c[0] = 0;
    max = arr[0];

    for(i = 1; i < N; i++){
        if(arr[i] > max){
            len = 1;
            max = arr[i];
            c = (int*)realloc(c, sizeof(int));
            c[len-1] = i;
        }else{
            if(arr[i] == max){
                len++;
                max = arr[i];
                c = (int*)realloc(c, len*sizeof(int));
                c[len-1] = i;
            }
        }

    }
    printf("%d\n", max);
    for(i = 0; i < len; i++){
        printf("%d ", c[i]);
    }
}

























