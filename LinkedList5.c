// Inter at the begining of Linked list(Push) and at the end of Linked List(Append)
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void insert(struct Node** head,int Data)
{
    struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=Data;
     NewNode->next=NULL;
     if(*head==NULL)
    {
       *head=NewNode;
    }
    else
    {
       struct Node* p=*head;
       while(p->next!=NULL)
       {
           p=p->next;
       }
       p->next=NewNode;
    }
}
void printlist(struct Node* start)
{
    if(start==NULL)
    {
        printf("No Element in list");
    }
    else
    {
    while(start!=NULL)
    {
        printf("%d-->",start->data);
        start=start->next;
    }
    }
}
void push(struct Node** head,int data)
{
   struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=data;
     NewNode->next=NULL;
       NewNode->next=*head;
       *head=NewNode; 
}
void append(struct Node** head,int data)
{
   struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=data;
     NewNode->next=NULL;
     struct Node* p=*head;

     if(*head==NULL)  // if the list is empty  
    {
       NewNode->next=*head;
       *head=NewNode;
    }
    else
    {    
       while(p->next!=NULL) // this neaded to bee checked because if last node matches to the number this condition will be valid at last node also
       {  
               p=p->next;
       }
        p->next=NewNode;
    } 
}
int main()
{
    struct Node* head=NULL;
    int N,d,i;
    printf("Enter the element you want to insert in the list");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&d);
        insert(&head,d);
    }
    printlist(head);
    int number,data;
    printf("Enter the element you want to push at the begning of list");
    scanf("%d",&data);
    push(&head,data);
    printf("Enter the element you want to add  at the end of list");
    scanf("%d",&data);
    append(&head,data);
    printlist(head);
    return 0;
}