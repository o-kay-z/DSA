#include<stdio.h>
#include<stdlib.h>
#define MAX 5


typedef struct {
    int elem[MAX];
    int count;
}List;


List initialize (List L){
        L.count = 0;
        return L;
}


List insertList (List L, int data, int position){
   
    if(position < L.count || position == L.count && L.count != MAX){
        for(int i = L.count; i != position; i--){
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[position] = data;
        L.count++;
    }
    else{
        if(position > L.count || position != L.count){
            printf("Position is not valid!\n");
        }
        else if(L.count == MAX){
            printf("Array is full!\n");
        }
    }
    return L;
}


List deletePos (List L, int position){
    if(position < L.count || position == L.count){
        for(int i = position; i < L.count; i++){
            L.elem[i] = L.elem[i+1];
        }
        L.count--;
    }
}


int locate (List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
    return -1;
}


List insertSorted(List L, int data){
    for (int i = 1 ; i < L.count; i++){
        int key = L.elem[i];
        int j = i - 1;
       
        while(j >= 0 && key < L.elem[j]){
            L.elem[j + 1] = L.elem[j];
            --j;
        }
        L.elem[j + 1] = key;
    }
    return L;
}


void displayList(List L){
    printf("Your array: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}


int main(){
    List L;
    int num, pos;
    int answer;
    printf("Variation 1\n");
    L = initialize(L);
    do{
        printf("What would you like to do?\n[1]Insert a number\n[2]Delete at position\n[3]Locate a number\n[4]Insert sorted\n[5]Display\n[6]Exit\nYour input: ");
        scanf("%d", &answer);
        printf("\n");
        switch(answer){
            case 1:
                printf("Number to insert: ");
                scanf("%d", &num);
                printf("Position to insert: ");
                scanf("%d", &pos);
                L = insertList(L, num, pos);
                displayList(L);
                printf("\n");
                break;
            case 2:
                printf("Position to delete: ");
                scanf("%d", &pos);
                L = deletePos(L, pos);
                displayList(L);
                printf("\n");
                break;
            case 3:
                printf("What number would you like to locate? ");
                scanf("%d", &num);
                pos = locate(L, num);
                if(pos != -1){
                    printf("Your number is located at position: %d\n", pos);
                }
                else{
                    printf("Your number is not in the list");
                }
                break;
            case 4:
                printf("Number to insert sorted: ");
                scanf("%d", &num);
                L = insertSorted(L, num);
                displayList(L);
                printf("\n");
                break;
            case 5:
                displayList(L);
                printf("\n");
                break;
            case 6:
                printf("Exiting...");
                break;
        }
       
    }while(answer != 6);
}
       
