/******************************************
 * Student name:          Roy Shefi
 * Student ID:            
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex2
 ******************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    int imput1 = 0;
    int x = 1;
    int i = 1;
    int count = 0;
    unsigned long int primeNum = 0;
    int boomNum = 0;
    
    // keep asking until there is a valid imput
    while (x == 1) {
        scanf("%d", &imput1);
        // primeNum input checking
        if (imput1 == 1){
            scanf("%lu", &primeNum);
            // checking untlit the root
            for(i = 2; i <= sqrt(primeNum); i++){
                if(primeNum % i == 0){
                    count++;
                    break;
                }
            }
            // if count didnt change then the number is prime
            // code with help from http://www.w3schools.in
            if(count == 0 && primeNum!= 1){
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
        // starting the 7 boom game
        if (imput1 == 2) {
            printf("Please enter a number for 7 boom game\n");
            scanf("%d", &boomNum);
            printf ("[");
            for (i = 1; i <= boomNum; i++) {
                
                // if the input is devidid by 7 or contains 7
                if(i == 7){
                    printf("%d", i);
                    }
                else if (i % 10 == 7 || i % 7 == 0) {
                    printf(",%d", i);
                    }
            }
            printf("]\n");

        }

        // geting out by user imput
        if (imput1 == 0) {
            return 0;
        }
        else {
            x = 1;
        }
        x = 1;
    }
    return  0;
}
