/******************************************
 * Student name:          Roy Shefi
 * Student ID:            204845929
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex3
 ******************************************/
//

#include "PrintArray.h"
#include <stdio.h>

#define SIZE 51

void PrintArray (){
    int arr[SIZE];
    int i, wanted_arry, j, x = 0, k, cou = 0 ,max = 0;
    
    printf("Please enter your array length and your array:\n");
    scanf ("%d", &wanted_arry); // asking for wanted arry
    for (i=0; i < wanted_arry; ++i) {
        scanf("%d", &arr[i]);
    }
    
        for (k=0,i=0; i < wanted_arry; ++i) {
        if (arr[i+1] > arr [i]) {
            ++cou;
            if (cou > max) {
                max = cou;
                x = k;
            }
        }
        else {
            k = i + 1;
            cou = 0;
            j = 0;
        }
    }
    printf("The max ascending array is:");
    for (j=x; j < wanted_arry; ++j) {
        if (arr[j] < arr[j+1]) {
            printf("%d ",arr[j]);
        }
    }
    printf ("Length %d",cou);
}

