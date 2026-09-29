#include <stdio.h>
#include <limits.h>

int sum_to_n(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

int main(void)
{
    int n;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        printf("Error: enter an integer.\n");
        return 1;
    }

    if (n < 1) {
        printf("Error: n must be at least 1.\n");
        return 1;
    }

    if ((long long)n * (n + 1LL) / 2 > INT_MAX) {
        printf("Error: the sum is too large for int.\n");
        return 1;
    }

    printf("Sum from 1 to %d = %d\n", n, sum_to_n(n));
    return 0;
}
