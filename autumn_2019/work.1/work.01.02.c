# include <stdio.h>
# define N 3

void search(int arr1[][N], int arr2[][N]);

void main() {
    int arr1[N][N] = {{1,2,3},{3,4,5},{6,7,8}};
    int arr2[N][N] = {{1,40,3},{2,2,4},{3,70,5}};

    search(arr1, arr2);
}

void search(int arr1[][N], int arr2[][N]){
    int counters[N] = {0};
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            int flag = 1;
            for(int j = 0; j < N; j++){
                if( arr1[k][j] != arr2[j][i]){
                    flag = 0;
                }
            }
            if(flag){
                counters[k]++;
                printf("Row %d of arr1 = column %d of arr2\n", k+1,i+1);
            }
        }
    }
    int max = 0;
    int max_index = -1;
    for(int i = 0; i < N; i++){
        if(counters[i] > max){
            max = counters[i];
            max_index = i;
        }
    }
    if(max_index != -1){
        printf("Row %d have biggest number of coincidences\n", max_index+1);
    }
}


