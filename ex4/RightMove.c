/******************************************
 * Student name:          Roy Shefi
 * Student ID:            
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex3
 ******************************************/

#include "RightMove.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 51

void RightMove(){
    int arr[SIZE];
    int temp [SIZE];
    int i, wanted_arry, move, x;
    printf("Please enter your array length and your array:\n");
    scanf ("%d", &wanted_arry); // asking for wanted arry
    for (i=0; i < wanted_arry; ++i) {
        scanf("%d", &arr[i]);
    }
    
    printf("Please enter the number to shift right:\n");
    scanf("%d", &move);
   
    printf("Your array is: ");
    for (i=0; i < wanted_arry; ++i) { // geting array from user
        printf("%d ", arr[i]);
    }
    
    if (move > wanted_arry) {        // safty so the move will always work
        move = move - wanted_arry;
    }
    else
        move = move;
    for (i=0; i < wanted_arry; ++i) { // copying the array
        temp[i] = arr[i];
    }
    
    for (i=0; i < wanted_arry; ++i) { // making the shift
            x = move + i;
            if (x >= wanted_arry) {
            x = x - wanted_arry;
            }
            arr[x] = temp[i];
        
    }
    printf("\nAfter %d shifts right is: ", move);
    for (i = 0; i < wanted_arry; ++i) {
        printf ("%d ", arr[i]);
    }
}


