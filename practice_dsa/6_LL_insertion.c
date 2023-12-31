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
void insertEnd(struct node *ptr, int data){
    //Creating a new node
    struct node *p;
    p = (struct node*) malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;

    //Searching for the end node
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    printf("\n\nEnd node having data: %d found. Performing insertion with the new data: %d.\n",ptr->data,p->data);

    //Insertion at the end
    ptr->next = p;

    printf("\n\n------------\nInsertion successful.\n");
}

void insertionAfterNode(struct node * ptr, int element){
    struct node * p;
    p = (struct node*) malloc(sizeof(struct node));
    p->data = element;
    p->next = ptr->next;
    ptr->next = p;
    printf("\n\n------------\nInsertion after node successful.\n");
}

struct node* insertBegin(struct node *ptr, int element){
    struct node*p = (struct node*)malloc(sizeof(struct node));
    p->data = element;
    p->next = ptr;
    printf("\n\n------------\nInsertion successful at beginning.\n");
    return p;
}

struct node* insertAfterIndex(struct node *ptr, int element, int index){
    struct node*p = (struct node *)malloc(sizeof(struct node));
    struct node*head = (struct node *)malloc(sizeof(struct node));
    p->data = element;
    int countIndex = 0;
    if(index<=0){
        return insertBegin(ptr,element);
    }
    else{
        head = ptr;
        while(countIndex!=index && ptr->next!=NULL){
            countIndex++;
            ptr=ptr->next;
        }
        p->next = ptr->next;
        ptr->next = p;
        printf("\n\n------------\nInsertion after index %d successful.\n",index);
        return head;
    }
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

    insertEnd(head,100);

    display(head);

    insertionAfterNode(second,77);

    display(head);

    head = insertBegin(head,111);

    display(head);

    head = insertAfterIndex(head,23,3);

    display(head);

    return 0;
}