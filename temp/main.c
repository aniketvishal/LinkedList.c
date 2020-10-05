#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void printList(struct Node* N)
{
    while(N!=NULL)
    {
        printf("%d\n",N->data);
        N=N->next;
    }
}
void push(struct Node** head)
{
    struct Node* N=(struct Node*)malloc(sizeof(struct Node));
    int d;
    printf("Enter Data");
    scanf("%d",&d);
    N->data=d;
    N->next=*head;
    *head=N;
}
void insertAfter(struct Node** head)
{
    int d;
    printf("Insert After");
    struct Node* he=*head;
    scanf("%d",&d);
    struct Node* N=(struct Node*)malloc(sizeof(struct Node));
    while()
}
int main()
{
    struct Node* head=NULL;
    push(&head);
     push(&head);
    push(&head);
   
    printList(head);
    return 0;
}
