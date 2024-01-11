#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} cll;

struct CircularLinkedList 
{
    struct Node *head;
};

void init_cll(struct CircularLinkedList *list) 
{
    list->head = NULL;
}

void add_node(struct CircularLinkedList *list, int data) 
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = list->head;

    if (list->head == NULL) 
    {
        list->head = new_node;
        new_node->next = new_node;
    } 
    else 
    {
        struct Node *current_node = list->head;
        while (current_node->next != list->head) 
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void insert(struct CircularLinkedList *list, int data) 
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = list->head;

    struct Node *current_node = list->head;
    struct Node *previous_node = NULL;

    while (current_node != NULL && current_node->data < data) 
    {
        previous_node = current_node;
        current_node = current_node->next;

        if (current_node == list->head) 
        {
            break;
        }
    }

    if (previous_node == NULL) 
    {
        list->head = new_node;
        new_node->next = current_node;
    } 
    else 
    {
        previous_node->next = new_node;
        new_node->next = current_node;
    }
}


void print(struct CircularLinkedList *list) 
{
    if (list->head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    struct Node *current_node = list->head;
    printf("->");
    while (current_node->next != list->head) 
    {
        printf("%d->", current_node->data);
        current_node = current_node->next;
    }
    printf("%d->", current_node->data);
    printf("\n");
}

int main() 
{
    printf("Question 1 part A.\n");
    struct CircularLinkedList list1;
    init_cll(&list1);
    int n, x;
    printf("Enter the number of elements in list1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        printf("Enter element no. %d: ", i + 1);
        scanf("%d", &x);
        add_node(&list1, x);
    }
    struct Node *current_node1 = list1.head;

    struct CircularLinkedList list2;
    init_cll(&list2);
    int m, y;
    printf("Enter the number of elements in list2: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        printf("Enter element no. %d: ", i + 1);
        scanf("%d", &y);
        add_node(&list2, y);
    }
    struct Node *current_node2 = list2.head;

    struct CircularLinkedList list3;
    init_cll(&list3);
    for (int i = 0; i < n + m; i++) 
    {
        if (i < n) 
        {
            add_node(&list3, current_node1->data);
            current_node1 = current_node1->next;
        } 
        else 
        {
            add_node(&list3, current_node2->data);
            current_node2 = current_node2->next;
        }
    }
    printf("List1 is: ");
    print(&list1);
    printf("List2 is: ");
    print(&list2);
    printf("List3 is: ");
    print(&list3);

    // question 1 part B
    printf("Question 1 part B starts.\n");
    int num;
    char choice;
    struct CircularLinkedList list4;
    init_cll(&list4);
    int l, z;
    printf("Enter the number of nodes in the list: \n");
    scanf("%d", &l);
    for (int i = 0; i < l; i++)
    {
        printf("Enter element no. %d: ", i + 1);
        scanf("%d", &z);
        add_node(&list4, z);
    }
    print(&list4);
    printf("Do you want to insert an element into the above list (y/n): ");
    scanf(" %c", &choice);
    fflush(stdout);
    if (choice == 'y' || choice == 'Y')
    {
        while (choice == 'Y' || choice == 'y')
        {
            printf("Enter the number to be inserted:");
            scanf("%d", &num);
            insert(&list4, num);
            printf("List4 is: ");
            print(&list4);
            printf("Do you want to continue (y/n): ");
            putchar(choice);
            fflush(stdout);
            scanf(" %c", &choice);
        }
    }
    else
    {
        exit(1);
    }
    return 0;
}
