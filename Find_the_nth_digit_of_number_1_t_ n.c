#include <stdio.h>

int find_Nth_Digit(int n) {
    unsigned int i, j, k;
    i = j = 1;
    while (n > 9 * i * j) {
        n -= 9 * i * j;
        j *= 10;
        i ++;
    }
    k = j + (n - 1) / i;
    for (j = (n - 1) % i; j < i - 1; j ++) {
        k = k / 10;
    }
    return k % 10;
}

int main(void)
{
  int n = 7;
  printf("\n%d digit of the sequence is %d",n,find_Nth_Digit(n));
  n = 12;
  printf("\n%d digit of the sequence is %d",n,find_Nth_Digit(n));
  return 0;    
}
