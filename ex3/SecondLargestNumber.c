/******************************************
* Student name:          Roy Shefi
* Student ID:            
* Course Exercise Group:   Mor 05
* Exercise name:            ex3
******************************************/
/************************************************************************
 * function name: SecondLargestNumber.                                  *
 * The Input: Void none                                                 *
 * The output: Void none                                                *
 * The Function operation: reciving a group of numbres from user and    *
 * printting the secong heighest on.                                    *
 *                                                                      *
 *************************************************************************/
#include "SecondLargestNumber.h"
    void SecondLargestNumber(){
        int first_num = 0, second_num = 0 , number= 0 ;
        printf("Please enter your array:\n");
        do {
            scanf("%d",&number);
            if (number != second_num && number != first_num) {
                // checking if the number is bigger then the last one.
                if (number > first_num){
                    second_num = first_num;
                    first_num = number;
                }
                // checking if the number is smaller then the second bigest number.
                else if (number > second_num){
                    second_num = number;
                }
            }
            
        }
        while (number != 0);
        printf("The second largest value is %d.",second_num);
        printf("\n");
    }