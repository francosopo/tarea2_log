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
    //los nodos previos  
    NodoA2 nodo_null = {-1,-1};
    NodoA2 heap_q[cant_nodos];
    for(int i=0;i<cant_nodos;i++){
        //Asignamos la distancia como infinita
        heap_q[i].dist = INT_MAX; 
        distancias[i] = INT_MAX;
        //Asignar los previos como indefinidos   
        previos[i] = nodo_null; 
    }
    // el nodo raiz hay que pasarlo como parámetro
    distancias[raiz]=0;
    heap_q[]
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