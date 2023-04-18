#include<stdio.h>
union student 
{
    char name[11];
    int roll;
    float gpa;
    double marks;
};
int main()
{
    int name[11];
    printf("Enter the name of the student.");
    union student s;
    //inputs
    printf("Enter the name of the student. ");
    scanf("%s",s.name);
    printf("Enter the roll number of the student. ");
    scanf("%d",&s.roll);
    printf("Enter the gpa of the student. ");
    scanf("%f",&s.gpa);
    printf("Enter the marks of the student. ");
    scanf("%lf",&s.marks);
    //addresses
    printf("The address of the union is %p\n",&s);
    printf("The address of s.name is %p\n",s.name);
    printf("The address of s.roll is %p\n",&s.roll);
    printf("The address of gpa is %p\n",&s.gpa);
    printf("The address of marks is %p\n",&s.marks);
    int length = sizeof(union student);
    printf("%d\n",length);
}