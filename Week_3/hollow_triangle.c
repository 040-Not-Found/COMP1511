//Week 3 Lab by z5311209

#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    printf("*\n");
    printf("**\n");
    int counter1 = 0;
    int counter2 = size;
    while (counter1 <= size - 4) {
        printf("*");
        counter1++;
        while (counter2 >= size) {
            printf(" ");
            counter2--;
        } counter2 = counter1 + size;
        printf("*\n");
    }
    int counter3 = 0;
    while (counter3 < size) {
        printf("*");
        counter3++;
    } printf("\n");
    return 0;
}
