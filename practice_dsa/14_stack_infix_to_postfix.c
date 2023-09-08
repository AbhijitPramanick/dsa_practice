//IMplementing infix to postfix conversion using stack

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
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
    printf("\nContents of the stack \n-----------------------------------------\n",(s->top)+1);
    for(int i=0;i<= s->top;i++){
        printf("\t%c",s->arr[i]);
    }
    printf("\n-----------------------------------------\n",s->top, s->size);
}

void push(struct stack *s,char val){
    if(isFull(s)){
        printf("\n***** Stack overflow. Cannot push. Push Unsuccessful!!! ***** \n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
    printf("\n'%c' pushed",val);
    display(s);
}
char pop(struct stack *s){
    char poppedVal;
    if(isEmpty(s)){
        printf("\n***** Stack underflow. Cannot pop. Pop unsuccessful. *****\n");
        return -1;
    }
    else{
        poppedVal = s->arr[s->top--];
        printf("\n'%c' popped",poppedVal);
        display(s);
        return poppedVal;
    }
}
char stackTop(struct stack *s){
    // printf("\nStack top element is %c\n",s->arr[s->top]);
    return s->arr[s->top];
}
int isOperator(char ch){
    if(ch=='/'||ch=='*'||ch=='+'||ch=='-') return 1;
    return 0;
}
int prec(char ch){
    if(ch=='/'||ch=='*') return 3;
    if(ch=='+'||ch=='-') return 2;
    return 1;
}

char* infixToPostfix(char *exp){

    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char*)malloc(s->size*sizeof(char));

    char *ans = (char*)malloc(s->size*sizeof(char));
    int i=0;
    int j=0;
    while(exp[i]!='\0'){
        if(!isOperator(exp[i])){
            ans[j] = exp[i];
            i++;j++;
        }
        else{
            if(isEmpty(s)){
                push(s,exp[i]);
                i++;
            }
            else if(prec(exp[i])>prec(stackTop(s))){
                push(s,exp[i]);
                i++;
            }
            else{
                ans[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        ans[j] = pop(s);
        j++;
    }
    ans[j] = '\0';
    return ans;
}

int main()
{

    char* exp = "a-b*c/q+p";
    printf("\nThe infix expression is %s\n",exp);
    printf("\nThe postfix expression is %s\n\n",infixToPostfix(exp));
    
    return 0;
}