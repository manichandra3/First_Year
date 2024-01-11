#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

int main()
{
    struct Node* head = NULL;
    struct Node* newNode = NULL;
    struct Node* temp = NULL;
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) 
        {
            head = newNode;
            temp = newNode;
        }
        else 
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int i=1;
    struct Node* current = head;
    if(n%2==0)
    {
        while(i < n/2)
        {
            current = current->next;
            i++;
        }
        printf("%d %d\n", current->data, current->next->data);
    }
    else
    {
        while(i <= n/2)
        {
            current = current->next;
            i++;
        }
        printf("%d\n", current->data);
    }

    return 0;
}
