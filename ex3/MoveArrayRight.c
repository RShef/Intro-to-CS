/******************************************
 * Student name:          Roy Shefi
 * Student ID:            204845929
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex3
 ******************************************/
/************************************************************************
 * function name: MoveArrayRight                                        *
 * The Input: None (Void)                                               *
 * The output: None (Void)                                              *
 * The Function operation: reciving an array with its size from the     *
 * user, then shifting the nubers right within the array size from user *
 * and pring the array after the shifts.                                *
 *************************************************************************/

#include "MoveArrayRight.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 51

void MoveArrayRight(){
    int arr[SIZE] = {0};
    int temp [SIZE];
    int i, wanted_arry, move, x, temp2;
    printf("Please enter your array length and your array:\n");
    // asking for wanted arry
    scanf ("%d", &wanted_arry);
    for (i=0; i < wanted_arry; ++i) {
        scanf("%d", &arr[i]);
    }
    
    printf("Please enter the number to shift right:\n");
    scanf("%d", &move);
    // if array is 0.
    if (wanted_arry == 0 ) {
        printf("Your array is: ");
        printf("\nAfter %d shifts right is:", move);
    }
    // if array is not 0.
    else{
    printf("Your array is: ");
    // geting array from user
    for (i=0; i < wanted_arry; ++i) {
        printf("%d ", arr[i]);
    }
    // safty so the move will always work
        if (move > wanted_arry) {
        temp2 = move;
        move = move % wanted_arry;
    }
    else{
        move = move;
    }
    // copying the array
    for (i=0; i < wanted_arry; ++i) {
        temp[i] = arr[i];
    }
    // making the shift
    for (i=0; i < wanted_arry; ++i) {
            x = move + i;
            if (x >= wanted_arry) {
            x = x - wanted_arry;
            }
            arr[x] = temp[i];
        
    }
    printf("\nAfter %d shifts right is:", move);
    for (i = 0; i < wanted_arry; ++i) {
        printf (" %d", arr[i]);
    }
    printf("\n");
}
}

