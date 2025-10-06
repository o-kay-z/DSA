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


bool isFull(Stack* s){ return false; }
bool isEmpty(Stack* s){return s->top == NULL;}


void push(Stack* s, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("%d pushhed!\n");
}


int pop(Stack* s){
    if(!(isEmpty(s))){
        int popped = s->top->data;
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
        printf("Popped!\n");
        return popped;
    }  
}


int peek(Stack* s){
    if(!(isEmpty(s))){
        return s->top->data;
    }
}


void display(Stack* s){
    Node* current = s->top;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
}
int main(){
    Stack* s = initialize();
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    int popped = pop(&s);
    int peeked = peek(&s);


    printf("Popped %d, Peeked %d\n", popped, peeked);
    display(&s);


    return 0;
}

