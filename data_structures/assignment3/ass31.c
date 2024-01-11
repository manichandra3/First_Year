#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, i;
    struct node* head = NULL;
    struct node* new_node = NULL;
    struct node* temp = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        new_node = (struct node*) malloc(sizeof(struct node));
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &new_node->data);
        new_node->next = NULL;

        if (head == NULL) 
        {
            head = new_node;
            temp = new_node;
        }
        else 
        {
            temp->next = new_node;
            temp = new_node;
        }
    }

    printf("The linked list is: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
