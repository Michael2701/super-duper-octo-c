/*=====================================
    מיכאל סיליאנוב, יבגני גולובוציוב   
==================================== */
#include <stdio.h>
#define M 12
#define N 3.0

int input(int *age1, int *age2, int *age3);
float calc(int *age1, int *age2, int *age3, int *count);

void main(){
    int age1, age2, age3, is_valid, count = 0;
    float avg;
    do{
        printf("Please enter ages of 3 people\n");
        scanf("%d", &age1);
        scanf("%d", &age2);
        scanf("%d", &age3);
        is_valid = input(&age1,&age2,&age3); 
        if(!is_valid) printf("Please enter valid ages\n");
    }while(!is_valid);

    avg = calc(&age1, &age2, &age3, &count);

    if(count == 0){
        printf("There is no people under 18 years old\n");
    }else{
        printf("There are %d people under 18 years old\n", count);
    }
    printf("The average age is: %.0f years and %g mounth \n", avg, (int)M*(avg-(int)avg) );
}

float calc(int *age1, int *age2, int *age3, int *count){
    float avg; 
    *count += *age1 < 18;
    *count += *age2 < 18;
    *count += *age3 < 18;
    
    return (*age1+*age2+*age3)/N;
}

int input(int *age1, int *age2, int *age3){
    int is_valid_age = 1;
    if(
        *age1 > 120 || *age1 < 1 ||
        *age2 > 120 || *age2 < 1 ||
        *age3 > 120 || *age3 < 1
    )
    is_valid_age = 0;
    return is_valid_age;
}















