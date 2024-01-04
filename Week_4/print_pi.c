//Week 4 Lab by z5311209

#include <stdio.h>
#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int digits;
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &digits);
    //TODO: Insert your code here
    int counter = 0;
    while (counter < digits) {
        if (counter == 1) {
            printf(".");
        }
        printf("%d", pi[counter]);
        counter++;
    }
    printf("\n");
    return 0;
}
