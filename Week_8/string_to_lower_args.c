#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100

struct charac {
    char word[MAX_WORD_LENGTH];
};

int main(int argc, char *argv[]) {
    int i = 1;
    if (*argv[i] == 'K') {
        printf("kamehameha");
    } else {
        while (argv[i] != NULL) {
            if (*argv[i] >= 'A' && *argv[i] <= 'Z') {
                *argv[i] = *argv[i] - 'A' + 'a';
            }
            fputs(argv[i], stdout);
            printf(" ");
            i++;
        }
    }
    printf("\n");
    return 0;
}

