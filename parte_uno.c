#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "utils.c"
#include "pss.h"

void test(int expected, int got, int ntest){
    
    if(expected != got){
        fprintf(stdout, "Test %i, Expected %i, got %i\n", ntest, expected, got);
    }else{
        fprintf(stdout, "Test %i pasado\n", ntest);
    }
}

// Extraemos el indice minimo 
int extractMinNode(int * arr_dist,int * arr_index,int len){
    int min = arr_dist[arr_index[len-1]];
    int j = -1;
    for(int k = 0;k<len ; k++){
        if(0<arr_dist[arr_index[k]] && arr_dist[arr_index[k]]<=min)
          j=arr_index[k];
    }
    return j;
}

void eliminar_de_arreglo(int *arr, int num, int len){
    for(int i =0; i< len; i++){
        if(arr[i]==num){
            arr[i]=arr[len-1];
            break;
        }
    }
}
void eliminar_de_arreglo_nodo(NodoA1 *arr, int num, int len){
    for(int i = 0; i < len; i++){
        if(i == len - 1){
            NodoA1 nodo_null = {-1,-1};
            arr[i] = nodo_null;
            break;
        }
        if(arr[i].valor == num){
            arr[i] = arr[len - 1];
            break;
        }
    }
}


void llenar_aux(NodoA1 *aux, int size){

}

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

//Asumimos que nodo tiene la cantidad de nodos(vértices)
void algoritmo1(NodoA1 *nodo, int raiz, int cant_nodos, int * distancias, NodoA1 * previos){
    //inicializamos dos arreglos, que contienen las distancias y 
    //los nodos previos(?
    int arreglo_indices[cant_nodos];
    NodoA1 aux[cant_nodos];  
    //int cantidadDentrodeAux= 0;
    NodoA1 nodo_null = {-1,-1};
    for(int i=0;i<cant_nodos;i++){
        //Asignamos la distancia como infinita
        distancias[i] = INT_MAX; 
        //Asignar los previos como indefinidos   
        previos[i] = nodo_null; 
        aux[i] = nodo[i];
        // rellenando aux
        //Asignamos el arreglo de indices
        arreglo_indices[i]=i;
    }
    // el nodo raiz hay que pasarlo como parámetro
    distancias[raiz]=0;
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

int main(int argc, char *argv[]){
    int *d = distanciasInt(5);
    NodoA1 *p = previos(5);
      
    //leer el archivo de input
    //FILE *in = fopen(argv[1], "r");
    int a[10]={5,8,2,9,5,8,3,1,8,9};
    int index[10]={0,1,2,3,4,5,6,7,8,9};
    test(7,extractMinNode(a,index,10),6);

    NodoA1  arr[5];
    crearGrafoDeJuguete(5,arr);

    test(0, arr[0].valor, 1);
    test(1, arr[1].valor, 2);
    test(2, arr[2].valor, 3);
    test(3, arr[3].valor, 4); 
    //test(5, arr[4].valor, 5);

    NodoA1 test_alg1[4];
    crearGrafoDeJuguete(4,test_alg1);
    int raiz = 0;
    int nNodos = 5;
    algoritmo1(test_alg1,raiz,nNodos,d,p);
    
    
    test(0,d[0], 7);
    test(4,d[1], 8);
    test(2,d[2], 9);
    test(3,d[3], 10);
    test(5,d[4], 11);

    destruirGrafoDeJuguete(arr, 5);
    destruirDistanciasInt(d);
    destruirPrevios(p);
}