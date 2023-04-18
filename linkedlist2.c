#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node_t 
{
    int data;
    struct Node_t *next;
} Node_t, *Node;
Node newNode(int data, Node next) 
{
    Node node = (Node) calloc(1, sizeof (Node_t));
    node->data = data;
    node->next = next;
    return node;
}
void addFirst(Node *pnode, int data) 
{
    *pnode = newNode(data, *pnode);
}
void addLast(Node *pnode, int data) 
{
    if (*pnode == NULL) 
    {
        addFirst(pnode, data);
        return;
    }
    Node node = *pnode;
    while (node->next)
    node = node->next;
    node->next = newNode(data, node->next);
}
int addAt(Node *pnode, int data, int index) 
{
    if (index == 0)
    {
        addFirst(pnode, data);
        return 1;
    }
    Node node = *pnode;
    for (index--; node && index; index--)
    node = node->next;
    if (!node) return 0;
    node->next = newNode(data, node->next);
}
int removeFirst(Node *pnode) 
{
    if (*pnode == NULL)
    return INT_MAX;
    Node node = *pnode;
    *pnode = node->next;
    int data = node->data;
    free(node);
    return data;
}
int removeLast(Node *pnode) 
{
    if (*pnode == NULL || (*pnode)->next == NULL)
    removeFirst(pnode);
    Node node = *pnode;
    while (node->next->next)
    node = node->next;
    int data = node->next->data;
    free(node->next);
    node->next = NULL;
    return data;
}
int removeFrom(Node *pnode, int index) 
{
    if (index == 0)
    return removeFirst(pnode);
    Node node = *pnode;
    for (index--; index; index--)
    node = node->next;
    if (node->next == NULL)
    return INT_MAX;
    int data = node->next->data;
    Node temp = node->next;
    node->next = node->next->next;
    free(temp);
    return data;
}
void printList(Node node) 
{
    while (node) 
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
int main() 
{
    Node list = NULL;
    printList(list);
    addFirst(&list, 10);
    printList(list);
    addFirst(&list, 9);
    printList(list);
    addFirst(&list, 8);
    printList(list);
    addLast(&list, 11);
    printList(list);
    addLast(&list, 12);
    printList(list);
    addLast(&list, 13);
    printList(list);
    int data = removeFirst(&list);
    printf("Removed: %d\n", data);
    printList(list);
    data = removeLast(&list);
    printf("Removed: %d\n", data);
    printList(list);
    int index = 0;
    data = 8;
    if (addAt(&list, data, index))
        printf("Added %d at %d.\n", data, index);
    else
    printf("Failed to add %d at %d.\n", data, index);
    printList(list);
    index = 15;
    data = 13;
    if (addAt(&list, data, index))
        printf("Added %d at %d.\n", data, index);
    else
        printf("Failed to add %d at %d.\n", data, index);
    printList(list);
    index = 5;
    data = 13;
    if (addAt(&list, data, index))
        printf("Added %d at %d.\n", data, index);
    else
        printf("Failed to add %d at %d.\n", data, index);
    printList(list);
    index = 5;
    data = removeFrom(&list, index);
    if (data != INT_MAX)
        printf("Added %d from %d.\n", data, index);
    else
        printf("Failed to add %d from %d.\n", data, index);
    printList(list);
    index = 0;
    data = removeFrom(&list, index);
    if (data != INT_MAX)
        printf("Added %d from %d.\n", data, index);
    else
        printf("Failed to add %d from %d.\n", data, index);
    printList(list);
    index = 2;
    data = removeFrom(&list, index);
    if (data != INT_MAX)
        printf("Added %d from %d.\n", data, index);
    else
        printf("Failed to add %d from %d.\n", data, index);
    printList(list);
}