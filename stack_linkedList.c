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
    struct Node *n = (struct Node *) malloc (sizeof(struct Node)); //If we cant allocate memory dynamically, it means stack is full.

    if(n == NULL){
        return 1; // True
    } else {
        return 0; // False
    }

}

struct Node* pushNumber(struct Node *top, int value){
    if(isFull(top)){
        printf("Stack Overflow");
        return top;
    }
    else {
        struct Node * n = (struct Node * ) malloc(sizeof(struct Node));
        n->data = value;
        n->next = top;
        top = n;
        return top;
    }
};

int popNumber(struct Node** top){
    if(isEmpty((*top))){
        printf("Stack UnderFlow");
    }
    else{
    struct Node *n = (*top);
        int value = n->data;
        (*top) = (*top)->next;
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

    struct Node *top = NULL;
    top = pushNumber(top, 99);
    top = pushNumber(top, 89);
    top = pushNumber(top, 79);
    linkedListTraversal(top);

    printf("POP is running \n");

    int element = popNumber(&top);
    printf("The popped Number is %d \n", element);
    linkedListTraversal(top);





    // struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    // struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    // struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    // struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    // //point to head(top);
    // top->data = 1;
    // top->next = second;

    // //point to second.
    // second->data = 11;
    // second->next = third;

    // //point to third.
    // third->data = 12;
    // third->next = fourth;

    // //point to fourth.
    // fourth->data = 13;
    // fourth->next = fifth;

    // //point to fifth.
    // fifth->data = 14;
    // fifth->next = NULL;

    // isEmpty(top);

    if(isEmpty(top)){
        printf("The stack is empty");

    } else {
        printf("The stack is not empty");
    }
}