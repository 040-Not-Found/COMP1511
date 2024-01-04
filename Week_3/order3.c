//Week 3 lab by z5311209
#include <stdio.h>

int main () {
    int a, b, c, tmp;
    printf ("Enter integer: ");
    scanf ("%d", &a);
    printf ("Enter integer: ");
    scanf ("%d", &b);
    printf ("Enter integer: ");
    scanf ("%d", &c);
    
    //make sure a<b
    if (b < a) {
        tmp = a;
        a = b;
        b = tmp;
    }
    
    if (c < b) {
        tmp = c;
        c = b;
        b = tmp;
    }
    
    if (b < a) {
        tmp = a;
        a = b;
        b = tmp;
    }
    
    printf("The integers in order are: %d %d %d\n", a, b, c);
    return 0;
}
