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


bool isEmpty(Queue* q){ return (q->front == NULL);}


void enqueue(Queue* q, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}


int dequeue(Queue* q){
    if(!(isEmpty(q))){
        int data = q->front->data;
        Node* temp = q->front;
        q->front = q->front->next;


        if(isEmpty(q)){
            q->rear = NULL;
        }


        free(temp);
        return data;
    }
}


void display(Queue* q){
    Node* current = q->front;
    printf("Queue: ");
    while(current != NULL){
        printf("%d ", current->data);
        if(current->next != NULL){
            printf("-> ");
        }
        current = current->next;
    }
    printf("\n");
}


int main(){
    Queue* customerQueue = initialize();
    int choice, order, served;


    do{
        printf("What would you like to do?\n[1]Order\n[2]Serve\n[3]Display queue\n[4]Exit\n");
        scanf("%d", &choice);


        switch(choice){
            case 1:
                printf("What would you like to order?");
                scanf("%d", &order);
                enqueue(customerQueue, order);
                break;
            case 2:
                served = dequeue(customerQueue);
                printf("Serving %d\n", served);
                break;
            case 3:
                display(customerQueue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
        }
        printf("\n");


    }while(choice != 4);
   
    return 0;
}

