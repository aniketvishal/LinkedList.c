// Alternative way to Delete an elemant from linked List
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
       while(p->next!=NULL)
       { 
           if(p->data==data)
           {
               p->data=p->next->data;
               p->next=p->next->next;
           }
               p=p->next;
               if(p==NULL)break;// TO AVOID SEGMENTATION fault if second last node matches to data 
               if(p->next->next==NULL &&  p->next->data==data)// TO AVOID SEGMENTATION fault if last node matches to data 
               { t=1;
                   break;
               }
              
       }
       if(t==1)
       {
           p->next=NULL;
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
    printf("Enter the element you want delete from List");
    scanf("%d",&data);
    delete(&head,data);
    printlist(head);
    return 0;
}