// Parenthesis matching problem can be implemented using stack

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack*ptr){
    if(ptr->top == -1) return 1;
    return 0;
}
int isFull(struct stack *ptr){
    if(ptr->top >= ptr->size-1) return 1;
    return 0;
}

void display(struct stack *s){
    printf("\ncontents of the stack is:\n ------------------------ \n");
    for(int i=0;i<=s->top;i++){
        printf("\t%c",s->arr[i]);
    }
    printf("\n ------------------------ \n Top value : %d, No of elements : %d\n",s->top,s->top+1);
}

void push(struct stack*ptr, char val){
    if(isFull(ptr)){
        printf("\nStack overflow. Cannot push.\n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
    printf("\n%c pushed into stack.",val);
}
char pop(struct stack*ptr){
    char val;
    if(isEmpty(ptr)){
        printf("\nStack Underflow. Cannot pop.\n");
        return -1;
    }
    val = ptr->arr[ptr->top--];
    printf("\n%c popped from stack.",val);
    return val;
}

void clearStack(struct stack*s){
    printf("\nClearing stack for reuse...");
    while(s->top!=-1){
        pop(s);
    }
    printf("\nStack cleared\n");
}
void parenthesisMatch(struct stack *s, char* exp){
    char poppedVal;
    int m=0;
    int isMatch = 1;
    while(exp[m]!='\0'){
        if( (exp[m]=='(') || (exp[m]=='[') || (exp[m]=='{')){
            push(s,exp[m]);
            display(s);
        }
        else if( (exp[m]==')') || (exp[m]==']') || (exp[m]=='}')){
            poppedVal = pop(s);

            if((poppedVal=='(' && exp[m]!=')') || (poppedVal=='[' && exp[m]!=']') || (poppedVal=='{' && exp[m]!='}')){
                printf("\nParenthesis Mis-matched for Expression %s\n",exp);
                isMatch = 0;
                break;
            }
        }
        m++;
    }
    if(!isMatch){
        printf("\n\n*** %s\thas Parenthesis Mis-match. ***\n",exp);
    }
    else if(s->top > -1){
        printf("\n\n*** %s\tParenthesis Mis-matched as stack is not empty. ***\n",exp);
    }
    else if(isMatch){
        printf("\n\n***\t%s\t has Parenthesis match. ***\n",exp);
    }
    display(s);
}
int main()
{
    struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    s->arr = (char*)malloc(s->size * sizeof(char));
    s->size = 50;
    s->top = -1;

    char exp1[]= "{2-[(3-4}*2";
    char exp2[]= "{2-[(3-4)*2]+{[(60/10)/3]*5}}*100";

    printf("\n ************************************************************************* \nThe expression is : %s\n",exp1);    
    parenthesisMatch(s,exp1);

    clearStack(s);

    printf("\n ************************************************************************* \nThe expression is : %s\n",exp2);    
    parenthesisMatch(s,exp2);
    
    return 0;
}