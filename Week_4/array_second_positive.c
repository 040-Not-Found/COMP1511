// COMP1511 Week 4 Lab: Array Second Positive
//
// This program was written by Celine-Lin (z5311209)
// on 27-06-2020
//
// This program finds the second positive number in an array of integers.
//

#include <stdio.h>

#define NOT_POSITIVE_ENOUGH 0

// Returns the second positive number in the array.
// Note: this function must not modify the array.
int array_second_positive(int size, int array[size]) {
    
    int flag = 0;
    int counter = 0;
    
    while (counter < size ) {
        if (flag == 1 && array[counter] > 0 ) {
            return array[counter];
            break;
        }
        if (array[counter] > 0 ) {
            flag = 1;
        }
        counter++;
    }

    return NOT_POSITIVE_ENOUGH;
}


// This is a simple main function that you can use to test your array_second_positive
// function.
// It will not be marked - only your array_second_positive function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your array_second_positive function directly.
// Any changes that you make to this function will not affect the autotests.

#define MAX_SIZE 100

int main(void) {
    int size1 = 7;
    int array1[MAX_SIZE] = {3, -14, 15, 9, 2, 6, 5};

    int result1 = array_second_positive(size1, array1);
    if (result1 == NOT_POSITIVE_ENOUGH) {
        printf("array1 wasn't positive enough!\n");
    } else {
        printf("The second positive value from array1 is: %d\n", result1);
    }

    int size2 = 10;
    int array2[MAX_SIZE] = {-1, -2, -4, 8, -16, -32, -64, -128, -256, 512};

    int result2 = array_second_positive(size2, array2);
    if (result2 == NOT_POSITIVE_ENOUGH) {
        printf("array2 wasn't positive enough!\n");
    } else {
        printf ("The second positive value from array2 is: %d\n", result2);
    }

    int size3 = 10;
    int array3[MAX_SIZE] = {-1, -3, -4, -8, -16, -33, -64, 138, -356, -513};

    int result3 = array_second_positive(size3, array3);
    if (result3 == NOT_POSITIVE_ENOUGH) {
        printf("array3 wasn't positive enough!\n");
    } else {
        printf ("The second positive value from array3 is: %d\n", result3);
    }

    // Note: you can add more tests here (but they won't be marked).

    return 0;
}
