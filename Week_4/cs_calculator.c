//Week 4 Lab by z5311209

#include <stdio.h>
#include <math.h>
#define TRUE 1

int main(void) {
    int scanned_in_value, result, scanned_in_value2;
    while (TRUE) {
        printf("Enter instruction: ");
        result = scanf("%d", &scanned_in_value);
        if (result == EOF) {
            break;
        } else if (scanned_in_value == 1) {
            scanf("%d", &scanned_in_value);
            printf("%d\n", scanned_in_value * scanned_in_value);
        } else if (scanned_in_value == 2 ) {
            scanf("%d", &scanned_in_value);
            scanf("%d", &scanned_in_value2);
            int output = 1;
            for (int counter = 0; counter < scanned_in_value2; counter++) {
                output = output * scanned_in_value;
            }
            printf("%d\n", output);
        }
    }
    return 0;
}
