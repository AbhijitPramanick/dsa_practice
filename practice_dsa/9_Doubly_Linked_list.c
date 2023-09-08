// Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void ForwardDisplay(struct node *ptr){
    printf("\nThe contents of the Doubly Linked list (in forward direction):\n---------------\n");
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n---------------\n");
}
void BackwardDisplay(struct node *ptr){
    printf("\nThe contents of the Doubly Linked list (in backward direction):\n---------------\n");
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr=ptr->prev;
    }
    printf("\n---------------\n");
}

struct node * newNode(){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    printf("\nNew node created.");
    return p;
}

struct node * insertAsHead (struct node * ptr, int val){
    struct node * new = newNode();
    ptr->prev = new;
    new->next = ptr;
    new->prev = NULL;
    new->data = val;
    printf("\nInsertion as Head successful.\n");
    return new;
}
struct node *  insertAsTail(struct node *ptr, int val){
    struct node *new = newNode();
    ptr->next = new;
    new->prev = ptr;
    new->next = NULL;
    new->data = val;
    printf("\nInsertion as Tail successful.\n");
    return new;
}
void insertAfterNode(struct node * ptr, int val){
    struct node * p = newNode();
    p->data = val;

    struct node *ptrNext = ptr->next;

    p->next = ptrNext;
    p->prev = ptr;
    ptr->next = p;
    ptrNext->prev = p;

}
void insertBeforeNode(struct node * ptr, int val){
    struct node * p = newNode();
    p->data = val;

    struct node *ptrPrev = ptr->prev;

    p->prev = ptrPrev;
    p->next = ptr;
    ptr->prev = p;
    ptrPrev->next = p;

}
int main()
{
    struct node *head,*second, *third, *fourth, *newTail;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    newTail = (struct node *)malloc(sizeof(struct node));

    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 40;
    fourth->next = NULL;

    ForwardDisplay(head);
    BackwardDisplay(fourth);

    head = insertAsHead(head,100);
    ForwardDisplay(head);
    BackwardDisplay(fourth);

    newTail = insertAsTail(fourth,200);
    ForwardDisplay(head);
    BackwardDisplay(newTail);

    //Can insert after any node, expect tail node
    insertAfterNode(third,333);
    ForwardDisplay(head);
    BackwardDisplay(newTail);
    //Can insert before any node, expect head node
    insertBeforeNode(second,555);
    ForwardDisplay(head);
    BackwardDisplay(newTail);
    return 0;
}