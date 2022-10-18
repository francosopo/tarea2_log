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

void destruirDistanciasint(int *dis){
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

