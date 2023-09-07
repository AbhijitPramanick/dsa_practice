#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void display(struct node * ptr){
    printf("\nThe contents of the Linked List:\n");
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr = ptr->next;
    }
}

struct node * deleteHead(struct node *ptr){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p = ptr;
    ptr = ptr->next;
    free(p);
    return ptr;

}

void deleteEnd(struct node *ptr){
    struct node *p = ptr->next;
    while(p->next != NULL){
        ptr = ptr->next;
        p=p->next;
    }
    ptr->next = NULL;
    free(p);
}
struct node* deleteGivenVal(struct node* ptr, int val){
    struct node*p = ptr->next;
    struct node*head = ptr;

    if(ptr->data==val){
        return deleteHead(ptr);
    }

    while(p!=NULL && p->data!=val){
        ptr=ptr->next;
        p=p->next;
    }
    if(p->data==val){
        ptr->next = p->next;
    }
    else{
        printf("\nValue not found.\n");
    }
    return head;
    free(p);
}
int main()
{
    struct node *head, *second, *third, *fourth;
    
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;
    
    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    display(head);

    // head = deleteHead(head);
    // deleteEnd(head);
    head = deleteGivenVal(head,10);

    display(head);

    return 0;
}