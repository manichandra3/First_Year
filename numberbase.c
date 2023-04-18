#include <stdio.h>
#include <math.h>

int main() {
   int number, base, target_base, result = 0, i = 0;

   printf("Enter the number: ");
   scanf("%d", &number);
   printf("Enter the base of the number: ");
   scanf("%d", &base);
   printf("Enter the target base: ");
   scanf("%d", &target_base);

   while (number > 0) {
      result += (number % target_base) * pow(10, i);
      number /= target_base;
      i++;
   }

   printf("The equivalent number in base %d is: %d\n", target_base, result);

   return 0;
}

