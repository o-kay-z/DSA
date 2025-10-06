#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;


typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;


Queue* initialize(){
    Queue* temp = malloc(sizeof(Queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}


bool isFull(Queue* q){return false;}
bool isEmpty(Queue* q){return (q->front == NULL);}


void enqueue(Queue* q, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(!(isEmpty(q))){
        q->rear->next = newNode;
        q->rear = newNode;
    }
    else{
        q->front = newNode;
        q->rear = newNode;
    }
   
}


int dequeue(Queue* q){
    if(!(isEmpty(q))){
        Node* temp = q->front;
        int data = q->front->data;
        q->front = q->front->next;


        if(isEmpty(q)){
            q->rear = NULL;
        }


        free(temp);
        return data;
    }
}


int front(Queue* q){
    if(!(isEmpty(q))){ return q->front->data;}
    else{return -1;}
}


void display(Queue* q){
    Node* current = q->front;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main(){
    Queue* q = initialize();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 40);
    enqueue(q, 60);
    int num = dequeue(q);
    int num2 = front(q);
    printf("Dequeued %d, Front %d\n", num, num2);
    display(q);




    return 0;
}

