/*=====================================
 מיכאל סיליאנוב, יבגני גולובוציוב
 ==================================== */
#import <Foundation/Foundation.h>
#import<stdio.h>
#define N 3

void agefunc(int *age,int *avg,int *under){
    *avg+=*age;
    if (*age<=18)
        *under+=1;
}
int agecheck(int age){ //check if the entered number is an actual age
    
    if (age<=0||age>180)
        return 0;
    else
        return 1;
}

int main(){
    int age = 0,i,under = 0,avg = 0;
    int flag = 0;
    for (i=0;i<N&&flag == 0;i++){ //loop to enter 3 numbers
        printf("Enter an age:\n");
        scanf("%d",&age);
        if (agecheck(age))//call the check fucktion
            agefunc(&age,&avg,&under);
        else if(!agecheck(age))//if its the age call the fuction that will sum it
            flag = 1;
    }
    if (flag == 0) // print the age avarenge + how much under 18 if all 3 was ages
        printf("the average is : %d.\nthere %d ages under 18\n",avg/N,under);
    else if(flag == 1) // print eror if one of the nubers wasnt age
        printf("EROR\n");
    
    return 0;
}
