//Et twitter: Hugo Pouloulou
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int factorial_num(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return n * factorial_num(n - 1);
    }
}

static char* get_Permutation(int n, int k)
{
    int i;
    int *permutation_sz = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        permutation_sz[i] = i + 1;
    }

    char *result = malloc(n + 1);
    for (i = 0; i < n; i++) {
        int fac = factorial_num(n - i - 1);
        int j = k > 1 ? (k - 1) / fac : 0;
        result[i] = permutation_sz[j] + '0';
        k -= j * fac;
        memmove(permutation_sz + j, permutation_sz + j + 1, (n - j) * sizeof(int));
    }
    result[n] = '\0';
    return result;
}

int main(void)
{
   int n = 3;
    int k = 2;
    printf("\nn = %d, k = %d  ", n, k);
    printf("\nKth sequence: %s ",get_Permutation(n, k));
    n = 4;
    k = 7;
    printf("\nn = %d, k = %d  ", n, k);
    printf("\nKth sequence: %s ",get_Permutation(n, k));
    return 0;
}