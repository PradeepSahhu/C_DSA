#include<stdio.h>
#include<stdlib.h> //for malloc()
#include<string.h> //for strlen()


// two Strings: infix and postfix and a stack which will act as a medium of operators precedence

struct stack {
    int size;
    int top;
    char* arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct stack *ptr, char value){
    if(isFull(ptr)){
        printf("The Stack is overFlow, You can't push %c ", value);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("The stack is underflow");
    } else {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int precedence(char ch){
    if (ch == '*' || ch == '/'){
        return 3;
    } else if( ch == '+' || ch=='-'){
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

char stackTop(struct stack *sp){
    return sp->arr[sp->top];
}

char * infixTopostFix( char *infix){
    //int *ptr = &a; in just struct stack it is just making a pointer of data type struct stack,
    //however it needs to point somewhere. that's why we use (struct stack *) malloc ((strlen(infix) + 1) * sizeof(char));

    // Making stack to act as a medium between inflix and postflix.
    struct stack *sp = (struct stack *) malloc ( sizeof(struct stack));
    sp->size = 20; // can only hold 20 different precedence of operators.
    sp->top = -1;
    sp->arr = (char *) malloc (sp->size * sizeof(char));

    char * postfix = (char *) malloc ((strlen(infix) + 1) * sizeof(char));

    int i = 0; 
    int j = 0;

    while(infix[i] != '\0'){ //Till infix is not empty.
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        } 
        else {
            if (precedence(infix[i]) > precedence(stackTop(sp))){
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


int main(){


    char * infix = "a+b/c-d*e";
    printf("The postfix value is: %s",infixTopostFix(infix));

    return 0;
    

}