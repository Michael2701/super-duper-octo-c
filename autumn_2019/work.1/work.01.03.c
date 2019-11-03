# include <stdio.h>
# define N 5
# define M 10

int check(int arr[][M], int m, int n);

void main() {
    int is_thin, num;
    int arr[N][M] = {
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    num = check(arr, M, N);

    if(num > 0)
    {
        is_thin = 1; 
    }
    else if(num == 0)
    {
        is_thin = 0;
    }
    else
    {
        is_thin = 0;
        num = -1*num;
    }

    if(is_thin)
    {
        printf("Matrix is thin and the number of not 0 numbers is: %d\n\r", num);
    }
    else
    {
        printf("Matrix is not thin and the number of not 0 numbers is: %d\n\r", num);
    }
}

int check(int arr[][M], int m, int n){
    int is_thin = 1;
    int count = 0;
    int num = m * n;
    int mapRows[N]  = {0}; 
    int mapColls[M] = {0};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] != 0)
            {
                count++;
                if(is_thin)
                {
                    mapRows[i]++;
                    mapColls[j]++;

                    if(count > num/10)
                    {
                        is_thin = 0;
                    }
                    else if(mapRows[i] > 2)
                    {
                        is_thin = 0;
                    }
                    else if(mapColls[j] > 2)
                    {
                        is_thin = 0;
                    }
                }
            }
        }
    }

    return is_thin ? count : (-1 * count);
}


