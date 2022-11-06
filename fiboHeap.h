#include "utils.c"

typedef struct ELN enlacedListNode;

typedef struct fiboNode
{
    int distancia; //la llave de la cola de fibonacci, se necesita sacar aquel con menor distancia.
    int id; // el identificador del nodo, se utilizará para reemplazar el coso
    int nNodos; // la cantidad de nodos de este arbol
    nodoA3 * storagedNode;
    enlacedListNode * listPosition; //nodo del bosque de fibonacci al que esta unido
    enlacedListNode * childs;//lista de los nodos colgados a este
    struct fiboNode * father;//el nodo al que este esta colgado.
}Node;

struct ELN
{
    Node *valor;
    struct ELN * next;
    
};

typedef struct fiboHeap
{
    enlacedListNode * lastElement; //ultimo elemento del bosque de fibbonacci
    enlacedListNode * forest; //bosque de fibonnacci, lista de arboles de fibbonacci.
    Node * min; //puntero menor nodo del bosque.
}Fib_Heap;

Node *newNode(int distancia, int id, nodoA3 *nodo);
void destroyNode(Node *n);

enlacedListNode *create_enlaced_list(Node *firstVal);
void insert_on_EL(Node *newVal, enlacedListNode **list);
void destroy_enlaced_list(enlacedListNode *list);
//listo hasta aqui

Fib_Heap *create_fibonacci_heap(Node *node);
void insert(Fib_Heap *CF, nodoA3 *nuevo, int dist);
nodoA3 *get(Fib_Heap *CF);
void merge(Fib_Heap *CF1, Fib_Heap *CF2);
void DecreaseKey(Fib_Heap *CF, int llave, int nueva_dist);
void destroyFH(Fib_Heap *CF);