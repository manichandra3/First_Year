#include <stdio.h>

#pragma pack(1)

union student 
{
    char name[11];
    int roll;
    char sex;
    double gpa;
};

void printStudent(union student s) 
{
    printf("Name: %s\n", s.name);
    printf("Roll: %d\n", s.roll);
    printf("Sex: %c\n", s.sex);
    printf("GPA: %lf\n", s.gpa);
}

void printStudentPtr(union student* sPtr) 
{
    printf("Name: %s\n", sPtr->name);
    printf("Roll: %d\n", sPtr->roll);
    printf("Sex: %c\n", sPtr->sex);
    printf("GPA: %lf\n", sPtr->gpa);
}

int main() 
{
    union student s1 = {"John Smith", 101, 'M', 3.8};
    printf("%s",s1.name);
    printf("Address of s1: %p\n", &s1);
    printf("Address of name: %p\n", s1.name);
    printf("Address of roll: %p\n", &s1.roll);
    printf("Address of sex: %p\n", &s1.sex);
    printf("Address of gpa: %p\n", &s1.gpa);
    printf("Size of union student: %zu bytes\n", sizeof(union student));
    
    printf("\nUsing #pragma pack(1):\n");
    union student s2 = {"Jane Doe", 102, 'F', 3.5};
    printf("Address of s2: %p\n", &s2);
    printf("Address of name: %p\n", s2.name);
    printf("Address of roll: %p\n", &s2.roll);
    printf("Address of sex: %p\n", &s2.sex);
    printf("Address of gpa: %p\n", &s2.gpa);
    
    printf("\nEnter details of five students:\n");
    union student students[5];
    for (int i = 0; i < 5; i++) 
    {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter roll of student %d: ", i+1);
        scanf("%d", &students[i].roll);
        printf("Enter sex of student %d (M/F/T): ", i+1);
        scanf(" %c", &students[i].sex);
        printf("Enter GPA of student %d: ", i+1);
        scanf("%lf", &students[i].gpa);
    }
    
    printf("\nDetails of five students:\n");
    for (int i = 0; i < 5; i++) 
    {
        printStudent(students[i]);
        printf("Address of student %d: %p\n", i+1, &students[i]);
    }
    return 0;
}
