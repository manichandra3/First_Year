#include <stdio.h>
#include <math.h>

int main() {
    double x;

    // Print the X-axis
    printf("-10  -9  -8  -7  -6  -5  -4  -3  -2  -1   0   1   2   3   4   5   6   7   8   9  10\n");

    // Print the Y-axis
    for(x = -10; x <= 10; x += 0.5) {
        int y = (int)(sin(x) * 10);
        int i;
        for(i = -10; i < y; i++) {
            printf(" ");
        }
        printf("*\n");
    }

    return 0;
}