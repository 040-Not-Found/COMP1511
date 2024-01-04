//Week 7 lab test by z5311209
#define LENGTH 1024
#include <stdio.h>

int main(void) {
    int i = 0;
    int array[LENGTH] = {0};
    int num = getchar();
    while (num != EOF) {
        array[i] = num;
        i++;
        num = getchar();
    }
    int length = i;
    i = 0;
    int j = 1;
    while (array[i] != 0) {
        i = 0;
        while (i < length) {
            if (array[i] == j) {
                break;
            } else if (array[i] != j){
                printf("%d", j);
            }
            j++;
            i++;
        }
    }
    return 0;
}

