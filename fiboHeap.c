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
    n ->listPosition=NULL;
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
    end->prev=NULL;
    end->valor=firstVal;
    return end;
}

void insert_on_EL(Node *newVal, enlacedListNode **list){
    enlacedListNode * newNode = malloc(sizeof(enlacedListNode));
    newNode->valor=newVal;
    newNode->next=*list;
    (*list)->prev=newNode;
    *list=newNode;
}

void destroy_enlaced_list(enlacedListNode *list){
    if(list == NULL){
        return ;
    }else{
        //enlacedListNode * next= list->next;
        //Node * valor = list->valor;
        destroyNode(list->valor);
        destroy_enlaced_list(list->next);
        free(list);
    }
    /*    if (next != NULL){
        destroy_enlaced_list(next);
    }*/
}

Fib_Heap *create_fibonacci_heap(Node *node){
    Fib_Heap *CF = (Fib_Heap*)malloc(sizeof(Fib_Heap));
    enlacedListNode * firstElement = create_enlaced_list(node);
    CF->forest=firstElement;
    CF->lastElement=firstElement;
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
    //añado los hijos del nodo eliminado a la lista enlazada
    while(c != NULL){
        Node *n = c ->valor;
        n->father = NULL;
        insert(CF,n->storagedNode,n->distancia);
        n->storagedNode=NULL;
        destroyNode(n);
        c = c->next;
    }
    enlacedListNode *toDelete = CF->min->listPosition;
    enlacedListNode *prev= toDelete->prev;
    enlacedListNode *next= toDelete->next;
    prev->next=next;
    next->prev=prev;
    toDelete->next=NULL;
    toDelete->prev=NULL;
    destroy_enlaced_list(toDelete);
    int k= (int)log2(CF->N);
    Node * A[k];
    for(int i =0; i<k; i++){
        A[i]=NULL;
    }
    enlacedListNode *forest= CF->forest;
    while(forest!=NULL){
        Node* n= forest->valor;
        int valor = n->nNodos;
        int k= ((int)floor(log2(valor))) +1;
        if(A[k]==NULL){
            A[k]=n;
        }
        else{
            if(A[k]->distancia > n->distancia){
                insert_on_EL(A[k],&(n->childs));
                n->nNodos=  n->nNodos+ A[k]->nNodos;
                A[k+1]=n;
                A[k]=NULL;
            }
            else{
                enlacedListNode * a = create_enlaced_list(A[k]);
                insert_on_EL(n,&a);
                A[k]->nNodos=  n->nNodos+ A[k]->nNodos;
                A[k+1]= A[k];
                A[k]=NULL;
            }
        }
        forest=forest->next;
    }

    int j=k;
    while(A[j]==NULL){
        j--;
    }
    enlacedListNode *newForest= create_enlaced_list(A[j]); 
    for(int i=j;i>=0;i--){
        if(A[i]!=NULL){
            insert_on_EL(A[i],&newForest);
        }
    }
    CF->forest=newForest;
    enlacedListNode * forestReference=CF->forest;
    CF->min= forestReference ->valor;
    forestReference=forestReference->next;
    //consigo un nuevo minimo
    while(forestReference!=NULL){
        if(CF->min->distancia > forestReference->valor->distancia)
        {
            CF->min=newForest->valor;
        }
    }
    return ret;
}

void merge(Fib_Heap *CF1, Fib_Heap *CF2){
    CF1->lastElement->next= CF2->forest;
    CF1->lastElement= CF2->lastElement;
    if(CF2->min->distancia < CF1 -> min -> distancia)
    {
        CF1->min = CF2->min;
    }
    CF2->min=NULL;
    CF2->lastElement=NULL;
    CF2->forest=NULL;
    destroyFH(CF2);
}

//busca un nodo entre todos los hijos de un arbol
Node *searchNode(Node *node, int llave){
    if(node->id==llave)
    {
        return node;
    }
    else
    {
        Node* result= NULL;
        if(node->childs!= NULL)
        {
            enlacedListNode *childs= node->childs;
            while(result==NULL && childs!=NULL){
                result=searchNode(childs->valor,llave);
                childs = childs->next;
            }
        }
        return result;
    }
}

//Para este caso en especifico el DecreaseKey es buscar un nodo entre los n disponibles, por lo que encontrarlo
//es orden N, numero de nodos, dado que la heap se ordena por distancia pero el cambio se hace en base a la id 
//las cuales no se ordenan en un orden especifico.
void DecreaseKey(Fib_Heap *CF, int llave, int nueva_dist)
{
    Node * toModify= NULL;
    enlacedListNode *forest= CF->forest;
    while (toModify==NULL && forest!=NULL)
    {
        toModify = searchNode(forest->valor,llave);
    }
    if(toModify == NULL){
        return ;
    }
    else{
        toModify->distancia=nueva_dist;
        while((toModify->distancia < toModify->father->distancia) && toModify->father!=NULL){
            Node* exfather= toModify->father;
            int distancia= exfather->distancia;
            int id = exfather -> id;
            nodoA3 * storage= exfather->storagedNode;
            exfather->id=toModify->id;
            exfather->distancia=toModify->distancia;
            exfather->storagedNode= toModify->storagedNode;
            toModify->storagedNode= storage;
            toModify->id=id;
            toModify->distancia=distancia;
            toModify= toModify->father;
        }
    }
    if(CF->min->distancia > toModify->distancia){
        CF->min=toModify;
    }
}

void destroyFH(Fib_Heap *CF)
{
    destroy_enlaced_list(CF->forest);
    //destroy_enlaced_list(CF->lastElement);
    //destroyNode(CF->min);
    free(CF);
}

