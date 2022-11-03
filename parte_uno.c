#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <math.h>

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
    int min = arr_dist[arr_index[0]];
    int j = -1;
    for(int k = 0;k<len ; k++){
        if(0<=arr_dist[arr_index[k]] && arr_dist[arr_index[k]]<=min)
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

int my_rand(){
    return rand();
}

double my_rand_frac(){
    return (double)rand() / (double) RAND_MAX;
}

double tiempo_algoritmo(NodoA1 *lista_adyacencia, int raiz, int cant_nodos, int *distancias, NodoA1 *previos){
    clock_t begin = clock();
        algoritmo1(lista_adyacencia, raiz, cant_nodos, distancias, previos);
    clock_t end = clock();
    return (double) (end - begin) / CLOCKS_PER_SEC;
}

void crearGrafo(int cant_nodos, int cant_aristas, NodoA1 *arr){
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

void eliminarGrafo(NodoA1 *lista, int cant_nodos){
    for (int i = 0; i < cant_nodos; i++){
        for(int j = 0; j < lista[i].nVecinos; j++){
            free(lista[i].vecinos[j]);
        }
        free(lista[i].vecinos);
    }
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
    fprintf(out, "%0.9f, %0.9f\n", para_escribir[0], para_escribir[1]);
}


// el tiempo está en segundos
void prueba_de_esfuerzo(void){
    int cant_nodos = (int) pow(2,14);
    char filename[100];
    snprintf(filename, 100, "alg1_aristas__tiempo_segundos_v2.csv");
    FILE *out = fopen(filename, "w");
    
    for(int  j = 16; j <= 24; j++){
        int cant_aristas = (int) pow(2,j);
        int cant_stats = 50;
        double stats[cant_stats];
        
        for (int i = 0; i < cant_stats; i++){
            NodoA1 lista_adyacencia[cant_nodos];
            NodoA1 *previos_arr = previos(cant_nodos);
            int *distancias = distanciasInt(cant_nodos);
            crearGrafo(cant_nodos, cant_aristas, lista_adyacencia);

            int raiz = (int) my_rand_frac() * cant_nodos;

            double delta_t = tiempo_algoritmo(lista_adyacencia,raiz, cant_nodos, distancias, previos_arr);

            stats[i] = delta_t;
            eliminarGrafo(lista_adyacencia,cant_nodos);
            destruirPrevios(previos_arr);
            destruirDistanciasInt(distancias);        
           
        }
        double para_escribir[2];
        para_escribir[0] = (double) cant_aristas;
        para_escribir[1] = promedio(stats, cant_stats);
        escribir(para_escribir, out);
    }
    fclose(out);
}

int main(int argc, char *argv[]){
    int *d = distanciasInt(5);
    NodoA1 *p = previos(5);
      
    //leer el archivo de input
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
    destruirGrafoDeJuguete(arr, 5);

    NodoA1 test_alg1[5];
    crearGrafoDeJuguete(5, test_alg1);
    int raiz = 0;
    int nNodos = 5;
    algoritmo1(test_alg1,raiz,nNodos,d,p);
    
    
    test(0,d[0], 7);
    test(4,d[1], 8);
    test(2,d[2], 9);
    test(3,d[3], 10);
    test(5,d[4], 11);

    destruirGrafoDeJuguete(test_alg1,5);

    destruirDistanciasInt(d);
    destruirPrevios(p);

    prueba_de_esfuerzo();
}