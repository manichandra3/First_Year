#include <stdio.h>
#include <stdlib.h>


typedef struct Node 
{
  int data;
  struct Node* prev;
  struct Node* next;
} dll;


dll* head = NULL;


void addNode(int data) 
{

  dll* newNode = (dll*) malloc(sizeof(dll));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;


  if (head == NULL) 
  {
    head = newNode;
  } 

  else 
  {
    dll* current = head;
    while (current->next != NULL) 
    {
      current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
  }
}

int main() 
{

  int n;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);


  for (int i = 0; i < n; i++) 
  {
    int data;
    printf("Enter the value for node %d: ", i+1);
    scanf("%d", &data);
    addNode(data);
  }


  dll* current = head;
  printf("The doubly linked list is: ");
  while (current != NULL) 
  {
    printf("%d ", current->data);
    current = current->next;
  }
  
  // Find the middle node of the list
  int i = 1;
  dll* ptr = head;
  while (i < n/2 && ptr->next != NULL) 
  {
    ptr = ptr->next;
    i++;
  }
  if (n % 2 == 0 && ptr->next != NULL) 
  {
    printf("\nThe middle node is: %d\n", ptr->next->data);
  } 
  else 
  {
    printf("\nThe middle node is: %d\n", ptr->next->data);
  }
  
  return 0;
}
