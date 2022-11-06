#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fiboHeap.h"


enlacedListNode * create_enlaced_list(Node *firstVal){
    enlacedListNode * end = malloc(sizeof(enlacedListNode));
    end->next=NULL;
    end->valor=firstVal;
    return end;
}

void insert_on_EL(Nodo *newVal, enlacedListNode *list){
    enlacedListNode * newNode = malloc(sizeof(enlacedListNode));
    newNode->valor=newVal;
    newNode->next=list;
    list=newNode;
}

void destroy_enlaced_list(enlacedListNode *list){
    enlacedListNode * next= list->next;
    free(list);
    if (next != NULL){
        destroy_enlaced_list(next);
    }
}

Fib_Heap create_fibonacci_heap(){
    Fib_Heap *CF = (Fib_Heap*)malloc(sizeof(Fib_Heap));
    CF->forest=create_enlaced_list(NULL)


}
