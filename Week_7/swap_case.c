//Week 7 lab by z5311209
#include <stdio.h>

int swap_case(int character);

int main(void) {
    int character = getchar();
    while (character != EOF) {

        int new_character = swap_case(character);
        putchar(new_character);

        character = getchar();
    }
    return 0;
}

int swap_case(int character) {
    if (character >= 'a' && character <= 'z') {
        int alphabetPosition = character - 'a';
        return 'A' + alphabetPosition;
    } else if (character >= 'A' && character <= 'Z') {
        int alphabetPosition = character - 'A';
        return 'a' + alphabetPosition;
    } else {
        return character;
    }
}
