#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int peso;
    Nodo *next;
}Nodo;

double *distanciasInt(int size){
    double *dis = calloc(size, sizeof(double));

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

void destruirDistanciasDouble(double *dis){
    free(dis);
}

int previos(){

}