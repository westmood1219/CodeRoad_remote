#include "swap.h"

void swap(int *a, int *b) {
    printf("����ǰ:a = %d, b = %d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("������:a = %d, b = %d\n", *a, *b);
}