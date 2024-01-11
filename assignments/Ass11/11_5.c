struct U 
{
   char char_member;
   float float_member;
};

struct P 
{
   char char_member;
   struct U union_member;
};

struct S 
{
   int int_member;
   struct P nested_structure;
};
#include <stdio.h>

int main() 
{
   struct S my_object;
   printf("Enter an integer value: ");
   scanf("%d", &my_object.int_member);
   printf("Enter a character value: ");
   scanf(" %c", &my_object.nested_structure.char_member);
   printf("Enter a character value: ");
   scanf(" %c", &my_object.nested_structure.union_member.char_member);
   printf("Enter a float value: ");
   scanf("%f", &my_object.nested_structure.union_member.float_member);
   
   printf("Integer value: %d\n", my_object.int_member);
   printf("Character value (P): %c\n", my_object.nested_structure.char_member);
   printf("Character value (U): %c\n", my_object.nested_structure.union_member.char_member);
   printf("Float value: %f\n", my_object.nested_structure.union_member.float_member);

   return 0;
}
