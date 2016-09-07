/******************************************
 * Student name:          Roy Shefi
 * Student ID:            
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex3
 ******************************************/
/************************************************************************
 * function name: IsPalindrome                                          *
 * The Input: arr[] ( array from user), wanted_array (array size).      *
 * The output: x (0 or 1)                                               *
 * The Function operation: reciving an array with its size from         *
 * the summing func, then checking if it is a Palindrome and then       *
 * returning x =  1 or 0, to the summing func and printing them to the  *
 * scren (with size).                                                   *
 *************************************************************************/
#include "IsPalindrome.h"
#define SIZE 51

int IsPalindrome(int arr[], int wanted_arry){
    int x = 0, half = 0, i = 0, half2 = 0;
    int first_half [SIZE] = {0};
    int sec_half [SIZE] = {0};
    
    if (wanted_arry % 2 == 0 ) {
        half = wanted_arry / 2;
        half2 = half;
    }
    else {
        half = (wanted_arry -1) / 2;
        half2 = (wanted_arry +1) / 2;
    }
    
    for (i=0; i < half; ++i) {
            first_half[i] = arr[half -1 - i];
        }
    for (i = half2; i < wanted_arry; ++i) {
            sec_half[i - half2] = arr[i];
        }
    for (i=0; i < half; i++) {
            if (sec_half[i] == first_half[i]) {
                x = 1;
            }
            else{
                x = 0;
                break;
            }
    }
        return x;
}
