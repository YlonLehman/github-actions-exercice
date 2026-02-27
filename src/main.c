#include <stdlib.h>
#include "libs/add/add.h"
#include "libs/minus/minus.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("add(%d, %d) = %d\n", num1, num2, add(num1, num2));
    printf("minus(%d, %d) = %d\n", num1, num2, minus(num1, num2));

    return 0;
}