/******************************************
 * Student name:          Roy Shefi
 * Student ID:            204845929
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex3
 ******************************************/
/************************************************************************
* function name: PrintHighestSequence                                   *
* The Input: None (Void)                                                *
* The output: None (Void)                                               *
* The Function operation:                                               *
* reciving an array with its size from the user,                        *
* then finding the largest sequence of ascending numbers and printing   *
* them to the scren (with size)                                         *
*************************************************************************/

#include "PrintHighestSequence.h"
#include <stdio.h>

#define SIZE 51

void PrintHighestSequence (){
    int arr[SIZE] = {0};
    int i, wanted_arry, x = 0, cou = 1 ,max = 1;
    int new_pos = 0;
    // asking for wanted arry
    printf("Please enter your array length and your array:\n");
    scanf ("%d", &wanted_arry);
    if (wanted_arry == 0 ) {
        printf("The max ascending array is:\nLength 0");
    }
    
    else{
    for (i=0; i < wanted_arry; ++i) {
        scanf("%d", &arr[i]);
    }
     // checking if the there is an escalation sequence in the arry.
    for (new_pos=0,i=1; i < wanted_arry; ++i){
        if (arr[i] > arr[i-1]){
            ++cou;
            if (cou > max){
                max = cou;
                x = new_pos;
            }
        }
        // alowing to print an escalation sequence that does not start at the biginning.
        else{
            new_pos = i;
            cou = 1;
        }
    }
        // printing the escalation sequence.
        printf("The max ascending array is:");
        for (i = 0; i < max; i++) {
            printf(" %d", arr[x + i]);
        }

           printf ("\nLength %d\n",max);
}
}

