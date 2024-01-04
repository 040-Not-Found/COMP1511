//Week 3 weekly test by z5311209

#include <stdio.h>

int main(void) {
    int integer1, integer2;
    int total;
    scanf("%d ",& integer1);
    scanf("%d",& integer2);
    total = integer1 * integer2;
    if (total > 0) {
        printf("%d\n", total);
    } else if (total == 0) {
        printf("zero\n");
    } else {
        printf("%d\n", -total);
    }
    return 0;
}
