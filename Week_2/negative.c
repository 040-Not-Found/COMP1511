//Week 2 Lab "Don't be negative" by z5311209 Celine Lin

#include <stdio.h>

#define ZERO 0

int main(void) {
   
    int input;
    scanf("%d", &input);    
    
    int number = input;
    
    if (number > ZERO) { //if the input number is a positive number
        printf("You have entered a positive number.\n");
    }
    if (number < ZERO) { //if the input number is a negative number
        printf("Don't be so negative!\n");
    }
    if (number == ZERO) { //if the input number is zero
        printf("You have entered zero.\n");    
    }
    
    return 0;
}
