#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10


typedef struct {
    int items[MAX];
    int count;
} List;


typedef struct {
    List list;
    int front;
    int rear;
} Queue;


Queue* initialize(){
    Queue* temp = malloc(sizeof(Queue));
    temp->list.count = 0;
    temp->front = -1;
    temp->rear = -1;
    return temp;
}


void enqueue(Queue* q, int value){
    if(!(isFull(q))){
        if(!(isEmpty(q))){
            q->rear = (q->rear + 1) % MAX;
        }
        else{
            q->front = 0;
            q->rear = 0;
        }
        q->list.items[q->rear] = value;
        q->list.count++;
    }
    else{
        printf("Queue is full.\n");        
    }
}


int dequeue(Queue* q){
    int removed = -1;
    if (!(isEmpty(q))){
        removed = q->list.items[q->front];


        if(q->list.count == 1){
            q->front = -1;
            q->rear = -1;
        }
        else{
            q->front = (q->front + 1) % MAX;
        }
        q->list.count--;
        return removed;
    }
    else{
        return removed;
    }
}


bool isFull(Queue* q){
    return (q->list.count == MAX);
}


bool isEmpty(Queue* q){
    return (q->list.count == 0);
}


int front(Queue* q){
    if(!(isEmpty(q))){
        return q->list.items[q->front];
    }
    else{
        printf("Queue is empty");
        return 0;
    }
}


void display(Queue* q){
    if(!(isEmpty(q))){
        int i = q->front;
        int count = q->list.count;
        while(count > 0){
            printf("%d ", q->list.items[i]);
            i = (i + 1) % MAX;
            count--;
        }
        printf("\n");
       
    }
    else{
        printf("Queue is empty.\n");
    }
   
}


int main(){
    Queue* q = initialize();
    int line = 0;
   
    int choice;
    do{
        printf("What would you like to do?\n");
        printf("1. Enter  Queue\n2. Check next in queue\n3. Call Next Customer \n4. Display Queues \n5. Exit\n");
        scanf("%d", &choice);
       
        switch(choice){
            case 1:
                if(!(isFull(q))){
                    enqueue(q, line);
                    printf("You have entered the queue. Your number is %d.\n", line);
                    line++;                    
                }
                else{
                    printf("Queue is full. Please try again later.\n");
                }                
                break;
            case 2:
                printf("The next in call is number %d", front(q));
                break;
            case 3:
                if(!(isEmpty(q))){
                    int removed = dequeue(q);
                    printf("Calling next customer from the Queue. Customer number: %d\n", removed);
                }
                else{
                    printf("Queue is empty.");
                }
                break;
            case 4:
                display(q);
                break;
            case 5:
                printf("Exiting the program...");
                break;
            default:
                printf("Not an option. Try again.");
        }
        printf("\n");
    }while(choice != 5);
    return 0;
}

