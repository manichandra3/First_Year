#include<stdio.h>
int main(){
    int num,i = 2;
    printf("Enter any integer: ");
    scanf("%d", &num);
    if (num == 0){
        printf("The number is neither prime nor composite.\n");
    }else{
    while (i<10){
        if (num%2 == 0){
            printf("Not Prime.\n");
        }else{
            printf("Prime.\n");
        }
        i++;
        break;
    }
    }
    main();
}