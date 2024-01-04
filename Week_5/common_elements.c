// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination

int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int i = 0;
    int j = 0;
    int k = 0;
    int endloop = 0;
    while (i < length) {//find common_elements
        endloop = 0;
        while (j < length && endloop == 0) {
            if (source1[i] == source2[j]) {//common
            //add the common element into destination then keep looping
                destination[k] = source1[i];
                k++;
                endloop = 1;
            } else {
                j++;
            }
        }
        j = 0;
        i++;
    }
    return k;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
#include <stdio.h>
int main(void) {
    #define length 4
    int source1[length] = {1, 2 ,3, 4};
    int source2[length] = {2, 3, 4, 5};
    int destination[length];//common elements
    //function
    common_elements(length, &source1[length], &source2[length], &destination[length]);
    //print common_elements
    int m = 0;
    int common = common_elements(length, &source1[length], &source2[length], &destination[length]);
    while (m < common) {
        printf("%d", destination[m]);
        m++;
    }
    return 0;
}

