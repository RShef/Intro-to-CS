/******************************************
 * Student name:          Roy Shefi
 * Student ID:            
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex3
 ******************************************/

#include <stdio.h>
void PrintArray();
void RightMove();
int main(){
    int x = 0;
    int y = 0;
    while (y == 0) {
        printf ("Please select the assignment:\n0. Exit.\n1. Shift right.\n2. Sub ascending array \n3. Palindrome\n4. Calculator1 \n5. Second largest\n");
    scanf("%d", &x);
    switch (x) {
            
        case 0:
            return 0;
            
            break;
            
            case 1:
            RightMove();
            break;
            
            case 2:
            PrintArray();
            break;
            
        default:
            printf("Error in assignment number, please try again.\n\n");
            printf ("Please select the assignment:\n0. Exit.\n1. Shift right.\n2. Sub ascending array \n3. Palindrome\n4. Calculator1 \n5. Second largest\n");
            break;
        }
        scanf("%d", &x);
        
    }
}