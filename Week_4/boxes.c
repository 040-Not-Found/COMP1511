//Week 4 weekly test by z5311209
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("How many boxes: ");
    scanf("%d", &n);
    
    int pos_x, pos_y, max;
    
    for ( int counter1 = 0; counter1 < 4*n - 1; counter1++) {
        for ( int counter2 = 0; counter2 < 4*n - 1;  counter2++) {
            pos_x = counter1 - (2*n - 1);  
            pos_y = counter2 - (2*n - 1); 
            
            if ( abs(pos_x) > abs(pos_y) ) {
                max = abs(pos_x);
            } else {
                max = abs(pos_y);
            }	
            
            if ( (max % 2) == 1) {
                printf("1");
            } else {
                printf("0");
            }
        }    
        printf("\n");
    }
    
    return 0;
}

