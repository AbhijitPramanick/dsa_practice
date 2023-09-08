// Implementation of stack using Array

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s){
    if(s->top==-1) return 1;
    else return 0;
}
int isFull(struct stack *s){
    if(s->top>=s->size-1) return 1;
    else return 0;
}
void display(struct stack *s){
    int i=0;
    printf("\nContents of the stack [%d elements]\n-----------------------------------------\n",(s->top)+1);
    for(int i=0;i<= s->top;i++){
        printf("\t%d",s->arr[i]);
    }
    printf("\n-----------------------------------------\nStack top value = %d\nStack size = %d\n",s->top, s->size);
}

void push(struct stack *s,int val){
    if(isFull(s)){
        printf("\n***** Stack overflow. Cannot push. Push Unsuccessful!!! ***** \n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
    printf("\nElement %d pushed successfully\n",val);
}

void peek(struct stack *s, int pos){
    int indexNo = (s->top)+1-pos;
    printf("\nElement at position [%d] and Index no. [%d] is : %d\n",pos,indexNo,s->arr[indexNo]);
}
void stackBottom(struct stack *s){
    printf("\nStack bottom element is %d\n",s->arr[0]);
}
void stackTop(struct stack *s){
    printf("\nStack top element is %d\n",s->arr[s->top]);
}
int main()
{
    struct stack *s;
    int poppedVal;

    s = (struct stack*)malloc(sizeof(struct stack));

    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    push(s,180);
    push(s,410);
    push(s,76);
    push(s,930);
    push(s,96);
    push(s,103);
    display(s);

    stackTop(s);
    stackBottom(s);
    peek(s,3);
    peek(s,5);
    return 0;
}