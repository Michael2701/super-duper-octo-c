#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4966)
#define N 3
int count_char(char* arr[], char ch);
void input(char **p);
void main() {
	char* arr[N] = { NULL }, ch = 'a';
	int count = 0;
	input(arr);
	count = count_char(arr, ch);
	printf("%d", count);

}

int count_char(char* arr[], char ch) {
	int i,j,count = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; arr[i][j] != '\0'; j++) {
			if (arr[i][j] == ch)
				count++;
		}
	}
	return count;
}
void input(char **p) {
	int i, j,size=0;
	char check_arr[100];
	for (i = 0; i < N; i++) {
		printf("enter an string\n");
		gets(check_arr);
		size =strlen(check_arr)+1;
		p[i] = (char*)malloc(size * sizeof(char));
		if (p[i]) {
			strcpy(p[i], check_arr);
		}
		else
			return 0;
	}
}