#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "utils.c"


void test(int expected, int got, int ntest){
    
    if(expected != got){
        fprintf(stdout, "Expected %i, got %i\n", expected, got);
    }else{
        fprintf(stdout, "Test numero %i pasado\n", ntest);
    }
}
// Extraemos el minimo 
int extractMin(int * arr,int len){
    int min = arr[0];
    int j;
    for(int k = 0;k<len;k++){
        if(arr[k]<=min)
          j=k;
    }
    return j;
}
//Asumimos que nodo tiene la cantidad de nodos(vértices)
void algoritmo1(NodoA1 *nodo, int cant_nodos){
    //inicializamos dos arreglos, que contienen las distancias y 
    //los nodos previos(?)
    int distancias[cant_nodos];
    int * previos[cant_nodos];

    NodoA1 aux[cant_nodos];  
    
    for(int i=0;i<cant_nodos;i++){
        //Asignamos la distancia como infinita
        distancias[i] = INT_MAX; 
        //Asignar los previos como indefinidos   
        previos[i] = NULL; 
        aux[i] = nodo[i];
    }
    //Asumimos que aquí está almacenado el nodo    
    distancias[0]=0;
    //Volver a asignar las distancias de los vecinos
    for(int i = 0;i<sizeof(nodo->vecinos)/sizeof(nodo->vecinos[1]);i++){  
      distancias[(nodo->vecinos)[i][0]] = nodo->vecinos[i][1];
    }  
    int contador = cant_nodos;
    int min = distancias[0];
    while(contador>0){
        NodoA1 * temp_nod;
        
        contador--;
    }    
}

int main(int argc, char *argv[]){
    int *d = distanciasInt(30);
    int *p = previos(30);
      
    //leer el archivo de input
    //FILE *in = fopen(argv[1], "r");
    int a[10]={1,2,3,4,5,6,7,8,4,10};
    test(0,extractMin(a,10),6);


    NodoA1  arr[5];
    crearGrafoDeJuguete(5,arr);
    test(1, arr[0].valor, 1);
    test(2, arr[1].valor, 2);
    test(3, arr[2].valor, 3);
    test(4, arr[3].valor, 4); 
    test(5, arr[4].valor, 5);

    destruirGrafoDeJuguete(arr, 5);
    destruirDistanciasInt(d);
    destruirPrevios(p);
}