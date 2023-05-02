#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}dll;
dll *head = NULL;
dll *newNode = NULL;
dll *temp = NULL;
int main()
{
    newNode = (dll*)malloc(sizeof(dll));
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int d; 
        printf("Enter the value of node %d: ",i);
        scanf("%d",&d);
        newNode->next = NULL;
        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp->prev
            temp = newNode;
        }
    }
}
