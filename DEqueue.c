#include <stdio.h>
#include <stdlib.h>

// This is used to print

//There are two values in Queue one for insert Enqueue (rear[r]) and another is for remove (Dequeue (back[b] ));
struct queue{
    int size;
    int r;
    int f;
    int *arr;
};


//******************************************
/*
Normal Queue;
f --- dequeue
r --- enqueue

DEqueue;
dequeueF --- int value = q->arr[q->f];
            q->f++;
enqueueF --- q->f--;
            q->arr[q->f] = value;

enqueueR --- q->r++;
q->arr[q->r] = value;

dequeueR --- 
int value = q->arr[q->r];
q->r--;
return value;


*/

int isFull(struct queue *q){ //is full condition.
    if(q->r == q->size - 1){
        return 1;
    }
    //return 0;
     else {
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

void enqueueR(struct queue *q, int value){
    if(isFull(q)){
        printf("Queue Overflow");
    } else {
        q->r = q->r+1; //q->r++;
        q->arr[q->r] = value;
    }
}

int dequeueR(struct queue *q){
    int value = -1;
    if(isEmpty(q)){
        printf("Queue UnderFlow");
    } else {
        value = q->arr[q->r];
        q->r--;
        
    }
    return value;
}

int dequeueF(struct queue *q){
    int value = -1;

    if(isEmpty(q)){
        printf("No Element to Dequeue"); //---> Empty function. or isEmpty();
    }
    // if(q->f == q->r){
    //     printf("No Element to Dequeue"); //---> Empty function. or isEmpty();

    // }
     else {
        q->f++;
        value = q->arr[q->f];
    }
    return value;
}

void enqueueF(struct queue *q, int value){
    if(isFull(q)){
        printf("Stack overflow \n");
    } else {
        q->arr[q->f] = value;
        q->f--;
    }
}


//Display the DEqueue element
void display(struct queue *q){
    int i = 0;
    while(i<=(q->r)){
        printf("Element: %d \n", q->arr[i]);
        i++;
    }
}



int main(){

    struct queue q;
    q.f = q.r = -1;
    q.size = 10;
    q.arr = (int *) malloc (q.size * sizeof(int));


// Enqueue few Elements.
enqueueF(&q, 12);
enqueueF(&q, 13);
enqueueF(&q, 14);
enqueueF(&q, 15);


printf("Dequeuing Element %d \n", dequeueF(&q));
printf("Dequeuing Element %d \n", dequeueF(&q));
printf("Dequeuing Element %d \n", dequeueF(&q));
printf("Dequeuing Element %d \n", dequeueF(&q));

display(&q);



if(isEmpty(&q)){
    printf("Queue is Empty \n");
}

if(isFull(&q)){
    printf("Queue is full \n");
}
    

    return 0;

}