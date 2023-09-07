#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void display(struct node *ptr){
    printf("Contents of the linked list:\n");
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    //Allocation of memory in the heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    
    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;
    
    third->data = 14;
    third->next = fourth;

    fourth->data = 34;
    fourth->next = NULL;

    display(head);
    return 0;
}