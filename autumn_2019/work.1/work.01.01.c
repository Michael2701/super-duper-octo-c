# include <stdio.h>
# define N 17


void main() {
    int i = 0, j = 0, length;
    char arr[N];
    gets(arr);

    for (i = 0; i < N; i++) {
        j = i;

        while (arr[j] && arr[j] != '*') {
            j++;
        }
        printf("(%d) ", j);
        printf("(%d) ", i);
        length = j - i;

        if (length % 2 == 0) {
            printf("%c", arr[ i + length/2 - 1 ]);
            printf("%c | ", arr[ i + length/2 ]);
        }
        else {
            printf("%c | ", arr[ i + length/2 ]);
        }

        i = j;
    }

}
