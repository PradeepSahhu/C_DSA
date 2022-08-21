#include <stdio.h>

// This is used to print

//There are two values in Queue one for insert Enqueue (rear[r]) and another is for remove (Dequeue (back[b] ));
struct queue{
    int size;
    int r;
    int f;
    int *arr;
};

int isFull(struct queue *q){ //is full condition.
    if(q->r == q->size - 1){
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(struct queue *q, int value){
    if(isFull(q)){
        printf("Queue Overflow");
    } else {
        q->r = q->r+1;
        q->arr[q->r] = value;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(q->f == q->r){
        printf("No Element to Dequeue"); //---> Empty function. or isEmpty();

    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){

    struct queue q;
    q.f = q.r = -1;
    q.size = 20;
    q.arr = (int *) malloc (q.size * sizeof(int));


    



}