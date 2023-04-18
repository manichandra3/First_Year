#include <stdio.h>

int main(void) {
  int n;
  float sum = 0;

  printf("Enter the value of n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    sum += 1.0 / i;
  }

  printf("The sum of the first %d terms is: %f\n", n, sum);

  return 0;
}