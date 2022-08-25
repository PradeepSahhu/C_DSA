#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node * next;
};

struct Node *f = NULL;
struct Node *r = NULL;

//Condition for Empty Queue.
int isEmpty(struct Node *f){
    if(f == NULL){
        return 1;
    }
    return 0;

}

//Condition for Full Queue.
int isFull(struct Node *n){
    if(n == NULL){
        return 1;
    }
    return 0;
}
// Linked List Traversal...

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the value of the linked list \n");

    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
};

void enqueue( int value){
    struct Node * n = (struct Node *) malloc(sizeof(struct Node));
    if(n == NULL){
        printf("The Stack Overflow");
    }
    else {
        n->data = value;
        n->next = NULL;
        if(f == NULL){
            f=r=n;
        } else {
            r->next = n;
            r=n;
        }
        
    }
}

int dequeue(){
    int value = -1;
    struct Node *ptr = f;
    if(isEmpty(f)){
        return value;
    } else {
        
        f = f->next;
        value = ptr->data;
        free(ptr);
        return value;

    }
}

int main(){



    

    linkedListTraversal(f);
    printf("Dequeing %d \n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(2);
    enqueue(12);
    dequeue();
    
    linkedListTraversal(f);

    return 0;



}