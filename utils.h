typedef struct colaHeap {
    int min;
    int *arr;
} ColaHeap;

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



int extractMinColaHeap(ColaHeap c);
int extractMinColaFib(ColaFib c);
int extractMinNormal(NodoA1 **arr);
