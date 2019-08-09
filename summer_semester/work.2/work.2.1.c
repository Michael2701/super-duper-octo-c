/*=====================================
    מיכאל סיליאנוב, יבגני גולובוציוב   
==================================== */
#include <stdio.h>

int yored(int,int);

void main()
{
    int prev,curr,longest=0,temp=1,num=0;
    printf("Please enter a number\n");
    scanf("%d",&prev);

    while(num != -1){
        scanf("%d",&num);
        if(num != -1){
            curr = num;
            
            if(yored(prev,curr)){
                temp++;
            }else{
                if(longest < temp){
                    longest = temp;
                }
                temp = 1;
            }
            prev = curr;
        }
    }

    if(longest < temp){
        longest = temp;
    }

    printf("\nThe longest series is: %d numbers long\n",longest);
    getchar();
}

int yored(int num1, int num2){
    return num1 > num2;
}