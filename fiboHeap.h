#include "utils.h"

typedef struct ELN enlacedListNode;

typedef struct fiboNode
{
    int distancia; //la llave de la cola de fibonacci, se necesita sacar aquel con menor distancia.
    int id; // el identificador del nodo, se utilizará para reemplazar el coso
    nodoA3 * storagedNode;
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
    enlacedListNode * forest; //bosque de fibonnacci, lista de arboles de fibbonacci.
    Node * min; //puntero menor nodo del bosque.
}Fib_Heap;

enlacedListNode *create_enlaced_list(Node *firstVal);
void insert_on_EL(Node *newVal, enlacedListNode *list);
void destroy_enlaced_list(enlacedListNode *list);
Fib_Heap *create_fibonacci_heap();
void insert(Fib_Heap CF, nodoA3 nuevo);
nodoA3 get(Fib_Heap CF);
void DecreaseKey(Fib_Heap CF, int llave, int nueva_dist);
void destroyFH(Fib_Heap CF);