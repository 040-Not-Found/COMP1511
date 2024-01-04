//Week 3 weekly test by z5311209

#include <stdio.h>

int main(void) {
    double num1, num2, num3;
    printf("Please enter three numbers: ");
    scanf("%lf",& num1);
    scanf("%lf",& num2);
    scanf("%lf",& num3);
    
    if (num1 > num2 && num2 > num3) {
        printf("down\n");
    } else if (num3 > num2 && num2 > num1) {
        printf("up\n");
    } else {
        printf("neither\n");
    }
    return 0;
}
