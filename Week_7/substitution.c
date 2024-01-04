//Week 7 lab by z5311209

#include <stdio.h>

int substitution(int character);

int main(void) {
    int counter = 0;
    int character[26];
    while (counter < 26) {
        character[counter] =  getchar;
    }
    while (character != EOF) {

        int new_character = substitution(character);
        putchar(new_character);

        character = getchar();
    }
    return 0;
}

int substitution(int character) {
    int counter = 0;
    while (counter < 26) {
        if (character[counter] = ) {
            
        }
        counter++;
    }
}

