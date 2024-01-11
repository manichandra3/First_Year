#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} link;

void create(link** head, int pos, int data) 
{
    link* newNode = (link*)malloc(sizeof(link));
    newNode->data = data;
    newNode->next = NULL;
    link* ptr = *head;
    if (pos == 0) 
    {
        newNode->next = *head;
        *head = newNode;
    } 
    else 
    {
        for (int i = 0; ptr != NULL && i < pos - 1; i++) 
        {
            ptr = ptr->next;
        }
        if (ptr == NULL) 
        {
            printf("Error: Invalid position\n");
            return;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

link* reverse(link* head) 
{
    link* current = head;
    link* prev = NULL;
    link* next = NULL;
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void print(link* head) 
{
    link* point = head;
    while (point != NULL) 
    {
        printf("%d->", point->data);
        point = point->next;
    }
    printf("\n");
}

void freeList(link* head) 
{
    link* current = head;
    while (current != NULL) 
    {
        link* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() 
{
    link* head = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        create(&head, i, data);
    }
    printf("Original list: ");
    print(head);
    head = reverse(head);
    printf("Reversed list: ");
    print(head);
    freeList(head);
    return 0;
}
