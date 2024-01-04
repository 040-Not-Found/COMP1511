//Week 5 lab by z5311209

#include <stdio.h>

// swap the values in two integers, given as pointers
void swap_pointers(int *first, int *second) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int tmp;
    tmp = *first;
    *first = *second;
    *second = tmp;
}

// This is a simple main function which could be used
// to test your swap_pointers function.
// It will not be marked.
// Only your swap_pointers function will be marked.

int main(void) {
    int first = 1;
    int second = 2;
    
    swap_pointers(&first, &second);
    
    printf("%d, %d\n", first, second);
    return 0;
}
