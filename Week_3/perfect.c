//Week 3 lab by z5311209

#include <stdio.h>

int main(void) {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    
    printf("The factors of %d are:\n", number);
    
    int factors = 1;
    int sum = 0;
    while (factors <= number) {
        if (number % factors == 0) {
            printf("%d\n", factors);
            sum = sum + factors;
        }
        factors++;
    }
    printf("Sum of factors = %d\n", sum);
    
    if (sum % number == 0) {
        printf("%d is a perfect number\n", number);
    } else {
        printf("%d is not a perfect number\n", number);
    }

    return 0;
}
