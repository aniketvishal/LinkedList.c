//
//  link.c
//  Data Structures
//
//  Created by Aniket Vishal on 05/12/19.
//  Copyright © 2019 Aniket Vishal. All rights reserved.
//

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
int main()
{
    struct Node* head=NULL;
    struct Node* second=NULL;
    struct Node* third=NULL;
    
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    printList(head);
    return 0;
}
