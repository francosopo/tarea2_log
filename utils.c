#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "utils.h"

int *distanciasInt(int size){
    int *dis = calloc(size, sizeof(int));

    //debuggeando el error de calloc
    if (dis == NULL){
        perror("distanciasInt");
        exit(-1);
    }
    // inicializando las distancias con ceros
    for(int i = 0; i < size; i++){
        dis[i] = 0;
    }
    return dis;
}

void destruirDistanciasInt(int *dis){
    free(dis);
}

NodoA1 *previos(int size){
    NodoA1 *prev = calloc(size, sizeof(NodoA1));

    if (prev == NULL){
        perror("previos calloc");
    }
    return prev;
}

NodoA2 *previos_heap(int size){
  NodoA2 *prev = calloc(size,sizeof(NodoA2));
  if (prev == NULL){
      perror("previos calloc");
  }
  return prev;
}


void destruirPrevios(NodoA1 *prev){
    free(prev);
}

void destruirPrevios_heap(NodoA2 *prev){
  free(prev);
}

void crearGrafoDeJuguete(int size, NodoA1 *arr){
    int a=0, b=1, c=2, d=3,e=4;
    int **vecinos_a = calloc(size, sizeof(int*));

    if(vecinos_a == NULL){
        perror("vecinos_a");
    }

    for(int i = 0; i< size; i++){
        vecinos_a[i] = calloc(2, sizeof(int));
        if(vecinos_a[i] == NULL){
            fprintf(stderr,"vecinos_a[%i]", i);
        }
    }

    vecinos_a[0][0] = 1;
    vecinos_a[0][1] = 8;
    vecinos_a[1][0] = 2;
    vecinos_a[1][1] = 2;
    vecinos_a[2][0] = 3;
    vecinos_a[2][1] = 3;
    vecinos_a[3][0] = 4;
    vecinos_a[3][1] = 7;

    arr[0].valor = a;
    arr[0].vecinos = vecinos_a;
    arr[0].nVecinos = 4;



    int **vecinos_b = calloc(size, sizeof(int*));

    if(vecinos_b == NULL){
        perror("vecinos_b");
    }
    for(int i = 0; i< size; i++){
        vecinos_b[i] = calloc(2, sizeof(int));
        if(vecinos_b[i] == NULL){
            fprintf(stderr,"vecinos_b[%i]", i);
        }
    } 

    
    vecinos_b[0][0] = 0;
    vecinos_b[0][1] = 7;
    vecinos_b[1][0] = 2;
    vecinos_b[1][1] = 1;
    vecinos_b[2][0] = 3;
    vecinos_b[2][1] = 5;
    vecinos_b[3][0] = 4;
    vecinos_b[3][1] = 3;

    arr[1].valor = b;
    arr[1].vecinos = vecinos_b;
    arr[1].nVecinos = 4;
    

    int **vecinos_c = calloc(size, sizeof(int*));
    if(vecinos_c == NULL){
        perror("vecinos_c");
    }
    for(int i = 0; i< size; i++){
        vecinos_c[i] = calloc(2, sizeof(int));
        if(vecinos_c[i] == NULL){
            fprintf(stderr,"vecinos_c[%i]", i);
        }
    }    

    
    vecinos_c[0][0] = 0;
    vecinos_c[0][1] = 3;
    vecinos_c[1][0] = 1;
    vecinos_c[1][1] = 2;
    vecinos_c[2][0] = 3;
    vecinos_c[2][1] = 7;
    vecinos_c[3][0] = 4;
    vecinos_c[3][1] = 8;

    arr[2].valor = c;
    arr[2].vecinos = vecinos_c;
    arr[2].nVecinos = 4;
    

    int **vecinos_d = calloc(size, sizeof(int*));
    if(vecinos_d == NULL){
        perror("vecinos_d");
    }
    for(int i = 0; i< size; i++){
        vecinos_d[i] = calloc(2, sizeof(int));
        if(vecinos_d[i] == NULL){
            fprintf(stderr,"vecinos_d[%i]", i);
        }
    } 

    
    vecinos_d[0][0] = 0;
    vecinos_d[0][1] = 1;
    vecinos_d[1][0] = 1;
    vecinos_d[1][1] = 7;
    vecinos_d[2][0] = 2;
    vecinos_d[2][1] = 5;
    vecinos_d[3][0] = 4;
    vecinos_d[3][1] = 2; 
    
    arr[3].valor = d;
    arr[3].vecinos = vecinos_d;
    arr[3].nVecinos = 4;    
    
    int **vecinos_e = calloc(size, sizeof(int*));

    if(vecinos_e == NULL){
        perror("vecinos_e");
    }
    for(int i = 0; i< size; i++){
        vecinos_e[i] = calloc(2, sizeof(int));
        if(vecinos_e[i] == NULL){
            fprintf(stderr,"vecinos_e[%i]", i);
        }
    } 
    vecinos_e[0][0] = 0;
    vecinos_e[0][1] = 7;
    vecinos_e[1][0] = 1;
    vecinos_e[1][1] = 8;
    vecinos_e[2][0] = 2;
    vecinos_e[2][1] = 2;
    vecinos_e[3][0] = 3;
    vecinos_e[3][1] = 3;

    arr[4].valor = e;
    arr[4].vecinos = vecinos_e;
    arr[4].nVecinos = 4;
}

void destruirGrafoDeJuguete(NodoA1 *arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            free((arr[i].vecinos)[j]);
        }
        free(arr[i].vecinos);
    }
}


void crearGrafoDeJugueteHeap(int size, NodoA2 *arr){
    int a=0, b=1, c=2, d=3,e=4;
    int **vecinos_a = calloc(size, sizeof(int*));

    if(vecinos_a == NULL){
        perror("vecinos_a");
    }

    for(int i = 0; i< size; i++){
        vecinos_a[i] = calloc(2, sizeof(int));
        if(vecinos_a[i] == NULL){
            fprintf(stderr,"vecinos_a[%i]", i);
        }
    }

    vecinos_a[0][0] = 1;
    vecinos_a[0][1] = 8;
    vecinos_a[1][0] = 2;
    vecinos_a[1][1] = 2;
    vecinos_a[2][0] = 3;
    vecinos_a[2][1] = 3;
    vecinos_a[3][0] = 4;
    vecinos_a[3][1] = 7;

    arr[0].valor = a;
    arr[0].vecinos = vecinos_a;
    arr[0].nVecinos = 4;



    int **vecinos_b = calloc(size, sizeof(int*));

    if(vecinos_b == NULL){
        perror("vecinos_b");
    }
    for(int i = 0; i< size; i++){
        vecinos_b[i] = calloc(2, sizeof(int));
        if(vecinos_b[i] == NULL){
            fprintf(stderr,"vecinos_b[%i]", i);
        }
    } 

    
    vecinos_b[0][0] = 0;
    vecinos_b[0][1] = 7;
    vecinos_b[1][0] = 2;
    vecinos_b[1][1] = 1;
    vecinos_b[2][0] = 3;
    vecinos_b[2][1] = 5;
    vecinos_b[3][0] = 4;
    vecinos_b[3][1] = 3;

    arr[1].valor = b;
    arr[1].vecinos = vecinos_b;
    arr[1].nVecinos = 4;
    

    int **vecinos_c = calloc(size, sizeof(int*));
    if(vecinos_c == NULL){
        perror("vecinos_c");
    }
    for(int i = 0; i< size; i++){
        vecinos_c[i] = calloc(2, sizeof(int));
        if(vecinos_c[i] == NULL){
            fprintf(stderr,"vecinos_c[%i]", i);
        }
    }    

    
    vecinos_c[0][0] = 0;
    vecinos_c[0][1] = 3;
    vecinos_c[1][0] = 1;
    vecinos_c[1][1] = 2;
    vecinos_c[2][0] = 3;
    vecinos_c[2][1] = 7;
    vecinos_c[3][0] = 4;
    vecinos_c[3][1] = 8;

    arr[2].valor = c;
    arr[2].vecinos = vecinos_c;
    arr[2].nVecinos = 4;
    

    int **vecinos_d = calloc(size, sizeof(int*));
    if(vecinos_d == NULL){
        perror("vecinos_d");
    }
    for(int i = 0; i< size; i++){
        vecinos_d[i] = calloc(2, sizeof(int));
        if(vecinos_d[i] == NULL){
            fprintf(stderr,"vecinos_d[%i]", i);
        }
    } 

    
    vecinos_d[0][0] = 0;
    vecinos_d[0][1] = 1;
    vecinos_d[1][0] = 1;
    vecinos_d[1][1] = 7;
    vecinos_d[2][0] = 2;
    vecinos_d[2][1] = 5;
    vecinos_d[3][0] = 4;
    vecinos_d[3][1] = 2; 
    
    arr[3].valor = d;
    arr[3].vecinos = vecinos_d;
    arr[3].nVecinos = 4;    
    
    int **vecinos_e = calloc(size, sizeof(int*));

    if(vecinos_e == NULL){
        perror("vecinos_e");
    }
    for(int i = 0; i< size; i++){
        vecinos_e[i] = calloc(2, sizeof(int));
        if(vecinos_e[i] == NULL){
            fprintf(stderr,"vecinos_e[%i]", i);
        }
    } 
    vecinos_e[0][0] = 0;
    vecinos_e[0][1] = 7;
    vecinos_e[1][0] = 1;
    vecinos_e[1][1] = 8;
    vecinos_e[2][0] = 2;
    vecinos_e[2][1] = 2;
    vecinos_e[3][0] = 3;
    vecinos_e[3][1] = 3;

    arr[4].valor = e;
    arr[4].vecinos = vecinos_e;
    arr[4].nVecinos = 4;
}

void destruirGrafoDeJugueteHeap(NodoA2 *arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            free((arr[i].vecinos)[j]);
        }
        free(arr[i].vecinos);
    }
}

nodoA3 *newNodoA3(int valor, int nVecinos, int **vecinos){
    nodoA3 *n = malloc(sizeof(nodoA3));
    n->valor = valor;
    n -> nVecinos = nVecinos;
    n -> vecinos = vecinos;
    return n;
}

void destroyNodeA3(nodoA3 *nodo){
    free(nodo);
}