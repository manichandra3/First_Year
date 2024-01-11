#include<stdio.h>
#include<stdlib.h>

struct Node 
{
   int data;
   struct Node* next;
};

void printList(struct Node* head) 
{
   struct Node* current = head;

   while (current != NULL) 
   {
      printf("%d ", current->data);
      current = current->next;
   }
}

void insertAtPosition(struct Node** head, int data, int position) 
{
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;

    if (position == 0) 
    {
      newNode->next = *head;
      *head = newNode;
      return;
    }

   struct Node* current = *head;
   for (int i = 0; current != NULL && i < position - 1; i++) 
   {
      current = current->next;
   }

   if (current == NULL) 
   {
      return;
   }

   newNode->next = current->next;
   current->next = newNode;
}

int main() 
{
   struct Node* head = NULL;
   struct Node* second = NULL;
   struct Node* third = NULL;
   struct Node* end = NULL;
   

   head = (struct Node*)malloc(sizeof(struct Node));
   second = (struct Node*)malloc(sizeof(struct Node));
   third = (struct Node*)malloc(sizeof(struct Node));
   end = (struct Node*)malloc(sizeof(struct Node));

   head->data = 1;
   head->next = second;

   second->data = 2;
   second->next = third;

   third->data = 3;
   third->next = end;

   end->data = 4;
   end->next= NULL;

   insertAtPosition(&head, -1, 0);
   printList(head);
   return 0;
}
