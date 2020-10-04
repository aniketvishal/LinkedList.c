// Inter after an element in Linked List
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
void inserafter(struct Node** head,int number,int data)
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
       
       while(p!=NULL) // this neaded to bee checked because if last node matches to the number this condition will be valid at last node also
       {  
           if(p->data==number)
           {
               NewNode->next=p->next;
               p->next=NewNode;
               p=p->next;
           }
            p=p->next;
       }
       
       
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
    printf("Enter the element you want to insert into list");
    scanf("%d",&data);
    printf("Enter the element after which you want to insert new node");
    scanf("%d",&number);
    inserafter(&head,number,data);
    printlist(head);
    return 0;
}