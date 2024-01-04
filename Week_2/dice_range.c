//Week 2 Lab "Dice Range" by z5311209 Celine Week

#include <stdio.h>
#define ZERO 0
int main(void){
    
    int sides;
    int rolled;
    
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &sides);
    printf("Enter the number of dice being rolled: ");
    scanf("%d", &rolled);    
    
    if (sides > ZERO && rolled > ZERO) {
    
        int total = sides * rolled;
    
        printf("Your dice range is %d", rolled);
        printf(" to %d.\n", total);

        double average;
        average = (rolled + total) * 0.5;
        
        printf("The average value is %lf\n", average);
        
    } else if (sides <= ZERO || rolled <= ZERO) {
        printf("These dice will not produce a range.\n");
    }
    
    return 0;

}

