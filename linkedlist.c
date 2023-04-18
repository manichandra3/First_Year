#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

int main() {
    // create the head node
    struct Node *head = malloc(sizeof(struct Node));
    head->value = 1;
    head->next = NULL;

    // create the second node and link it to the head node
    struct Node *second = malloc(sizeof(struct Node));
    second->value = 2;
    second->next = NULL;
    head->next = second;

    // create the third node and link it to the second node
    struct Node *third = malloc(sizeof(struct Node));
    third->value = 3;
    third->next = NULL;
    second->next = third;

    // traverse the linked list and print each value
    struct Node *current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }

    // free the memory allocated for the nodes
    free(head);
    free(second);
    free(third);

    return 0;
}
