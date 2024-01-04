//Week 2 Lab "Leap Year Calculator" by z5311209 Celine Lin

#include <stdio.h>

int main(void) {
    
    int year;
    
    printf("Enter year: ");
    scanf("%d", &year);
    
    if ((year % 4) != 0) {//remainder does not equals to zero
        printf("%d  is not a leap year.\n", year);
    }   
    
    else if ((year % 100) != 0) {
        printf("%d  is a leap year.\n", year);
    }
    
    else if ((year % 400) != 0) {
        printf("%d  is not a leap year.\n", year);
    }
    
    else {
        printf("%d  is a leap year.\n", year);
    }
    
    return 0;
    
}
