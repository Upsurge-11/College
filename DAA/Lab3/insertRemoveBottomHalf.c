#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
  int data;
  struct node *next;
};

void push(struct node **head_ref, int new_data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void deleteNode(struct node **head_ref, int key)
{
  struct node *temp = *head_ref, *prev;
  if (temp != NULL && temp->data == key)
  {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
    return;
  prev->next = temp->next;
  free(temp);
}

void printList(struct node *node)
{
  while (node != NULL)
  {
    printf(" %d ", node->data);
    node = node->next;
  }
}

void minElementsKoDhundo(struct node **q, int n)
{
  for (int i = 0; i < n / 2; i++)
  {
    struct node *r;
    int min = INT_MAX;
    r = *q;
    while (r != NULL)
    {
      if (r->data < min)
      {
        min = r->data;
      }
      r = r->next;
    }
    deleteNode(q, min);
  }
}

int main()
{
  struct node *head = NULL;
  int i = 0, n = 0;
  while (1)
  {
    printf("Enter the data(-1 to cancel) :- \n");
    scanf("%d", &i);
    if (i == -1)
    {
      break;
    }
    n++;
    push(&head, i);
  }
  puts("Created Linked List: ");
  printList(head);
  minElementsKoDhundo(&head, n);
  puts("\nLinked List after Deletion of minimum: ");
  printList(head);
  return 0;
}