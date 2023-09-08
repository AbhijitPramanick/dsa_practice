// Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node * ptr){
    printf("\nThe contents of the Circular Linked list is :\n---------------\n");
    struct node *p;
    p = ptr;
    do{
        printf("\t%d",ptr->data);
        ptr = ptr->next;
    }while(ptr!=p);
    printf("\n---------------\n");
}

struct node * newNode(){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    printf("\nNew node created.");
    return p;
}

struct node * insertAtHead(struct node * ptr, int val){
    struct node *p = newNode();
    p->data = val;
    struct node *k = ptr;
    do{
        ptr=ptr->next;
    }while(ptr->next!=k);
    ptr->next = p;
    p->next = k;
    printf("New node inserted as head");
    return p;
}

struct node * insertAfterKey(struct node*ptr, int key, int val){
    struct node *k = ptr->next;
    struct node *l = ptr;
    struct node *new = newNode();
    printf("\nFinding the key %d.",key);
    do{
        ptr=ptr->next;
        k=k->next;
    }while(ptr!=l && ptr->data!=key);
    if(ptr->data==key){
        printf("\nKey found!\nPerforming insert after the key %d",key);
        new->data = val;
        ptr->next=new;
        new->next = k;
    }
    else{
        printf("\nKey not found. Insertion unsuccessful.");
    }
    return l;
}
void insertAfterNode(struct node*ptr, int val){
    struct node * new = newNode();
    struct node * k = ptr->next;
    new->data = val;
    ptr->next = new;
    new->next = k;
    printf("\nInsertion after node with data %d is successful.",ptr->data);
}

void insertBeforeNode(struct node * ptr,int val){
    struct node * new = newNode();
    struct node * k = ptr->next;
    struct node *l = ptr;
    new->data = val;
    do{
        ptr=ptr->next;
        k=k->next;
    }while(k!=l);
    ptr->next = new;
    new->next = k;
    printf("\nInsertion before node with data %d is successful.",ptr->data);
}
int main()
{
    struct node *head,*second, *third, *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = head;

    display(head);

    head = insertAtHead(head,23);

    display(head);

    head = insertAfterKey(head,30,33);

    display(head);

    insertAfterNode(third,100);
    display(head);

    insertBeforeNode(fourth,200);
    display(head);



    return 0;
}