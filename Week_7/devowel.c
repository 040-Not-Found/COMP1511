//Week 7 lab by z5311209

#include <stdio.h>

//int is_vowel(int character);

int main(void) {
    int ch = getchar();
    while (ch != EOF) {
        if (ch != 'a' && ch != 'e'&& ch != 'i'&& ch != 'o'&& ch != 'u') {
            putchar(ch);
        } else {
        
        }
        ch = getchar();
    }
    return 0;
}

/*int is_vowel(int character) {
    

    return is_vowel;
}*/
