/*
 * week4_1_dynamic_array.c
 * Author: Lafi Haneef Mulakkal
 * Student ID: 251ADB120
 * Description: Allocate an integer array, calculate its sum and
 * average, and release the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    /* Check that the allocation size fits before multiplying. */
    if ((size_t)n > (size_t)-1 / sizeof(int)) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    arr = malloc((size_t)n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            /* Release the allocation even when input fails. */
            free(arr);
            printf("Invalid input.\n");
            return 1;
        }
    }

    /* A wider accumulator reduces the risk of integer overflow. */
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    /* Convert before dividing to preserve the fractional part. */
    double average = (double)sum / n;

    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", average);

    free(arr);
    return 0;
}