#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack // array stack 
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size -1){
        return 1; // 1 means true
    }
    else {
        return 0; // 0 means false
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    { 
        return 1; // 1 means true.
    }
    // return 0;
    else
    {
        return 0; // 0 means false.
    }
}
void push(struct stack * ptr, char value){
    if(isFull(ptr)){
        printf("The stack overflow! cannot push %d to the stack \n", value);
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("The stack is Underflow! please push before pop \n");
        return 'a';
    }else{
        char value = ptr->arr[ptr->top];
        // ptr->arr[ptr->top] = [0]; // we can't make our array empty..
        ptr->top--;
        return value;
    }
}
int stackTop(struct stack *sp){
    return sp->arr[sp->top];
}


int precedence(char character){
    if(character == '*' || character == '/'){
        return 3;
    }
    else if( character == '+' || character == '-'){
        return 2;
    } else {
        return 0;
    }
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }
    else {
        return 0;
    }

}

char * infixToPostfix(char * infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (char *) malloc (sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i = 0; //Trac infix traversal.
    int j = 0; //Track postFix addition.

    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        } else {
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            } else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    };
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char * infix = "a-b+t/6";
    printf("postfix is %s", infixToPostfix(infix));

    return 0;

}