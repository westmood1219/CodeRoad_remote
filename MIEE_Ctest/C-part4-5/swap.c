#include "swap.h"

void swap(int *a, int *b) {
    printf("交换前:a = %d, b = %d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("交换后:a = %d, b = %d\n", *a, *b);
}