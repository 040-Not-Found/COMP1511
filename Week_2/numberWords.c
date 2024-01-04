//Week 2 Lab "Numbers to Words" by z5311209 Celine Lin

#include <stdio.h>
#define ONE 1
#define FIVE 5
int main(void) {

    int integer;
    
    printf("Please enter an integer: ");
    scanf("%d", &integer);
    
    if (integer == ONE) {
        printf("You entered one.\n");
    }
    
    if (integer == 2) {
        printf("You entered two.\n");
    }
    
    if (integer == 3) {
        printf("You entered three.\n");
    }
    
    if (integer == 4) {
        printf("You entered four.\n");
    }
    
    if (integer == 5) {
        printf("You entered five.\n");
    }
    
    if (integer > FIVE) { //if the input number greater than five
        printf("You entered a number greater than five.\n");
    }
    
    if (integer < ONE) { //if the input number less than one
        printf("You entered a number less than one.\n");
    } 
        
    return 0;
    
}
