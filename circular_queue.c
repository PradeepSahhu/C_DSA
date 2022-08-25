#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct Queue *q){
    if(q->f == q->r){
        return 1;
    } 
    return 0;
}

int isFull(struct Queue *q){
    if((q->r+1) % (q->size) == q->f){
        return 1;
    } 
    return 0;
}


int dequeue(struct Queue *q){
    int val = -1;
    if(q->r == q->f){
        printf("Empty Queue \n");
    }
    else {
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
        return val;
    }
    return val;
}
void enqueue(struct Queue *q, int value){
    if((q->r+1) % (q->size) == q->f){ 
        printf("Queue Overflow \n");
    } else {
        q->r = (q->r+1)% q->size; // Circular increment.
        q->arr[q->r] = value;
    }
}
int main(){

    struct Queue *q;
    q->size = 4;
    q->r = q->f = 0;
    q->arr = (int *) malloc (q->size * sizeof(int));

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);

    printf("The Dequeue value is %d \n", dequeue(q));
    printf("The Dequeue value is %d \n", dequeue(q));


    return 0;

}