#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(struct Node* head) 
{
    struct Node *i, *j;
    int min_data;

    for (i = head; i != NULL; i = i->next) 
    {
        min_data = i->data;
        for (j = i->next; j != NULL; j = j->next) 
        {
            if (j->data < min_data) 
            {
                swap(&i->data, &j->data);
                min_data = j->data;
            }
        }
    }
}

void printList(struct Node* node) 
{
    while (node != NULL) 
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;


    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 3;
    head->next = second;
    second->data = 1;
    second->next = third;

    third->data = 4;
    third->next = NULL;

    printf("Linked list before sorting: \n");
    printList(head);

    selectionSort(head);

    printf("\nLinked list after sorting: \n");
    printList(head);

    return 0;
}
