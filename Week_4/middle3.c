//Week 4 weekly test by z5311209

#include <stdio.h>

int main (void) {
    int i = 0;
    int integer[3];
    while (i < 3) {
        printf("Enter integer: ");
        scanf("%d", &integer[i]);
        i++;
    } if (integer[0] > integer[1] && integer[0] < integer[2]) {
        printf("Middle: %d\n", integer[0]);
    } else if (integer[1] > integer[0] && integer[1] < integer[2]) {
        printf("Middle: %d\n", integer[1]);
    } else if (integer[2] > integer[0] && integer[2] < integer[1]) {
        printf("Middle: %d\n", integer[2]);
    } else if (integer[0] > integer[2] && integer[0] < integer[1]) {
        printf("Middle: %d\n", integer[0]);
    } else if (integer[1] > integer[2] && integer[1] < integer[0]) {
        printf("Middle: %d\n", integer[1]);
    } else if (integer[2] > integer[1] && integer[2] < integer[0]) {
        printf("Middle: %d\n", integer[2]);
    } else if (integer[0] == integer[1]) {
        printf("Middle: %d\n", integer[0]);
    } else if (integer[2] == integer[1]) {
        printf("Middle: %d\n", integer[1]);
    } else if (integer[0] == integer[2]) {
        printf("Middle: %d\n", integer[0]);
    }
    return 0;
}
