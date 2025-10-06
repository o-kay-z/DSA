#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}Node;




typedef struct{
    Node* head;
    int count;
}List;


List* initialize(){
    List* L = (List*) malloc(sizeof(List));
    if (L == NULL){
        return NULL;
    }
    L->head = NULL;
    L->count = 0;
    return L;
}


void empty(List *list){
    while(list->head != NULL){
        free(list->head->data);
        list->head = list->head->next;
    }
    list->count = 0;
}


void insertFirst (List *list, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error");
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}


void insertLast(List *list, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error");
    }
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
    }
    else{
        Node* current = list->head;
        while(current->next != NULL){
            current->next= newNode;
            current->data = current->next;
        };
    }
    list->count++;
}
//what am i cooking


void insertPos(List *list, int data, int index){
    if (index == 0){
        insertFirst(list, data);
    }
    else if (index == list->count){
        inserLast(list, data);
    }
    else if (index < list->count){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        Node* current = list->head;


        for(int i = 0; i < index - 1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    }
    else{
        printf("gtfo");
    }
}


void deleteStart(List *list){
    Node* current = list->head;
    list->head = current->next;
    free(current);
    list->count--;
}


void deleteLast(List *list){
    if(list->count == 1){
        free(list->head);
        list->head = NULL;
        list->count--;
    }
    else{
        Node* current = list->head;
    }
}


void deletePos (List *list, int index){


    if (index == 0){
        deleteStart(list);
    }
    else{
        Node* current = list->head;
        for(int i = 0; i < index - 1; i++){
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        list->count--;
    }
}


int retrieve(List *list, int index){
    if(index < list->count){
        Node* current = list->head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
        return current->data;
    }
}


int locate(List *list, int data){
    if(list->head == NULL){
        return -1;
    }
    else{
        Node* current = list->head;
        int index = 0;
        while(current != NULL){
            if(current->data == data){
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
}


void display(List *list){
    Node* current = list->head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}


int main(){
    List* L = initialize();
    L = {{3,{5,{7,{9,{11, NULL}}}}}, 5};


    insertFirst(L, 1);
    insertLast (L, 13);
    insertPos (L, 2, 1);
    display(L);
}






