#include<stdio.h>
#include<stdlib.h>

struct Node {
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

void deleteNode(struct Node** head, int position) {
   if (*head == NULL) {
      return;
   }

   struct Node* temp = *head;
   if (position == 0) 
   {
      *head = temp->next;
      free(temp);
      return;
   }

   for (int i = 0; temp != NULL && i < position - 1; i++) 
   {
      temp = temp->next;
   }

   if (temp == NULL || temp->next == NULL) {
      return;
   }

   struct Node* nextNode = temp->next->next;
   free(temp->next);
   temp->next = nextNode;
}

int main() {
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

    deleteNode(&head, 2); 
    printList(head);
    return 0;
}
