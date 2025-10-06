#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 5


typedef struct{
    int items[MAX_SIZE];
    int top;
}Stack;


Stack* initialize(){
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    temp->top = -1;
    return temp;
}


bool isFull(Stack* s){
    return(s->top == MAX_SIZE - 1);
}


bool isEmpty(Stack* s){
    return(s->top == -1);
}


void push(Stack* s, int value){
    if(!(isFull(s))){
        s->top++;
        s->items[s->top] = value;
    }
    else{
        printf("Stack is full.\n");
    }
}


int pop(Stack* s){
    int value = -1;
    if(!(isEmpty(s))){
        int value = s->items[s->top];
        s->top--;
        return value;
    }
    else{
        printf("Stack is empty.\n");
        return value;
    }
}


int peek(Stack* s){
    if(!(isEmpty(s))){
        return s->items[s->top];
    }
    else{
        return -1;
    }    
}


int top(Stack* s){
    return s->top;
}


void display(Stack* s){
    if(!(isEmpty(s))){
        for(int i = s->top ; i > -1; i--){
            printf("%d \n", s->items[i]);
        }      
    }
    else{
        printf("Stack is empty.\n");
    }
}


int main(){
    Stack* S = initialize();
   
    int choice, value;
    do{
        printf("What would you like to do?\n");
        printf("1. Push an item\n2.Pop an item\n3.Peek the stack\n4.Top\n5.Display the stack\n6.Exit the program\n");
        scanf("%d", &choice);
       
        switch(choice){
            case 1:
                int item;
                printf("Value of item to be pushed: ");
                scanf("%d", &item);
                push(S, item);
                break;
            case 2:
                value = pop(S);
                if(!(value == -1)){
                    printf("The popped value is %d", value);
                }
                break;
            case 3:
                value = peek(S);
                if(!(value == -1)){
                    printf("The topmost item of the stack is %d", value);
                }                
                break;
            case 4:
                printf("The value of top is %d", top(S));
                break;
            case 5:
                display(S);
                break;
            case 6:
                printf("Exiting the program...");
                break;
        }
        printf("\n");
    }while(choice != 0);
    return 0;
}








