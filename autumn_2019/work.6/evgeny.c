#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#define N 20
#define C 3

typedef struct stud 
{
	char name[N];
	int class_num;
	int half_A_grade;
	int half_B_grade;
	int year_grade;
}student;
typedef student class[36];


void input(student* p) //function to take the students data from a file (func 1)
{
	int i = 0,count =0 ;
	FILE* fd = fopen("students.txt", "r");
	if (fd)
	{
		for(i = 0;i<C && !(feof);i++,count++)
		{
			fscanf(fd, "%s %d %d %d ", p[i].name, &p[i].class_num,&p[i].half_A_grade,&p[i].half_B_grade);
		
		}
	}
	if (count < 36)
	{
		printf("the file is not corect need a 36 students\n");
			exit ;
	}
}

int class_count(student* p, int class_num) // counts how much students in one class (func 2)
{
	int i, count = 0;
	for (i = 0; i < C; i++)
	{
		if (p[i].class_num == class_num)
			count++;
	}
	return count;

}
void year_grade_change(student* p) // function that claculate the the year grade based on A half grade and B half grade (func 3)
{
	int i, avg;
	for (i = 0; i < C; i++)
	{
		avg = (p[i].half_A_grade + p[i].half_B_grade) / 2;
		p[i].year_grade = avg;
	}
}
void class_year_avg(student* p) // count the class year averange grade (func 4)
{
	int i;
	float avg = 0;
	for (i = 0; i < C; i++) 
	{
		avg += p[i].year_grade;
	}
	printf("The class year avg is: 5%f\n", avg / C);
}
void top_student_count(student* p) // count the studebts that have year grade above 90(func 5)
{
	int i, count = 0;
	for (i = 0; i < C; i++) 
	{
		if (p[i].year_grade >= 90)
			count++;
	}
	printf("the number of students that have grade bigger than 90:%d\n", count);
}
void main() { // main function 
	class comp_class;
	int class_number;
	input(comp_class); // call func 1
	printf("enter the class number you whant to check:\n");
	do// call to func 2 
	{
	scanf("%d",&class_number);
	} while (class_number<0&&class_number>5);//check corect input
	printf("there : %d students in class :%d \n", class_count(comp_class, class_number), class_number);
	year_grade_change(comp_class); //call func 3
	class_year_avg(comp_class); //call func 4
	top_student_count(comp_class); //call func 5
}
