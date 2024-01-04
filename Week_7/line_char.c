//Week 7 lab test by z5311209

#define LENGTH 256
#include <stdio.h>

int main(void) {
    int i = 0;
    int array[LENGTH] = {0};
    int character = getchar();
    while (character != EOF && character != 10) {
        array[i] = character;
        i++;
        character = getchar();
    }
    int position;
    scanf("%d", &position);
    printf("The character in position %d is '%c'\n", position, array[position]);
    return 0;
}

