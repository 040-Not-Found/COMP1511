//Week 7 lab by z5311209

#include <stdio.h>

int encrypt(int character, int shift);

int main(void) {
    int shift;
    scanf("%d", &shift);
        if (shift >= 26 || shift <= -26) {
            shift = shift % 26;
        }
    int character = getchar();
    while (character != EOF) {

        int new_character = encrypt(character, shift);
        putchar(new_character);

        character = getchar();
    }
    return 0;
}

int encrypt(int character, int shift) {
    if (character >= 'a' && character <= 'z') {
        int alphabetPosition = character + shift;
        if (alphabetPosition <= 'z' && alphabetPosition >= 'a') {
            return alphabetPosition;
        } else if (alphabetPosition > 'z') {
            int real_shift = shift - ('z' - character) - 1;
            alphabetPosition = 'a' + real_shift; 
            return alphabetPosition;
        } else if (alphabetPosition < 'a') {
            int real_shift = shift - ('a' - character);
            alphabetPosition = 'z' + real_shift + 1;
            return alphabetPosition;
        } else {
            return character;
        }
    } else if (character >= 'A' && character <= 'Z') {
        int alphabetPosition = character + shift;
        if (alphabetPosition <= 'Z' && alphabetPosition >= 'A') {
            return alphabetPosition;
        } else if (alphabetPosition > 'Z') {
            int real_shift = shift - ('Z' - character) - 1;
            alphabetPosition = 'A' + real_shift; 
            return alphabetPosition;
        } else if (alphabetPosition < 'A') {
            int real_shift = shift - ('A' - character);
            alphabetPosition = 'Z' + real_shift + 1;
            return alphabetPosition;
        } else {
            return character;
        }
    } else {
        return character;
    }
    
}

