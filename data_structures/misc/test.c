#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int data;
    struct queue* next;
} queue;

queue* front = NULL;
queue* rear = NULL;

void enqueue(int data) {
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->data = data;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("The element %d was added to the queue\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("EMPTY\n"); 
        return;
    }
    int r = front->data;
    queue* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    printf("The element %d was removed from the queue\n", r);
    free(temp);
}

void printList(queue* front) {
    queue* temp = front;
    if (temp == NULL) {
        printf("The list is empty\n");
    } else {
        printf("NULL->");
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int d;
    scanf("%d", &d);
    while (d--) {
        int x;
        char c;
        scanf(" %c", &c); 
        if (c == 'e') {
            scanf("%d", &x);
            enqueue(x);
        } else if (c == 'd') {
            dequeue();
        }
        printList(front);
    }
    return 0;
}
