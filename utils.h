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


typedef struct colaHeap {
    int min;
    int n;
    NodoA2 *arr;
} ColaHeap;

/*
typedef struct _NODE {
  int key;
  int degree;
  int nodetag;
  NodoA1 * storedNode;
  struct _NODE *left_sibling;
  struct _NODE *right_sibling;
  struct _NODE *parent;
  struct _NODE *child;
  bool mark;
  bool visited;
} NODE;

typedef struct fibanocci_heap {
  int n;
  NODE *min;
  int phi;
  int degree;
} FIB_HEAP;

FIB_HEAP *make_fib_heap();
void insertion(FIB_HEAP *H, NODE *new, NodoA1 * val, int key);
NODE *extract_min(FIB_HEAP *H);
void consolidate(FIB_HEAP *H);
void fib_heap_link(FIB_HEAP *H, NODE *y, NODE *x);
NODE *find_min_node(FIB_HEAP *H);
void decrease_key(FIB_HEAP *H, NODE *node, int key);
void cut(FIB_HEAP *H, NODE *node_to_be_decrease, NODE *parent_node);
void cascading_cut(FIB_HEAP *H, NODE *parent_node);
void Delete_Node(FIB_HEAP *H, int dec_key);

int extractMinColaHeap(ColaHeap c);
int extractMinColaFib(ColaFib c);
int extractMinNormal(NodoA1 **arr);
*/