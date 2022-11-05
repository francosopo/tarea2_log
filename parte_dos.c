#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <math.h>

#include "utils.c"
#include "pss.h"

//actualiza la distancia desde un nodo (acumulada) hacia todos sus vecinos
void actualizarDistancias(NodoA1 *nodos,int nodo, int *distancias, NodoA1 *prev){ 
    for(int i = 0; i < nodos[nodo].nVecinos; i++ ){
        int dis_tabla = distancias[nodos[nodo].vecinos[i][0]];
        int dis_v_mas_u = distancias[nodos[nodo].valor] + nodos[nodo].vecinos[i][1];
        if( dis_tabla > dis_v_mas_u){
            distancias[nodos[nodo].vecinos[i][0]] = dis_v_mas_u;
            prev[nodos[nodo].vecinos[i][0]] = nodos[nodo];
        }
    }
}
/*
Inicializamos los arreglos de distancias y nodos previos. Anadimos un nodo
en la cola de prioridad para cada vertice utilizando Heapify, considerando
la distancia de ese vertice a la raız para ordenarlos.

*/

//Asumimos que nodo tiene la cantidad de nodos(vértices)
void algoritmo2(NodoA2 *nodo, int raiz, int cant_nodos, int * distancias, NodoA2 * previos){
    //inicializamos dos arreglos, que contienen las distancias y 
    //los nodos previos, y además la cola de heap  
    NodoA2 nodo_null = {-1,-1};
    NodoA2 nodo_arr[cant_nodos];
    ColaHeap heap_q = {__INT_MAX__,0,nodo_arr};
    nodo[raiz].dist = 0;
    for(int i=0;i<cant_nodos;i++){
        distancias[i] = INT_MAX;
        //Asignar los previos como indefinidos   
        previos[i] = nodo_null;
        //Asignamos la distancia como infinita en la cola de heap
        if(i==raiz){
          nodo[i].dist=0;
          distancias[i]=0;
        }  
        else{  
          nodo[i].dist = INT_MAX;
        }
        insert(&heap_q,&nodo[i]);   
    }
    
    //Volver a asignar las distancias de los vecinos
    actualizarDistancias(nodo, raiz, distancias, previos);
    int contador = cant_nodos;
    //int min = distancias[0];
    while(contador>0){
        int distancia_minima = extractMinNode(distancias,arreglo_indices,contador);
        eliminar_de_arreglo(arreglo_indices,distancia_minima,contador);
        eliminar_de_arreglo_nodo(aux, distancia_minima, contador);
        actualizarDistancias(nodo, nodo[distancia_minima].valor,distancias, previos);
        contador--;
    }
}