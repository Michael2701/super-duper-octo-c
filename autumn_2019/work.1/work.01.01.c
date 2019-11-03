# include <stdio.h>
# define N 70


void main() {
    int i = 0, j = 0, flag = 1,length;
    char arr[N];
    gets(arr);

    for (i = 0; i < N && flag; i++) 
    {
        j = i;

        while (arr[j] && arr[j] != '*') 
        {
            j++;
        }

        if(arr[j] == '\0') flag = 0;

        length = j - i;

        if (length % 2 == 0) 
        {
            printf("%c", arr[ i + length/2 - 1 ]);
            printf("%c", arr[ i + length/2 ]);
        }
        else 
        {
            printf("%c", arr[ i + length/2 ]);
        }

        printf("\n");
        i = j;
    }
}
