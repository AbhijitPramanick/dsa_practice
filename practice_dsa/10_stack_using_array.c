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

int pop(struct stack *s){
    int poppedVal;
    if(isEmpty(s)){
        printf("\n***** Stack underflow. Cannot pop. Pop unsuccessful. *****\n");
        return -1;
    }
    else{

        poppedVal = s->arr[s->top--];
        printf("\n%d popped successfully\n");
        return poppedVal;
    }
}

int main()
{
    struct stack *s;
    int poppedVal;

    s = (struct stack*)malloc(sizeof(struct stack));

    s->size = 3;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    push(s,1);
    push(s,4);
    display(s);

    push(s,7);
    push(s,9);
    display(s);

    poppedVal = pop(s);
    printf("\nThe popped value : %d\n",poppedVal);
    display(s);

    poppedVal = pop(s);
    printf("\nThe popped value : %d\n",poppedVal);
    display(s);

    poppedVal = pop(s);
    printf("\nThe popped value : %d\n",poppedVal);
    display(s);

    poppedVal = pop(s);
    printf("\nThe popped value : %d\n",poppedVal);
    display(s);

    poppedVal = pop(s);
    printf("\nThe popped value : %d\n",poppedVal);
    display(s);

    return 0;
}