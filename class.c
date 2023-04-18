#include<stdio.h>
#include<stdlib.h>

struct node
{
    int a;
    struct node *next;
};

void insert_begin(struct node**, int);
void insert_end(struct node**, int);
void print(struct node *h)
{
    printf("\n");
    while (h != NULL)
    {
        printf("%d -->", h->a);
        h = h->next;
    }
}

void main()
{
    struct node *temp, *head;
    int i;
    head = (struct node *)malloc(sizeof(struct node));
    head -> a = 1;
    temp = head;

    for (i = 1; i < 10; i++)
    {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node -> next = NULL;
        node -> a = i + 1;
        temp -> next = node;
        temp = temp -> next;
    }

    print(head);    
}
