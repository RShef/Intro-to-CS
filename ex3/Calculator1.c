/******************************************
 * Student name:          Roy Shefi
 * Student ID:            204845929
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex3
 ******************************************/
/************************************************************************
 * function name: Calculator1.                                          *
 * The Input: Void none                                                 *
 * The output: Void none                                                *
 * The Function operation: reciving int numbers with an opreater and    *
 * calculatind them                                                     *
 *                                                                      *
 *************************************************************************/


#include "Calculator1.h"
#include <stdio.h>

void Calculator1(){
    int x=0, y=0, z=0, t=0, ans = 0, help=0;
    int x1 = 0, y1= 1;
    char op;
    printf("Please enter your equation:\n");
    
    do {
        // Checking a tricky stata
        if (help == 0){
            scanf("%d / %d", &x, &y);
            help =1;
            if (x == 0 && y == 1) {
                printf("Result %d/%d.", x, y);
            break;
            }
            else if ( x == 0){
                break;
            }
            //Saftey.
            else if (x < 0) {
                x = -x;
                y = -y;
            }
        }
        // Geting the second fraction and the Operater between them.
        scanf(" %c %d / %d", &op, &z, &t);
        //Border
        if (z == 0 && t == 0) {
            x1 = x;
            y1 = y;
            break;
        }
        //Saftey.
       else if (z < 0) {
            z = -z;
            t = -t;
        }
        
        switch (op) {
            case '+':
                // Making a common denominator
                x = x * t;
                z = z * y;
                y = y * t;
                t = y;
                // adding.
                x += z;
                ans = x/y;
                break;
            case '-':
                // Making a common denominator
                x = x * t;
                z = z * y;
                y = y * t;
                t = y;
                x -= z;
                break;
             case '*':
                y *= t;
                x *= z;
                break;
            case '/':
                x *= t;
                y *= z;
                break;
                
            default:
                break;
        }
        // Reduction
        if (x != 0 ) {
          if(y % x == 0){
            y = y / x;
            x = 1;
          }
        }
        else{
            x = 0;
            y = 1;
        }
        x1 = x;
        y1 = y;
        
    } while (y != 0);
    
        if(x1!=0 && y1 % x1 != 0){
        y1= y1 / x1;
        x1 = 1;
        }
        printf("Result %d/%d.\n", x1, y1);
    }
