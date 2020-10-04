// All initial operations on Linked List
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
}void inserbefore(struct Node** head,int number,int data)
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
void delete(struct Node** head,int data)
{
     struct Node* p=*head;
     int t=0; 
     if(p->data==data)  // if first alement in list to bee dalated
    {
         *head=p->next;
    }
    else
    {    
       while(p->next->next!=NULL)
       { 
           if(p->next->data==data)
           {
               p->next=p->next->next;
           }
               p=p->next;
               if(p->next==NULL)// TO AVOID SEGMENTATION fault if second last node matches to data 
               {
                   break;
               }
               if(p->next->next==NULL)// TO AVOID SEGMENTATION fault if last node matches to data
               {
                   t=1;
                   break;
               }
       }
       if(t==1)
       if(p->next->data==data)
       {
           p->next=NULL;
       }
        
    } 
}
int main()
{
    struct Node* head=NULL;
    int N,d,i,Choice;
    int number,data;
    printf("Enter the element you want to insert in the list");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&d);
        insert(&head,d);
    }
    while(Choice!=0)
    {
        printf("\n1.To push an element at the begning of list Enter 1");
        printf("\n2.To add an element at the end of list Enter 2");
        printf("\n3.To inser an element after an elemat of list Enter 3");
        printf("\n4.To inser an element before an elemat of list Enter 4");
        printf("\n5.To delete an element from list press 5");
        printf("\n6.To dispay list press 6");
        printf("\n-- Enter 0 if you don't want to perform any operation--\n:-");
        scanf("%d",&Choice);
        switch(Choice)
        {
            case 1:
                    printf("Enter the element you want to push at the begning of list");
                    scanf("%d",&data);
                    push(&head,data);
                    break;
            case 2:        
                printf("Enter the element you want to add  at the end of list");
                scanf("%d",&data);
                append(&head,data);
                break;
            case 3:
                printf("Enter the element you want to insert into list");
                scanf("%d",&data);
                printf("Enter the element after which you want to insert new node");
                scanf("%d",&number);
                inserafter(&head,number,data);
                break;
            case 4:
                printf("Enter the element you want to insert into list");
                scanf("%d",&data);
                printf("Enter the element before which you want to insert new node");
                scanf("%d",&number);
                inserbefore(&head,number,data);
                break;
            case 5:
                printf("Enter the element you want delete from List");
                scanf("%d",&data);
                delete(&head,data);
                break;    
            case 6:
                printlist(head);
                break;
        }
    }
    return 0;
}