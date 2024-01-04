//Week 3 Lab by z5311209

#include <stdio.h>

int main(void) {
    int size;

    #define TWO 2
    printf("Enter size: ");
    scanf("%d", &size);
    if (size % TWO == 0 || size < 5) {
        return 1;
    } else {
        //top part
        int counterOne = 1;
        int counterTwo = size;
        int counterThree = 0;
        int counterFour = size;

        int dashes = (size)/2;
        
        while (counterOne <= (size) / 2) {
            while (counterTwo > size) {//left part dashes
                printf("-");
                counterTwo--;
            }
            printf("*-");//stars
            while (counterThree < dashes - 1) {//middle part dashes
                printf("--");
                counterThree++;
            } 
            counterThree = counterOne;
            printf("*");
            while (counterFour > size) {//right part dashes
                printf("-");
                counterFour--;
            }
            counterTwo = size + counterOne; 
            counterFour = size + counterOne;
            printf("\n");
            counterOne++;
        }
        //middle part
        int counterFive = 0;
        int counterSix = 0;      
          
        while (counterFive <= dashes -1) {
            printf("-");
            counterFive++;
        }
        printf("*");
        while (counterSix <= dashes -1) {
            printf("-");
            counterSix++;
        }
        printf("\n");
        //bottom part
        counterOne = 1;
        counterTwo = 0;
        counterThree = dashes;
        counterFour = 0;
        
        while (counterOne <= (size) / 2) {
            while (counterTwo < dashes - 1) {
                printf("-");
                counterTwo++;
            }
            printf("*-");
            while (counterThree > dashes) {
                printf("--");
                counterThree--;
            } 
            counterThree = counterOne;
            printf("*");
            while (counterFour < dashes -1) {
                printf("-");
                counterFour++;
            }
            counterTwo = counterOne;
            counterFour = counterOne;
            counterThree = dashes + counterOne;
            printf("\n");
            counterOne++;
        }
        return 0;
    }
}
