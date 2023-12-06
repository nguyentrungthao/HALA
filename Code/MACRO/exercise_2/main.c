#include <stdio.h>
#include "lib1.h"
#include "lib1.h"

int main() {
    // add(1, 2, 3, 4, 5);
    printf("%d\n", ADD(2, 3));
    printf("%f\n", ADD(2.1, 3));
    printf("%d\n", sum(2, 3));
    return 0;
}