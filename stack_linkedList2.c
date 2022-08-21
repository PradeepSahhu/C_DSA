#include <stdio.h>
#include <stdlib.h>

// Making stack using linkedList

// 1. side 1 will be used for push and pop operations
// 2. head is now -> top
// 3. stack empty condition ->(top == null);
// 4. stack full when -> heap memory is exhausted. <=> [ ptr == null]
// 5. you can always set a custom size.



//********* All the push or pop operations happen on first node of the linked list. *******
struct Node
{
    int data;
    struct Node *next;
};

 struct Node *top = NULL;   // global variable

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1; // 1 means true.
    }
    // return 0;
    else
    {
        return 0; // 0 means false.
    }
}

int isFull(struct Node *top){
    struct Node *n = (struct Node *) malloc (sizeof(struct Node));

    if(n == NULL){
        return 1; // True
    } else {
        return 0; // False
    }

}

struct Node* pushNumber(struct Node *top, int value){
    if(isFull(top)){
        printf("Stack Overflow");
    }
    else {
        struct Node * n = (struct Node * ) malloc(sizeof(struct Node));
        n->data = value;
        n->next = top;
        top = n;
        return top;
    }
};

int popNumber(struct Node* tp){
    if(isEmpty((tp))){
        printf("Stack UnderFlow");
    }
    else{
    struct Node *n = (tp);
        int value = n->data;
        (top) = (tp)->next;
        free(n);
        return value;
    }
}

void linkedListTraversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
};

int main()
{

   
    top = pushNumber(top, 99);
    top = pushNumber(top, 89);
    top = pushNumber(top, 79);
    linkedListTraversal(top);

    printf("POP is running \n");

    int element = popNumber(top);
    printf("The popped Number is %d \n", element);
    linkedListTraversal(top);



    if(isEmpty(top)){
        printf("The stack is empty");

    } else {
        printf("The stack is not empty");
    }
}