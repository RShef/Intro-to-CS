/******************************************
 * Student name:          Roy Shefi
 * Student ID:            204845929
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex3
 ******************************************/

#include <stdio.h>
#include "MoveArrayRight.h"
#include "PrintHighestSequence.h"
#include "Palindrome.h"
#include "IsPalindrome.h"
#include "Calculator1.h"
#include "SecondLargestNumber.h"

void MoveArrayRight();
void PrintHighestSequence();
void Palindrome();
void SecondLargestNumber();
void Calculator1();

int main(){
    int x = 0;
    int y = 0;
    while (y == 0) {
    printf ("Please select the assignment:\n0. Exit\n1. Shift right\n2. Sub ascending array \n3. Palindrome\n4. Calculator \n5. Second largest\n");
    scanf("%d", &x);
    switch (x) {
            
        case 0:
            return 0;
        case 1:
            MoveArrayRight();
            break;
            
        case 2:
            PrintHighestSequence();
            break;
            
        case 3:
            Palindrome();
            break;
        case 4:
            Calculator1();
            break;
            
        case 5:
            SecondLargestNumber();
            break;

            
        default:
            printf("Error in assignment number, please try again.\n\n");
            break;
        }
        printf("\n");
    }
}