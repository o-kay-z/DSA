#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;


typedef struct Stack{
    Node* top;
}Stack;


Stack* initialize(){
    Stack* temp = malloc(sizeof(Stack));
    temp->top = NULL;
    return temp;
}


bool isEmpty(Stack* s){return s->top == NULL;}


void push(Stack* s, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}


int pop(Stack* s){
    if(!(isEmpty(s))){
        int data = s->top->data;
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
        return data;
    }
    else{
        return -1;
    }
}


int peek(Stack* s){
    if(!(isEmpty(s))) {
        return s->top->data;
    }
    else{
        return -1;
    }
}


int main(){
    Stack* dirty = initialize();
    Stack* hold = initialize();
    Stack* cabinet = initialize();
    int expected = 1;
    bool curse = 0;
    // push(dirty, 2);
    // push(dirty, 5);
    // push(dirty, 3);
    // push(dirty, 1);
    // push(dirty, 4);
    push(dirty, 5);
    push(dirty, 4);
    push(dirty, 3);
    push(dirty, 2);
    push(dirty, 1);


   
    while( !(isEmpty(dirty)) || !(isEmpty(hold))){
        if( !(isEmpty(dirty)) && peek(dirty) == expected){
            int popped = pop(dirty);
            printf("Washing and storing plate %d...\n", popped);
            push(cabinet, popped);
            expected++;
        }
        else if( !(isEmpty(hold)) && peek(hold) == expected){
            int held = pop(hold);
            printf("Washing and storing plate %d...\n", held);
            push(cabinet, held);
            expected++;
        }
        else if(!(isEmpty(dirty))){
            int popped = pop(dirty);
            printf("Holding plate %d...\n", popped);
            push(hold, popped);
        }
        else{
            printf("It's jover. ");
            curse = 1;
            break;
        }
    }


    (curse == 0) ? printf("You won!") : printf("The curse won.");


    return 0;
}

