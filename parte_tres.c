#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <math.h>

#include "fiboHeap.c"

void test(int expected, int got, int ntest){
    
    if(expected != got){
        fprintf(stdout, "Test %i, Expected %i, got %i\n", ntest, expected, got);
    }else{
        fprintf(stdout, "Test %i pasado\n", ntest);
    }
}

void testeo_listas_enlazadas(enlacedListNode *list){
    enlacedListNode *next= list->next;
    printf("distance: %i, id: %i\n",list->valor->distancia, list->valor->id);
    if(next != NULL){
        testeo_listas_enlazadas(next);
    }
}

/*
void algoritmo3(NodoA1 *nodo, int raiz, int cant_nodos, int * distancias, NodoA1 * previos){
    //inicializamos dos arreglos, que contienen las distancias y 
    //los nodos previos(?
    int arreglo_indices[cant_nodos];
    FIB_HEAP * aux=make_fib_heap();  
    //int cantidadDentrodeAux= 0;
    NodoA1 nodo_null = {-1,-1};

    for(int i=0;i<cant_nodos;i++){
        NODE * node;
        //metemos a la cola de fibonacci todos los nodos
        distancias[i]=INT_MAX;
        //Asignar los previos como indefinidos   
        previos[i] = nodo_null; 
        insertion(aux, node,&nodo[i],distancias[i]);
        // rellenando aux
        //Asignamos el arreglo de indices
        arreglo_indices[i]=i;
    }
    distancias[raiz]=0;
    find_node(aux,aux->min,raiz,0); 
    int contador = cant_nodos;
    //int min = distancias[0];
    while(contador>0){
        NODE* min_dist = extract_min(aux);
        NodoA1 * min_node = min_dist->storedNode;
        int ** vecinos = min_node->vecinos;
        for(int i=0; i< min_node->nVecinos;i++){
            int dis_tabla = distancias[vecinos[i][0]];
            int dis_v_mas_u = distancias[min_node->valor] + vecinos[i][1];
            if(dis_v_mas_u < dis_tabla){
                distancias[vecinos[i][0]]= dis_v_mas_u;
                find_node(aux,aux->min,vecinos[i][0],dis_v_mas_u);
            }
        }
        contador--;
    }
    free(aux);
}
*/

int main(int argc, char *argv[]){
    /*
    int *d = distanciasInt(5);
    NodoA1 *p = previos(5);
    */
    Node base= {40,40,NULL,NULL,NULL};
    enlacedListNode * list = create_enlaced_list(&base);

    Node *pruebas[5];
    for(int i =0; i<5;i++){
        pruebas[i]->childs=NULL;
        pruebas[i]->distancia=i;
        pruebas[i]->id=1;
        pruebas[i]->father=NULL;
        pruebas[i]->storagedNode=NULL;
        insert_on_EL(pruebas[i],list);
    }
    testeo_listas_enlazadas(list);
    destroy_enlaced_list(list);
    //leer el archivo de input
    /*
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
    algoritmo3(test_alg1,raiz,nNodos,d,p);
    
    
    test(0,d[0], 7);
    test(4,d[1], 8);
    test(2,d[2], 9);
    test(3,d[3], 10);
    test(5,d[4], 11);

    destruirGrafoDeJuguete(test_alg1,5);

    destruirDistanciasInt(d);
    destruirPrevios(p);

    //prueba_de_esfuerzo();
    */
}