//Qus. from two linked list of the same size, the task is to create a new linked list using those linked lists. The condition is that the greater  node at each Position  among both linked list will be added to the new liked list.
//Approach: We traverse both the linked list at the same time and compare node of both lists. The node which is greater among them will be added to the new linked list. We do this for each node.
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void insert(struct Node** head,int N) //1. here we aRE USING double pounet pointer with the store the addreass of other pointer
{
    int c=0,n;
    struct Node* p;;
    
     while(c!=N)
     {  c++;
     
        printf("Enter %d Elements in LInked list",c);
        if(c==1)//2. if there is no element in linked list we need to directly asign the addrss of NewNode to main head1 pointer 
        {
            struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&n);
            NewNode->data=n;
            NewNode->next=NULL;
            *head=NewNode;
            p=*head;
            
        }
    else{
           struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
          
            scanf("%d",&n);
            NewNode->data=n;
            NewNode->next=NULL;
            
            p->next=NewNode;
           p=p->next;
        }
     }
}
void printlist(struct Node* start) //3. nince we just need to access the values in list to no dounble poiner is Needed here
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
void greater(struct Node **head,struct Node* p1,struct Node* p2)
{    
    struct Node* P;
    if(p1==NULL)
    {
        printf("No elements in Lists");
    }
    else
    {
        while(p1!=NULL )
        {
        struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
          if(p1->data>=p2->data)
          {
            NewNode->data=p1->data;
          }
          else
          {
              NewNode->data=p2->data;
          } 
            NewNode->next=NULL;
          if(*head==NULL)
          {
            *head=NewNode;
            P=*head;
          }      
          else
          {
              P->next=NewNode;
              P=P->next;
          }
        p1=p1->next;
        p2=p2->next;
            
        }
    }
    
}
void main()
{
    struct Node *head1=NULL;
    int N;
    printf("How many elements do you want to insert into linked list");
    scanf("%d",&N);
    printf("Enter Elements for linked list 1\n");
    insert(&head1,N);
    printlist(head1);
    struct Node *head2=NULL;
    printf("\nEnter Elements for linked list 2\n");
    insert(&head2,N);
    printlist(head2);
    struct Node *head3=NULL;
    greater(&head3,head1,head2);
    println("\n");
     printlist(head3);
    return 0;
}