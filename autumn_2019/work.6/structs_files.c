//michael silianov + evgeney golovachov
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define NL 20
#define CL 36

typedef struct {
    char name[NL];
    int class_name;
    int gradeA;
    int gradeB;
    int gradeY;
} student;

typedef student class[CL];

// create array of sudents based on file data
void input(student* Class);

// print all students table with year avarage grade
void prnt(student* Class);

// find number of sudents in particular class
int std_number(student* Class, int class);

// calculate year avarege per student
void set_gradey(student* Class);

// calculate class year avarage
// must run after set_gradey
int find_class_avarage(student* Class);

// find number of sudent have year avarage under 90
int num_best_std(student* Class);

void main() {
    int i, count, avarage, best, num;
    class Class;

    input(Class);
    set_gradey(Class);
    prnt(Class);

    avarage = find_class_avarage(Class);
    printf("Class avarage is %d\n", avarage);

    best = num_best_std(Class);
    printf("Numbers of students have avarage higher then 90: %d\n", best);

    printf("Enter a class number: ");
    scanf("%d", &num);
    count = std_number(Class, num);
    printf("Students number in class %d: %d\n", num,count);
}

int num_best_std(student* Class){
    int i, summ = 0;
    for(i = 0; i < CL; i++){
        if(Class[i].gradeY > 90){
            summ++;
        }
    }
    return summ;   
}

void set_gradey(student* Class){
    int i;
    for(i = 0; i < CL; i++){
        Class[i].gradeY = (Class[i].gradeA + Class[i].gradeB) / 2;
    }
}

int find_class_avarage(student* Class){
    int i, summ = 0;
    for(i = 0; i < CL; i++){
        summ += Class[i].gradeY;
    }
    return summ/CL;
}


int std_number(student* Class, int class){
    int i, count = 0;
    for(i = 0; i < CL; i++){
        if(Class[i].class_name == class){
            count++;
        }   
    }
    return count;
}

void input(student* Class) {
    int i = 0;
    FILE* fd = fopen("students.txt", "r");

    if (fd) {
        while (!feof(fd)) {
            fscanf(fd, "%s", Class[i].name);
            fscanf(fd, "%d", &Class[i].class_name);
            fscanf(fd, "%d", &Class[i].gradeA);
            fscanf(fd, "%d", &Class[i].gradeB);
            fscanf(fd, "%d", &Class[i].gradeY);
            i++;
        }
    }
    fclose(fd);
}

void prnt(student* Class){
    int i;
    for(i = 0; i < CL; i++){
        printf("%10s ", Class[i].name);
        printf("%3d ", Class[i].class_name);
        printf("%3d ", Class[i].gradeA);
        printf("%3d ", Class[i].gradeB);       
        printf("%3d ", Class[i].gradeY);       
        printf("\n");
    }
}