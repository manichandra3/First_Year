#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* curr = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        int digit = sum % 10;
        carry = sum / 10;
        
        struct Node* newNode = createNode(digit);
        
        if (result == NULL) {
            result = newNode;
            curr = result;
        } else {
            curr->next = newNode;
            curr = curr->next;
        }
    }
    
    return result;
}

void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("->NULL");
    printf("\n");
}

void freeLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;

    int n1, n2;
    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first linked list: ");
    for (int i = 0; i < n1; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&l1, value);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second linked list: ");
    for (int i = 0; i < n2; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&l2, value);
    }

    struct Node* sum = addTwoNumbers(l1, l2);

    printf("Result: ");
    printLinkedList(sum);

    freeLinkedList(l1);
    freeLinkedList(l2);
    freeLinkedList(sum);

    return 0;
}
