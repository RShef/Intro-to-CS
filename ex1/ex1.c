/******************************************
* Student name:          Roy Shefi
* Student ID:            
* Course Exercise Group:   Mor 05
* Exercise name:            ex1
******************************************/

#include <stdio.h>
#include <math.h>
int main()
{
    printf("Please input three courses grades:\n");
    // defineing variables
    char first_subjekt = '\0';
    char second_subjekt = '\0';
    char third_subjekt = '\0';
    
    float first_score = 0;
    float second_score = 0;
    float third_score = 0;
    
    // asking for grade input from the user
    scanf("%f %c", &first_score, &first_subjekt);
    
    // making sure the grade is with in grade range (0-100)
    if (first_score > 100 || first_score < 0 ) {
        printf("Error\n");
           return 0;
    }
    // making sure the imput is in a subjekt relavant
    if (first_subjekt != 'I' && first_subjekt != 'O'
        && first_subjekt != 'D' && first_subjekt != 'L'
        && first_subjekt != 'A')
    {
        printf("Error\n");
           return 0;
    }
    // asking for grade input from the user
    scanf("%f %c", &second_score, &second_subjekt);
    
    // making sure the grade is with in grade range (0-100)
    if (second_score > 100 || second_score < 0 ) {
        printf("Error\n");
        return 0;
    }
    // making sure the imput is in a subjekt relavant
    if (second_subjekt != 'I' && second_subjekt != 'O'
        && second_subjekt != 'D' && second_subjekt != 'L'
        && second_subjekt != 'A')
    {
        printf("Error\n");
        return 0;
    }
    // asking for grade input from the user
    scanf("%f %c", &third_score, &third_subjekt);
    
    // making sure the grade is with in grade range (0-100)
    if (third_score > 100 || third_score < 0 ) {
        printf("Error\n");
        return 0;
    }
    // making sure the imput is in a subjekt relavant
    if (third_subjekt != 'I' && third_subjekt != 'O'
        && third_subjekt != 'D' && third_subjekt != 'L'
        && third_subjekt != 'A')
    {
        printf("Error\n");
        return 0;
    }
    if (first_subjekt == second_subjekt || first_subjekt == third_subjekt
        || second_subjekt  == third_subjekt) {
        printf("Error\n");
        return 0;
    }
    
    /** Analazing in which subjekt the grade is in and making cuclation on it
     for firts input **/
    
    switch (first_subjekt) {
        case 'A':
            first_score = first_score + 8;
            if (first_score > 100){
                first_score = 100;
            }

            break;
        case 'I':
            first_score = first_score + 2;
            if (first_score > 100){
                first_score = 100;
            }
            break;
        case 'O':
            first_score = first_score - 8;
            if (first_score > 100){
                first_score = 100;
            }

            break;
        case 'D':
            first_score = first_score * 1.06;
            if (first_score > 100){
                first_score = 100;
            }

            break;
        case 'L':
            first_score = 10 * sqrt(first_score);
            if (first_score > 100){
                first_score = 100;
            }
            break;
        default: printf("Error");

    }
    
    /** Analazing in which subjekt the grade is in and making cuclation on it
     for second input **/

    switch (second_subjekt) {
        case 'A':
            second_score = second_score + 8;
            if (second_score > 100){
                second_score = 100;
            }
            
            break;
            
        case 'I':
            second_score = second_score + 2;
            if (second_score > 100){
                second_score = 100;
            }
            break;
            
        case 'O':
            second_score = second_score - 8;
            if (second_score > 100){
                second_score = 100;
            }
            
            break;
            
        case 'D':
            second_score = second_score * 1.06;
            if (second_score > 100){
                second_score = 100;
            }
            
            break;
            
        case 'L':
            second_score = 10 * sqrt(second_score);
            if (second_score > 100){
                second_score = 100;
                break;
            default: printf("Error");

            }
        

    }
    /** Analazing in which subjekt the grade is in and making cuclation on it
     for third input **/

    switch (third_subjekt) {
        case 'A':
            third_score = third_score + 8;
            if (third_score > 100){
                third_score = 100;
            }
            
            break;
            
        case 'I':
            third_score = third_score + 2;
            if (third_score > 100){
                third_score = 100;
            }
            break;
            
        case 'O':
            third_score = third_score - 8;
            if (third_score > 100){
                third_score = 100;
            }
            
            break;
            
        case 'D':
            third_score = third_score * 1.06;
            if (third_score > 100){
                third_score = 100;
            }
            
            break;
            
        case 'L':
            third_score = 10 * sqrt(third_score);
            if (third_score > 100){
                third_score = 100;
            }
        default: printf("Error");
   }
    
    
    if (first_score == second_score)
    {
        switch (first_subjekt) {
            case 'I':
                printf("You received this grade in Introduction to computer science\n");
                break;
                
            default:
                break;
        }
    }
    // printing the hiehst grade.
    
    if (first_score > second_score && first_score > third_score) {
        printf("Your max grade is %.02f\n", first_score);
        switch (first_subjekt) {
            case 'A':
                printf("You received this grade in Algorithms\n");
                break;
                
            case 'I':
                printf("You received this grade in Introduction to computer science\n");
                break;
            
            case 'O':
                printf("You received this grade in Object oriented programming\n");
                break;
                
            case 'D':
                printf("You received this grade in Data Structures\n");
                break;
                
            case 'L':
                printf("You received this grade in Linear algebra\n");
                break;
            default: printf("Error");

        }
  
    }
    
    if (second_score > first_score && second_score > third_score) {
        printf("Your max grade is %.02f\n", second_score);
        switch (second_subjekt) {
            case 'A':
                printf("You received this grade in Algorithms\n");
                break;
                
            case 'I':
                printf("You received this grade in Introduction to computer science\n");
                break;
                
            case 'O':
                printf("You received this grade in Object oriented programming\n");
                break;
                
            case 'D':
                printf("You received this grade in Data Structures\n");
                break;
                
            case 'L':
                printf("You received this grade in Linear algebra\n");
                break;
            default: printf("Error");
                
        }

    }
    if (third_score > first_score && third_score > second_score) {
        printf("Your max grade is %.02f\n", third_score);
        switch (third_subjekt) {
            case 'A':
                printf("You received this grade in Algorithms\n");
                break;
                
            case 'I':
                printf("You received this grade in Introduction to computer science\n");
                break;
                
            case 'O':
                printf("You received this grade in Object oriented programming\n");
                break;
                
            case 'D':
                printf("You received this grade in Data Structures\n");
                break;
                
            case 'L':
                printf("You received this grade in Linear algebra\n");
                break;
            default: printf("Error");

                
        }

    }
    return 0;
    }
