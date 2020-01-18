//michael silianov + evgeney golovachov
#include <stdio.h>
#include <stdlib.h>
#define N 25
#define L 5

typedef struct{
    char name[N];
    int  num;
    int* courses;
} student;

typedef student univer[L];

void readToArray(student* Univer);// read file and save to array of structs
void freeUniver(student* Univer); // free dinamically allocated array inside student struct
void printCourseStudents(student* Univer, int coursNumber); // print students per cours 
int countPerCourse(student* Univer, int coursNumber); // count students for one course
int charToNum(char* s); // transform char to number

void main(){
    int count,coursNum,choise, run = 1;
    univer Univer;
    readToArray(Univer);

    while(run){// programm main loop

        do{ // check if course number is between 1 to 120
            printf("\nPlease enter course number(1-120): ");
            scanf("%d", &coursNum);
        }
        while(coursNum < 1 || coursNum > 120);

        printf("%s\n","Press 1 for students list");
        printf("%s\n","Press 2 for students count");
        printf("%s","Press 3 for exit ");
        scanf("%d", &choise);
        
        switch(choise){
            case 1:
                printCourseStudents(Univer, coursNum);
            break;
            case 2:
                count = countPerCourse(Univer, coursNum);
                count ? printf("The count is: %d\n", count): printf("%s\n","No students for this course");
            break;
            case 3:
                run = 0;
                freeUniver(Univer);
                printf("Good buy\n");
            break;
            default:
                printf("Please read instructions ;))\n");
        }
    }

}

int countPerCourse(student* Univer, int coursNumber){
    int i,j,flag,count=0;
    for(i = 0; i < L; i++){
        j = 0, flag = 0;
        while(  Univer[i].courses[j] != -1 && !flag){
            if(Univer[i].courses[j] == coursNumber){
                flag = 1;
                count++;
            }
            j++;
        }
    }   
    return count;
}


void printCourseStudents(student* Univer, int coursNumber){
    int i,j,flag;
    for(i = 0; i < L; i++){
        j = 0, flag = 1;
        while(  Univer[i].courses[j] != -1 && flag){
            if(Univer[i].courses[j] == coursNumber){
                flag = 0;
            }
            j++;
        }
        if(!flag){
            printf("%11d %s \n", Univer[i].num, Univer[i].name);
        }
    }
}

void freeUniver(student* Univer){
    for(int i = 0; i < L; i++){
        free(Univer[i].courses);
    }   
}

void readToArray(student* Univer) {
    int a,b,n;
    int i = 0, j, c, flag;
    char temp[4];
    int* t;
    int nums[4];
    FILE* fd = fopen("students.txt", "r");

    if (fd) {
        while (!feof(fd)) {
            j = 0;
            flag = 1;
            fscanf(fd, "%s", Univer[i].name);
            fscanf(fd, "%d", &Univer[i].num);

            Univer[i].courses = (int*)malloc(sizeof(int));

            while (flag) {
                fscanf(fd, "%s", temp);

                if (*temp == ',') {
                    flag = 0;
                }else {
                    Univer[i].courses[j] = charToNum(temp);
                    Univer[i].courses = (int*)realloc(Univer[i].courses, sizeof(int)*(j+1));
                }
                j++;
            }

            Univer[i].courses[j-1] = -1;
            i++;
        }
    }
}

int charToNum(char* s) {
    int i = 0,num = 0;
    while (*(s+i)) {
        num = (num * 10) + (*(s+i) - '0');
        i++;
    }
    return num;
}