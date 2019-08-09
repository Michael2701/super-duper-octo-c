/*=====================================
    מיכאל סיליאנוב, יבגני גולובוציוב   
==================================== */
# include <stdio.h>
# include <stdlib.h>

int prime(int);

void main (){
    int num,temp,result;
    temp = 0, result = 0;

    printf("Please enter a number \n");
    scanf("%d", &num);

    while(num != -1){
        if(prime(num)){
            temp++;
        }else{
            if(temp > result){
                result = temp;
            }
            temp = 0;
        }

        scanf("%d", &num);
        if(num == -1 && temp > result) result = temp;
    }
    printf("The longest series of prime numbers is: %d \n", result);
    getchar();
}

int prime(int num){
    int i;
    int n = num < 0 ? -1*num : num;

    for(i = 2; i <= n/2; i++){
        if( !(n%i) ){
            return 0;
        }
    }
    return 1;
}

