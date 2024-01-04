//Week 2 "Addition" by z5311209 Celine Lin

#include <stdio.h>

int main(void) {

    int numberA;
    int numberB;
    
    printf("Please enter two integers: ");
    scanf("%d ", &numberA);
    scanf("%d", &numberB);
    
    //numberA + numberB = sum
    int sum = numberA + numberB;
    
    printf("%d ", numberA);
    printf("+ %d ", numberB);
    printf("= %d", sum);
    printf("\n");
    
    return 0;
    
} 
