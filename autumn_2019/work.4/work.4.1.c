//michael silianov + evgeney golovachov
#include<stdio.h>
#pragma warning(disable:4996)
#define n 5 // numer of names that will be saved in the file
#define str 50 //length of a string that will containe names
void new_txt(char* new);
void print_copy(FILE* read, FILE* new);
void main() {
	FILE* new_file = fopen("newfile.txt", "w"); //open to pointer to file read+ write
	FILE* read_file = fopen("oldfile.txt", "r");


	if (read_file && new_file) { //call a function that will copy + print the file created before
		print_copy(read_file, new_file);
	}

	fclose(new_file);
	fclose(read_file);
}


void print_copy(FILE* read, FILE* new) {
	char arr[str];
	while (!feof(read)) {
		
		if (fgets(arr, str, read)) {
			printf("%s", arr);
			fprintf(new, "%s", arr);
		}
	}
}