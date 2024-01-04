//Week 4 lab test by z5311209

#include <stdio.h>

int main (void) {
    int number;
    printf("How many numbers: ");
    scanf("%d", &number);
    if (number == 0) {
        printf("The sum is: 0\n");
    } else {
        int i = 0;
        int numbers[number];
        while (i < number) {
            scanf("%d", &numbers[i]);
            i++;
        } 
        int total = 0;
        int j = 0;
        while (j < number) {
            total = total + numbers[j];
            j++;
        }
        printf("The sum is: %d\n", total);
    }
    return 0;
}
