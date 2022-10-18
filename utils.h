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
    Nodo *arr
} ColaFib;

int extractMinColaHeap(ColaHeap c);
int extractMinColaFib(ColaFib c);
int extractMinNormal(int **arr);
