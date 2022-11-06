#include <stdbool.h>

typedef struct nodo {
    int contenido;
    struct nodo *sig;
} Nodo;

typedef struct colaFib {
    int min;
    Nodo *arr;
} ColaFib;

typedef struct nodoA1{
    int valor; 
    int nVecinos;
    int **vecinos; // {[v1,4], [v2,5], [v3,7], [v4,3]}
}NodoA1;


//Nodo para el algoritmo 2
typedef struct nodoA2{
    int valor; 
    int nVecinos;
    int dist; //c/r al nodo raiz
    int **vecinos; // {[v1,4], [v2,5], [v3,7], [v4,3]}
}NodoA2;


typedef struct nodoA3
{
    int valor;
    int nVecinos;
    int **vecinos;
}nodoA3;

typedef struct colaHeap {
    int min;
    int n;
    NodoA2 *arr;
} ColaHeap;
