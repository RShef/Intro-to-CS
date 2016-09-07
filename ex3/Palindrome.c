/******************************************
 * Student name:          Roy Shefi
 * Student ID:            204845929
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex3
 ******************************************/
/************************************************************************
 * function name:   Palindrome                                          *
 * The Input: none (void)                                               *
 * The output: none ( void)                                             *
 * The Function operation: reciving an array with its size from         *
 * the user, then suminig a func to chek if it is a palindrome.         *
 * then if the returing  value is 0 or 1 printig to the user.           *
 * (with size).                                                         *
 *************************************************************************/

#include "Palindrome.h"
#include "IsPalindrome.h"
#include <stdio.h>
#define SIZE 51

void Palindrome(){
    int arr[SIZE] = {0};
    int  i= 0 , wanted_arry = 0 ;
    // making sure its not 0.
    printf("Please enter your array length and your array:\n");
    scanf ("%d", &wanted_arry);
    if (wanted_arry == 0 ) {
        printf("Your array is palindrome.");
    }
    else{
    // Getint array from user.
    for (i=0; i < wanted_arry; ++i) {
        scanf("%d", &arr[i]);
     }
    // Caling A function to check if the array is a palindrome.
    switch (IsPalindrome(arr, wanted_arry)) {
        case 0:
            printf("Your array is not palindrome.\n");
            break;
          case 1:
            printf("Your array is palindrome.\n");
            break;
            
        default:
            break;
    }
}
}

