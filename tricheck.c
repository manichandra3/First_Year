#include<stdio.h>
int main(){
    int a1,a2,a3;
    printf("Enter the angles of the triangle:\n"); 
    printf("Angle 1: ");
    scanf("%d", &a1);
    printf("Angle 2: ");
    scanf("%d", &a2);
    printf("Angle 3: ");
    scanf("%d", &a3);
    if (a1+a2+a3 == 180)
    {
        printf("These lines form a triangle.\n");
    }
    else
    {
        printf("These angle don't form a triangle.\n");
    }
}