#include<stdio.h>
int main(){
    char c;
    printf("Enter any character: ");
	scanf("%c", &c);
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		printf("%c is an alphabet in english\n", c);
	}
    else
    {
		if (c >= 48 && c<= 57){
            printf("%c is a number.\n", c);
        }
         else 
        {
        printf("It is something else.\n");
        }
	}
   
}