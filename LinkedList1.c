#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* next; 
}; 
int main() 
{ 
    struct Node* head,*second,*third; // these all are prointer for the "struct Node" data type 
     
    head = (struct Node*)malloc(sizeof(struct Node)); // those poiners are Dynamically allocaed memory so that it can be used as an object of "struct Node" data type
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
    head->data = 1; 
    head->next = second; 
    second->data = 2; 
    second->next = third; 
    third->data = 3;
    third->next = NULL;
 //                            --------------------------                      -------------------------
 //                           |                           |                   |                         |
 //        head[ 1  | "address of second"  ]                -> second[ 2  |  "address of third" ]       -> third[  3 | NULL ]

    // to Traverse all the allements of this list we are usung "p" and at first ponting it from startr to end till we get NULL at end 
    struct Node* p;
    p=head;
//                            --------------------------                      -------------------------
//                           |                           |                   |                         |
 //    p--->head[ 1  | "address of second"  ]              -> second[ 2  |  "address of third" ]         -> third[  3 | NULL ]


    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
 //                            --------------------------                      -------------------------
 //                           |                           |                   |                         |
 //        head[ 1  | "address of second"  ]                -> second[ 2  |  "address of third" ]       -> third[  3 | NULL ]
 //                                                                                                                      ^
 //                                                                                                                      |
 //                                                                                                                      p
    return 0; 
} 
