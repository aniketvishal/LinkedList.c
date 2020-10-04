// Inter before an element in Linked List
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
void inserbefore(struct Node** head,int number,int data)
{
   struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=data;
     NewNode->next=NULL;
     struct Node* p=*head;
     
     if(p->data==number || *head==NULL)  // if the list is empty or when the fist nodes data matches to the number 
    {
       NewNode->next=*head;
       *head=NewNode;
    }
    else
    {
       printf("I am in");
       while(p->next->next!=NULL) // this neaded to bee checked because if not if condition p->next->data can go unvalid
       {  
           if(p->next->data==number)
           {
               NewNode->next=p->next;
               p->next=NewNode;
               p=p->next;
           }
            p=p->next;
       }
       if(p->next->data==number)   //if the last node's data matches to the number we will need this if beacause of previous while will terminate condition (p->next->next!=NULL) before searching for the data in last node
           {
               NewNode->next=p->next;
               p->next=NewNode;
               
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
    printf("Enter the element before which you want to insert new node");
    scanf("%d",&number);
    inserbefore(&head,number,data);
    printlist(head);
    return 0;
}