//michael silianov + evgeney golovachov
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 5
#define L 50

typedef struct {
	int count;
	char* name;

} student;

void read_file(FILE* f, char* names);
void main() {
	char temp[L];
	char** names = (char**)malloc(sizeof(char*));
	char** names2;
	FILE* read_file = fopen("oldfile.txt", "r");


	int i = 0;
	if (read_file && names) { 
		while (!feof(read_file)) {
			if (fgets(temp, L, read_file)) 
			{
				names2 = (char**)realloc(names, (i+1)*sizeof(char*));
				if(names2){
					names = names2;
				}

				names[i] = (char*)malloc( (strlen(temp)+1) * sizeof(char));
				if(names[i]){
					strcpy(names[i], temp);
				}

				i++;
			}
	
		}
	}
	fclose(read_file);

	student* st = (student*)calloc((i-1), sizeof(student));

	int scount = 0;
	for(int x = 0; x < i-1; x++){
		for(int y = x+1; y < i; y++){
			if(!strcmp(names[x], names[y])){
				printf("%s %s \n", names[x], names[y]);
				int flag = 1;
				for(int k = 0; k < i; k ++){
					// printf("%s", (st+k)->name);
					if( (st+k)->name == names[y] ){
						
						(st+k)->count++;
						flag = 0;
					}
				}
				if(flag){
					(st+scount)->name = (char*)malloc( (strlen(names[y])+1) * sizeof(char) );
					if((st+scount)->name){
						strcpy((st+scount)->name, names[y]);
					}
					(st+scount)->count++;
				}
			}
		}
	}
}
