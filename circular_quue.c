#include <stdio.h>
#include <stdlib.h>

// This is used to print

//There are two values in Queue one for insert Enqueue (rear[r]) and another is for remove (Dequeue (back[b] ));
struct circularQueue{
    int size;
    int r;
    int f;
    int *arr;
};

int isFull(struct circularQueue *q){ //is full condition.
    if((q->r+1) % (q->size) == q->f){
        return 1;
    }
    //return 0;
     else {
        return 0;
    }
}

int isEmpty(struct circularQueue *q){
    if(q->f == q->r){
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(struct circularQueue *q, int value){
    if(isFull(q)){
        printf("Queue Overflow \n");
    } else {
        printf("Enqueued Element %d\n", value);
        q->r = (q->r+1)% q->size; //Circular increment.
        q->arr[q->r] = value;
    }
}

int dequeue(struct circularQueue *q){
    int val = -1;

    if(isEmpty(q)){
        printf("No Element to Dequeue \n"); //---> Empty function. or isEmpty();
    }
    // if(q->f == q->r){
    //     printf("No Element to Dequeue"); //---> Empty function. or isEmpty();

    // }
     else {
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
    }
    return val;
}

int main(){

   struct circularQueue q;
    q.f = q.r = 0;
    q.size = 4;
    q.arr = (int *) malloc (q.size * sizeof(int));


// Enqueue few Elements.
enqueue(&q, 12); //Here q is the variable not the pointer.
enqueue(&q, 15);
enqueue(&q, 20);
// enqueue(&q, 20);

printf("Dequeuing Element %d \n", dequeue(&q));
printf("Dequeuing Element %d \n", dequeue(&q));
printf("Dequeuing Element %d \n", dequeue(&q));
// printf("Dequeuing Element %d \n", dequeue(&q));
enqueue(&q, 20);
enqueue(&q, 20);
enqueue(&q, 20);





if(isEmpty(&q)){
    printf("******************* Queue is Empty ************\n");
}

if(isFull(&q)){
    printf("\n ****************** Queue is full **************\n");
}

}