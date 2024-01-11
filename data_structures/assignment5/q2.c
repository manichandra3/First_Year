#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct stack 
{
    int arr[MAX_SIZE];
    int top;
} stack;

void initialize(stack *s) 
{
    s->top = -1;
}

int is_empty(stack *s) 
{
    return s->top == -1;
}

int is_full(stack *s) 
{
    return s->top == MAX_SIZE - 1;
}

void push(stack *s, int data) 
{
    if (is_full(s)) 
    {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(stack *s) 
{
    if (is_empty(s)) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

typedef struct queue 
{
    stack s1, s2;
} queue;

void initialize_queue(queue *q) 
{
    initialize(&q->s1);
    initialize(&q->s2);
}

void enqueue(queue *q, int data) 
{
    push(&q->s1, data);
}

int dequeue(queue *q) 
{
    if (is_empty(&q->s2)) 
    {
        while (!is_empty(&q->s1)) 
        {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

int main() 
{
    queue q;
    initialize_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    return 0;
}
