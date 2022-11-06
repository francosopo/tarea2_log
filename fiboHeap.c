#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fiboHeap.h"

Node *newNode(int distancia, int id, nodoA3 *nodo){
    Node *n = malloc(sizeof(Node));
    n -> distancia = distancia;
    n -> id = id;
    n -> storagedNode = nodo;
    n -> nNodos = 0;
    n -> childs = NULL;
    n -> father = NULL;
    return n;
}

void destroyNode(Node *n){
    destroy_enlaced_list(n->childs);
    //destroyNodeA3(n-> storagedNode);
    free(n);
}

enlacedListNode * create_enlaced_list(Node *firstVal){
    enlacedListNode * end = malloc(sizeof(enlacedListNode));
    end->next=NULL;
    end->valor=firstVal;
    return end;
}

void insert_on_EL(Node *newVal, enlacedListNode **list){
    enlacedListNode * newNode = malloc(sizeof(enlacedListNode));
    newNode->valor=newVal;
    newNode->next=*list;
    *list=newNode;
}

void destroy_enlaced_list(enlacedListNode *list){
    if(list == NULL){
        return ;
    }else{
        enlacedListNode * next= list->next;
        free(list);
        destroy_enlaced_list(next);
    }
    /*    if (next != NULL){
        destroy_enlaced_list(next);
    }*/
}

Fib_Heap *create_fibonacci_heap(Node *node){
    Fib_Heap *CF = (Fib_Heap*)malloc(sizeof(Fib_Heap));
    CF->forest=create_enlaced_list(node);
    CF->min = CF->forest->valor;
    return CF;
}
void insert(Fib_Heap *CF, nodoA3 *nuevo, int dist)
{
    Node *n = newNode(dist, nuevo->valor,nuevo);
    insert_on_EL(n,&(CF->forest));
    if(CF->min->distancia > n ->distancia){
        CF->min = n;
    }
}
nodoA3 *get(Fib_Heap *CF)
{
    nodoA3 *ret = CF->min->storagedNode;
    enlacedListNode *c = CF->min->childs;
    while(c != NULL){
        Node *n = c ->valor;
        n->father = NULL;
        insert(CF,n->storagedNode,n->distancia);
        destroyNode(n);
        c = c->next;
    }
    merge(CF);
    return ret;
}

void merge(Fib_Heap *CF){
    enlacedListNode *list = CF->forest;

}
void DecreaseKey(Fib_Heap *CF, int llave, int nueva_dist)
{

}
void destroyFH(Fib_Heap *CF)
{
    destroy_enlaced_list(CF->forest);
    destroyNode(CF->min);
    free(CF);
}

