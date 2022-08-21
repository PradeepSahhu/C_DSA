#include <stdio.h>
#include <stdlib.h>

struct stack // array stack
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // 1 means true
    }
    else
    {
        return 0; // 0 means false
    }
}

char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
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

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The stack is Underflow! please push before pop \n");
        return 0;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        // ptr->arr[ptr->top] = [0]; // we can't make our array empty..
        ptr->top--;
        return value;
    }
}

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("The stack overflow! cannot push %d to the stack \n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}



int match(char a, char b){
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    if(a == '(' && b == ')'){
        return 1;
    }
    return 0;

}

int paranthesisMatch(char *exp)
{

    struct stack *sp;
    sp->size = 15;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++) // '\0' means NULL character...
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(sp))
            {
                return 0;
            }

            popped_ch = pop(sp);

            if(!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char *exp = "(8)*(9){}[]()"; // it tells that either the equation is balanced or not in terms of brackets.

    if (paranthesisMatch(exp))
    {
        printf("The paranthesis is Balanced");
    }
    else
    {
        printf("The parantheis is Unbalanced ");
    };

    return 0;
}