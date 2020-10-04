// onserting elemernts in Linked List using FUnction
#include<stdio.h>   
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void insert(struct Node** head,int Data) //1. here we aRE USING double pounet pointer with the store the addreass of other pointer
{
    struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=Data;
     NewNode->next=NULL;
    if(*head==NULL)//2. if there is no element in linked list we need to directly asign the addrss of NewNode to main head pointer 
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
int main()
{
    struct Node* head=NULL;
    int N,d;
    scanf("%d",&N);
       for(int i=0;i<N;i++)
       {
           scanf("%d",&d);
           insert(&head,d);
       }
    
   printlist(head);
       return 0;
}