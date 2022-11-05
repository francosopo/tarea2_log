#include <stdlib.h>
#include <stdio.h>
#include "utils.c"
//Funcion para insertar un nodo a una cola de prioridad

void decrease_key_heap(ColaHeap *heap, int index,int decrease);
void swap(NodoA2 **a, NodoA2 **b, ColaHeap *heap);


void insert(ColaHeap *a, NodoA2* nodo){
    a->n  = (a->n) + 1;
    a->arr[a->n] = *nodo;
    for(int j=a->n; j>1 && ((a->arr[j]).dist)<(a->arr[j/2]).dist; j= j/2){ // intercambiamos con el padre
        NodoA2 t = (a->arr)[j];
        (a->arr)[j] = (a->arr)[j/2];
        (a->arr)[j/2] = t;
      }
}

NodoA2 extract_min_heap(ColaHeap *a){
    NodoA2 m = (a->arr)[1]; // # La variable m lleva el m�ximo
    (a->arr)[1] = (a->arr)[(a->n)--]; // # Movemos el �ltimo a la ra�z y achicamos el heap
    int j=1;
    while(2*j<=(a->n)){ //# mientras tenga alg�n hijo
        int k=2*j; //# el hijo izquierdo
        if(k+1<=(a->n) && (a->arr)[k+1].dist < (a->arr)[k].dist)
            k=k+1;  //# el hijo derecho es el mayor
        if((a->arr)[j].dist< (a->arr)[k].dist)
            break;  //# es mayor que ambos hijos1
        NodoA2 t = (a->arr)[j];  
        (a->arr)[j] = (a->arr)[k];
        (a->arr)[k] = t;  
        j=k;   //# lo intercambiamos con el mayor hijo
    }
    return m;
}

void decrease_key_heap(ColaHeap *heap, int index,int decrease){
  int j = index;
  (heap->arr[j]).dist = decrease;
  while(j/2>0){
    int papa = j/2;
    if((heap->arr)[papa].dist > (heap->arr[j]).dist){
      NodoA2 * temp = &(heap->arr[papa]);
      heap->arr[papa] = heap->arr[j];
      heap->arr[j] = *temp;
    }  
    //swap(&(&(heap->arr[papa])), &(&(heap->arr[j])), heap);
    if((heap->arr)[papa].dist < (heap->arr[j]).dist || j==0)
      break;  
    j=papa;
  }
}

void find_node_heap(ColaHeap *heap, int id, int decrease){
  for(int i = 0; i < heap -> n; i++){
    if(heap -> arr[i].valor == id){
      decrease_key_heap(heap, i, decrease); 
    }
  }
}


//épicoooooooooooooooooooooooooooooooo
/*int main(){
    NodoA2 nodo_arr[10];
    ColaHeap q_heap = {__INT_MAX__,0,nodo_arr};
    for(int i = 1; i< 9; i++){
        NodoA2 *nodo = malloc(sizeof(NodoA2));
        nodo->dist = 2*i;
        nodo->nVecinos = 0;
        nodo->valor= i;
        nodo->vecinos = NULL;
        insert(&q_heap, nodo);
    }
    //for(int i = 1; i< 9; i++){
    //    printf("%i\n",extract_min_heap(&q_heap).dist);  
    //}
    find_node_heap(&q_heap,7,1);
    NodoA2 nodo_heap = extract_min_heap(&q_heap);
    printf("dist:%i, id:%i\n",nodo_heap.dist,nodo_heap.valor);
    
}
*/

