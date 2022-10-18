#include <stdio.h>
#include <stdlib.h>

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

int *previos(int size){
    int *prev = calloc(size, sizeof(int));

    if (prev == NULL){
        perror("previos calloc");
    }

    return prev;
}



void destruirPrevios(int *prev){
    free(prev);
}

void crearGrafoDeJuguete(int size, NodoA1 *arr){
    int a=1, b=2, c=3, d=4,e=5;
    int **vecinos_a = calloc(5, sizeof(int*));
    for(int i = 0; i< 2; i++){
        vecinos_a[i] = calloc(2, sizeof(int));
    }
    vecinos_a[0][0] = 4;
    vecinos_a[0][1] = 3;
    vecinos_a[1][0] = 2;
    vecinos_a[1][1] = 8;
    vecinos_a[2][0] = 3;
    vecinos_a[2][1] = 2;
    vecinos_a[3][0] = 5;
    vecinos_a[3][1] = 7;
    vecinos_a[4][0] = 1;
    vecinos_a[4][1] = 9;

    arr[0].valor = a;
    arr[0].vecinos = vecinos_a;

    int **vecinos_b = calloc(5, sizeof(int*));
    for(int i = 0; i< 2; i++){
        vecinos_b[i] = calloc(2, sizeof(int));
    } 
    vecinos_b[0][0] = 4;
    vecinos_b[0][1] = 5;
    vecinos_b[1][0] = 5;
    vecinos_b[1][1] = 3;
    vecinos_b[2][0] = 3;
    vecinos_b[2][1] = 1;
    vecinos_b[3][0] = 2;
    vecinos_b[3][1] = 7;
    vecinos_b[4][0] = 1;
    vecinos_b[4][1] = 9;

    arr[1].valor = b;
    arr[1].vecinos = vecinos_b;

    int **vecinos_c = calloc(5, sizeof(int*));
    for(int i = 0; i< 2; i++){
        vecinos_c[i] = calloc(2, sizeof(int));
    }    
    vecinos_c[0][0] = 1;
    vecinos_c[0][1] = 3;
    vecinos_c[1][0] = 5;
    vecinos_c[1][1] = 8;
    vecinos_c[2][0] = 3;
    vecinos_c[2][1] = 2;
    vecinos_c[3][0] = 4;
    vecinos_c[3][1] = 7;
    vecinos_c[4][0] = 2;
    vecinos_c[4][1] = 9;

    arr[2].valor = c;
    arr[2].vecinos = vecinos_c;

    int **vecinos_d = calloc(5, sizeof(int*));
    for(int i = 0; i< 2; i++){
        vecinos_d[i] = calloc(2, sizeof(int));
    } 
    vecinos_d[0][0] = 3;
    vecinos_d[0][1] = 5;
    vecinos_d[1][0] = 2;
    vecinos_d[1][1] = 7;
    vecinos_d[2][0] = 4;
    vecinos_d[2][1] = 2;
    vecinos_d[3][0] = 1;
    vecinos_d[3][1] = 1;
    vecinos_d[4][0] = 5;
    vecinos_d[4][1] = 8; 
    
    arr[3].valor = d;
    arr[3].vecinos = vecinos_d;
    
    int **vecinos_e = calloc(5, sizeof(int*));
    for(int i = 0; i< 2; i++){
        vecinos_e[i] = calloc(2, sizeof(int));
    } 
     
    vecinos_e[0][0] = 4;
    vecinos_e[0][1] = 3;
    vecinos_e[1][0] = 2;
    vecinos_e[1][1] = 8;
    vecinos_e[2][0] = 3;
    vecinos_e[2][1] = 2;
    vecinos_e[3][0] = 5;
    vecinos_e[3][1] = 7;
    vecinos_e[4][0] = 1;
    vecinos_e[4][1] = 9;
    arr[4].valor = e;
    arr[4].vecinos = vecinos_e;
}