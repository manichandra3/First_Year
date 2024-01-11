#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct ListNode** head, int value) {
    struct ListNode* newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printLinkedList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("->NULL");
    printf("\n");
}

void freeLinkedList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int getLength(struct ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct ListNode* rotateLinkedList(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    int length = getLength(head);
    k = k % length;

    if (k == 0) {
        return head;
    }

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    int count = 0;

    while (count < k) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev->next = NULL;

    struct ListNode* newHead = curr;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = head;

    return newHead;
}

int main() {
    struct ListNode* head = NULL;
    int n, k;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&head, value);
    }

    printf("Enter the number of nodes to rotate: ");
    scanf("%d", &k);

    printf("Original Linked List: ");
    printLinkedList(head);

    struct ListNode* rotatedHead = rotateLinkedList(head, k);

    printf("Rotated Linked List: ");
    printLinkedList(rotatedHead);

    freeLinkedList(rotatedHead);

    return 0;
}
