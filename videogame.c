#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    unsigned int crane = 0;
    int stacks;
    int H;
    printf("Enter the number of stacks and H:\n");
    scanf("%d%d",&stacks,&H);
    int* a = malloc(stacks * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    printf("Enter the number of boxes in all the stacks:\n");
    for (int i = 0; i < stacks; i++) {
        scanf("%d", &a[i]);
    }
    printf(" The commands are encoded as follows:\n");
    printf("1 : Move left\n");
    printf("2 : Move right\n");
    printf("3 : Pick up box\n");
    printf("4 : Drop box\n");
    printf("0 : Quit\n");
    int g = 5;
    while(g != 0) {
        printf("Enter the actions:\n");
        scanf("%d",&g);
        if (g == 1) {
            if (crane == stacks) {
                crane = stacks;
            } else {
                crane++;
            }
        }
        if (g == 2) {
            if(crane == 0) {
                crane = 0;
            } else {
                crane--;
            }
        }
        if (g == 3) {
            if (a[crane] == 0) {
                printf("Invalid input.\n");
                break;
            } else {
                a[crane]--;
            }
        }
        if (g == 4) {
            if(a[crane] == H) {
                printf("Invalid input.\n");
                break;
            } else {
                a[crane]++;
            }
        }
    }
    printf("The changed stacks are:\n");
    for(int i = 0; i < stacks; i++) {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
