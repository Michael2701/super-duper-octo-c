/*=====================================
    מיכאל סיליאנוב, יבגני גולובוציוב   
==================================== */
# include <stdio.h>
# include <stdlib.h>
# define LENG 2

int SUMD(int);
// takes care of input
int input();
// return number length
int get_num_length(int);
// calculate summ of all number digits
int num_sum(int);

void main (){
    int num,sum,flag=1;

    printf("Please enter a number \n");

    while(flag)
    {
        num = input();
        
        if(num != 0)
        {
            sum = SUMD(num);
        }
        else
        {
            flag=0;
            printf("The end\n");
        }
    }
    getchar();
}

int SUMD(int num)
{
    int len = get_num_length(num);
    printf("The number is: %d\n", num);

    if(len == LENG)
    {
        printf("The summ is: %d\n", num_sum(num));
    }
    else
    {
        printf("The summ is: %d\n", num_sum(num%100));
    }
};

int input()
{
    int n;
    scanf("%d", &n);
    if(get_num_length(n) < LENG) n = 0;
    return n;
}

int get_num_length(int num)
{
    int counter = 0;

    while(num)
    {
        counter++;
        num/=10;
    }
    return counter;
}

int num_sum(int num)
{
    int sum = 0;

    while(num)
    {
        sum+=num%10;
        num/=10;
    } 
    return sum;
}

