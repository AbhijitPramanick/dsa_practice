//Implementation of Stack using Linked List

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void display(struct node* ptr){
    printf("\nContents of the stack implemented through linked list is:\n -----------------------------------\n");
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr = ptr->next;
    }
    printf("\n -----------------------------------\n");
}

struct node * newNode(){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    return ptr;
}

int isEmpty(struct node *top){
    if(top == NULL) return 1;
    return 0;
}
int isFull(){
    struct node *p = newNode();
    if(p==NULL) return 1;
    return 0;
}

struct node* push(struct node *top, int x){
    if(isFull()){
        printf("\nStack overflow\n");
        return top;
    }

    struct node *p = newNode();
    p->data = x;
    p->next = top;
    top = p;
    printf("\nPush successful.\n");
    return top;
}
struct node* pop(struct node *top){
    struct node* p = top;
    top = top->next;
    printf("\nPopped element : %d\n",p->data);
    free(p);
    printf("\nPop successful.\n");
    return top;
}

void stackBottom(struct node*ptr){
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    printf("\nThe stack bottom element is : %d\n",ptr->data);
}

void stackTop(struct node *ptr){
    printf("\nStack top element is %d\n",ptr->data);
}
int main()
{
    struct node *top = NULL;

    int poppedVal;

    top = push(top,592);
    display(top);
    top = push(top,111);
    display(top);
    top = push(top,789);
    display(top);
    top = push(top,489);
    display(top);
    top = push(top,753);
    display(top);

    top = pop(top);
    display(top);
    top = pop(top);
    display(top);


    stackTop(top);
    stackBottom(top);
    return 0;
}