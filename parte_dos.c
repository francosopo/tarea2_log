#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include "heap.c"
#include "pss.h"

//actualiza la distancia desde un nodo (acumulada) hacia todos sus vecinos
void actualizarDistancias(ColaHeap* q_heap, int * distancias,NodoA2* minimo){ 
    for(int i = 0; i < minimo->nVecinos; i++ ){
        int dis_tabla = distancias[minimo->vecinos[i][0]];
        int dis_v_mas_u = distancias[minimo->valor] + minimo->vecinos[i][1];
        if( dis_tabla > dis_v_mas_u){
            distancias[minimo->vecinos[i][0]] = dis_v_mas_u;
            find_node_heap(q_heap,minimo->vecinos[i][0]+1,dis_v_mas_u);
        }
    }
}

//Asumimos que nodo tiene la cantidad de nodos(vértices)
void algoritmo2(NodoA2 *nodo, int raiz, int cant_nodos, int * distancias, NodoA2 * previos){
    //inicializamos dos arreglos, que contienen las distancias y 
    //los nodos previos, y además la cola de heap  
    NodoA2 nodo_null = {-1,-1,-1,NULL};
    NodoA2 nodo_arr[cant_nodos];
    ColaHeap heap_q = {INT_MAX, 0, nodo_arr};

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
    //actualizarDistancias(nodo, raiz, distancias, previos);
    //int min = distancias[0];
    while(heap_q.n>0){
        NodoA2 nodo_minimo = extract_min_heap(&heap_q);
        previos[nodo_minimo.valor]=nodo_minimo;
        actualizarDistancias(&heap_q, distancias,&nodo_minimo);
    }
}
//-------------------------------------------------
//       Cosas relacionadas con el test
//-------------------------------------------------
void test(int expected, int got, int ntest){
    
    if(expected != got){
        fprintf(stdout, "Test %i, Expected %i, got %i\n", ntest, expected, got);
    }else{
        fprintf(stdout, "Test %i pasado\n", ntest);
    }
}
int my_rand(){
    return rand();
}

double my_rand_frac(){
    return (double)rand() / (double) RAND_MAX;
}

void crearGrafo(int cant_nodos, int cant_aristas, NodoA2 *arr){
    srand(time(NULL));

    int cant_aristas_por_vecino = cant_aristas/cant_nodos;

    for (int i = 0; i < cant_nodos; i++){       
        //alocando espacio para los vecinos del nodo i
        int **vecinos = calloc(cant_aristas_por_vecino, sizeof(int*));
        if (vecinos == NULL) perror("vecinos");

        // alocando espacio para las aristas
        for (int j = 0; j < cant_aristas_por_vecino; j++){
            vecinos[j] = calloc(2, sizeof(int));
            if (vecinos[j] == NULL) fprintf(stderr, "vecinos %i", j);
        }

        for (int k = 0; k < cant_aristas_por_vecino; k++){
            for(int l = 0; l < 2; l++){
                vecinos[k][l] = (int) my_rand_frac() * cant_nodos;
            }
        }
        arr[i].valor = i;
        arr[i].vecinos = vecinos;
        arr[i].nVecinos = cant_aristas_por_vecino;
    }

}

double tiempo_algoritmo(NodoA2 *lista_adyacencia, int raiz, int cant_nodos, int *distancias, NodoA2 *previos){
    clock_t begin = clock();
        algoritmo2(lista_adyacencia, raiz, cant_nodos, distancias, previos);
    clock_t end = clock();
    return (double) (end - begin) / CLOCKS_PER_SEC;
}

double promedio(double *stats, int cant_stats){
    double sum = 0;
    for(int i = 1; i < cant_stats; i++){
        sum = sum + stats[i];
    }
    return sum / (double)cant_stats;
}



//cant_aristas, tiempo_segundos
void escribir(double *para_escribir, FILE *out){
    fprintf(out, "%0.2f, %0.9f\n", para_escribir[0], para_escribir[1]);
}

void eliminarGrafoHeap(NodoA2 *lista, int cant_nodos){
    for (int i = 0; i < cant_nodos; i++){
        for(int j = 0; j < lista[i].nVecinos; j++){
            free(lista[i].vecinos[j]);
        }
        free(lista[i].vecinos);
    }
}
// el tiempo está en segundos
void prueba_de_esfuerzo(void){
    int cant_nodos = (int) pow(2,14);
    char filename[100];
    snprintf(filename, 100, "alg2_aristas__tiempo_segundos_v2.csv");

    FILE *out = fopen(filename, "w");
    fprintf(out,"naristas,tiempo_s\n");
    for(int  j = 16; j <= 24; j++){
        int cant_aristas = (int) pow(2,j);
        int cant_stats = 50;
        double *stats = calloc(cant_stats, sizeof(double));
        if(stats == NULL){
            perror("stats: calloc");
            fclose(out);
            exit(-1);
        }
        
        for (int i = 0; i < cant_stats; i++){
            NodoA2 *lista_adyacencia = calloc(cant_nodos, sizeof(NodoA2));
            if(lista_adyacencia == NULL){
                perror("lista_adyacencia");
                fclose(out);
                free(stats);
                exit(-1);
            }
            NodoA2 *previos_arr = previos_heap(cant_nodos);
            int *distancias = distanciasInt(cant_nodos);
            crearGrafo(cant_nodos, cant_aristas, lista_adyacencia);

            int raiz = (int) my_rand_frac() * cant_nodos;

            double delta_t = tiempo_algoritmo(lista_adyacencia,raiz, cant_nodos, distancias, previos_arr);

            stats[i] = delta_t;
            eliminarGrafoHeap(lista_adyacencia,cant_nodos);
            destruirPrevios_heap(previos_arr);
            destruirDistanciasInt(distancias);        
            free(lista_adyacencia);
        }
        double para_escribir[2];
        para_escribir[0] = (double) cant_aristas;
        para_escribir[1] = promedio(stats, cant_stats);
        escribir(para_escribir, out);
        printf("j: %i,%0.9f\n", j, para_escribir[1]);
        free(stats);
    }
    fclose(out);
}


int main(int argc, char *argv[]){
    int *d = distanciasInt(5);
    NodoA2 *p = previos_heap(5);
      
    NodoA2  arr[5];
    crearGrafoDeJugueteHeap(5,arr);

    test(0, arr[0].valor, 1);
    test(1, arr[1].valor, 2);
    test(2, arr[2].valor, 3);
    test(3, arr[3].valor, 4); 
    test(4, arr[4].valor, 5);
    destruirGrafoDeJugueteHeap(arr, 5);

    NodoA2 test_alg1[5];
    crearGrafoDeJugueteHeap(5, test_alg1);
    int raiz = 0;
    int nNodos = 5;
    algoritmo2(test_alg1,raiz,nNodos,d,p);
    test(0,d[0], 6);
    test(4,d[1], 7);
    test(2,d[2], 8);
    test(3,d[3], 9);
    test(5,d[4], 10);

    destruirGrafoDeJugueteHeap(test_alg1,5);

    destruirDistanciasInt(d);
    destruirPrevios_heap(p);

    prueba_de_esfuerzo();
}

