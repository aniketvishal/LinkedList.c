#include <stdio.h>  
#include <stdlib.h>  
struct Node {  
    int data;  
    struct Node* next;  
    struct Node* prev;  
};  
void append(struct Node** head_ref, int new_data) 
{  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* last = *head_ref; 
   new_node->data = new_data; 
   new_node->next = NULL; 
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
   while (last->next != NULL) 
        last = last->next; 
  last->next = new_node; 
   new_node->prev = last; 
    return; 
} 
void push(struct Node** head_ref, int new_data)  
{  
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  
  
    new_node->data = new_data;  
  
    new_node->next = (*head_ref);  
    new_node->prev = NULL;  
  
    if ((*head_ref) != NULL)  
        (*head_ref)->prev = new_node;  
  
    (*head_ref) = new_node;  
}  
void printList(struct Node* node)  
{  
    struct Node* last;  
    printf("\nTraversal in forward direction \n");  
    while (node != NULL) {  
        printf(" %d ", node->data);  
        last = node;  
        node = node->next;  
    }  
  
    printf("\nTraversal in reverse direction \n");  
    while (last != NULL) {  
        printf(" %d ", last->data);  
        last = last->prev;  
    }  
}  
int main()  
{  
    /* Start with the empty list */
    struct Node* head = NULL;  
    int N,d;
    printf("How many elements you want to add at the end of Duble LInked list(append):-");
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    { scanf("%d",&d);
        append(&head,d);
    }
    printf("How many elements you want to add at the begining of Duble LInked list(push):-");
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    { scanf("%d",&d);
        push(&head,d);
    }
    printf("\nprinting Double Linked List: ");  
    printList(head);  
  
    getchar();  
    return 0;  
}  