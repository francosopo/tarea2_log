#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
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

void destruirDistanciasInt(int *dis){
    free(dis);
}

NodoA1 *previos(int size){
    NodoA1 *prev = calloc(size, sizeof(NodoA1));

    if (prev == NULL){
        perror("previos calloc");
    }
    return prev;
}



void destruirPrevios(NodoA1 *prev){
    free(prev);
}

void crearGrafoDeJuguete(int size, NodoA1 *arr){
    int a=0, b=1, c=2, d=3,e=4;
    int **vecinos_a = calloc(size, sizeof(int*));

    if(vecinos_a == NULL){
        perror("vecinos_a");
    }

    for(int i = 0; i< size; i++){
        vecinos_a[i] = calloc(2, sizeof(int));
        if(vecinos_a[i] == NULL){
            fprintf(stderr,"vecinos_a[%i]", i);
        }
    }

    vecinos_a[0][0] = 1;
    vecinos_a[0][1] = 8;
    vecinos_a[1][0] = 2;
    vecinos_a[1][1] = 2;
    vecinos_a[2][0] = 3;
    vecinos_a[2][1] = 3;
    vecinos_a[3][0] = 4;
    vecinos_a[3][1] = 7;

    arr[0].valor = a;
    arr[0].vecinos = vecinos_a;
    arr[0].nVecinos = 4;



    int **vecinos_b = calloc(size, sizeof(int*));

    if(vecinos_b == NULL){
        perror("vecinos_b");
    }
    for(int i = 0; i< size; i++){
        vecinos_b[i] = calloc(2, sizeof(int));
        if(vecinos_b[i] == NULL){
            fprintf(stderr,"vecinos_b[%i]", i);
        }
    } 

    
    vecinos_b[0][0] = 0;
    vecinos_b[0][1] = 7;
    vecinos_b[1][0] = 2;
    vecinos_b[1][1] = 1;
    vecinos_b[2][0] = 3;
    vecinos_b[2][1] = 5;
    vecinos_b[3][0] = 4;
    vecinos_b[3][1] = 3;

    arr[1].valor = b;
    arr[1].vecinos = vecinos_b;
    arr[1].nVecinos = 4;
    

    int **vecinos_c = calloc(size, sizeof(int*));
    if(vecinos_c == NULL){
        perror("vecinos_c");
    }
    for(int i = 0; i< size; i++){
        vecinos_c[i] = calloc(2, sizeof(int));
        if(vecinos_c[i] == NULL){
            fprintf(stderr,"vecinos_c[%i]", i);
        }
    }    

    
    vecinos_c[0][0] = 0;
    vecinos_c[0][1] = 3;
    vecinos_c[1][0] = 1;
    vecinos_c[1][1] = 2;
    vecinos_c[2][0] = 3;
    vecinos_c[2][1] = 7;
    vecinos_c[3][0] = 4;
    vecinos_c[3][1] = 8;

    arr[2].valor = c;
    arr[2].vecinos = vecinos_c;
    arr[2].nVecinos = 4;
    

    int **vecinos_d = calloc(size, sizeof(int*));
    if(vecinos_d == NULL){
        perror("vecinos_d");
    }
    for(int i = 0; i< size; i++){
        vecinos_d[i] = calloc(2, sizeof(int));
        if(vecinos_d[i] == NULL){
            fprintf(stderr,"vecinos_d[%i]", i);
        }
    } 

    
    vecinos_d[0][0] = 0;
    vecinos_d[0][1] = 1;
    vecinos_d[1][0] = 1;
    vecinos_d[1][1] = 7;
    vecinos_d[2][0] = 2;
    vecinos_d[2][1] = 5;
    vecinos_d[3][0] = 4;
    vecinos_d[3][1] = 2; 
    
    arr[3].valor = d;
    arr[3].vecinos = vecinos_d;
    arr[3].nVecinos = 4;    
    
    int **vecinos_e = calloc(size, sizeof(int*));

    if(vecinos_e == NULL){
        perror("vecinos_e");
    }
    for(int i = 0; i< size; i++){
        vecinos_e[i] = calloc(2, sizeof(int));
        if(vecinos_e[i] == NULL){
            fprintf(stderr,"vecinos_e[%i]", i);
        }
    } 
    vecinos_e[0][0] = 0;
    vecinos_e[0][1] = 7;
    vecinos_e[1][0] = 1;
    vecinos_e[1][1] = 8;
    vecinos_e[2][0] = 2;
    vecinos_e[2][1] = 2;
    vecinos_e[3][0] = 3;
    vecinos_e[3][1] = 3;

    arr[4].valor = e;
    arr[4].vecinos = vecinos_e;
    arr[4].nVecinos = 4;
}

void destruirGrafoDeJuguete(NodoA1 *arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            free((arr[i].vecinos)[j]);
        }
        free(arr[i].vecinos);
    }
}

FIB_HEAP *make_fib_heap() {
  FIB_HEAP *H;
  H = (FIB_HEAP *)malloc(sizeof(FIB_HEAP));
  H->n = 0;
  H->min = NULL;
  H->phi = 0;
  H->degree = 0;
  return H;
}

// Printing the heap
void print_heap(NODE *n) {
  NODE *x;
  for (x = n;; x = x->right_sibling) {
    if (x->child == NULL) {
      printf("node with no child (%d) \n", x->key);
    } else {
      printf("NODE(%d) with child (%d)\n", x->key, x->child->key);
      print_heap(x->child);
    }
    if (x->right_sibling == n) {
      break;
    }
  }
}

// Inserting nodes
void insertion(FIB_HEAP *H, NODE *new, int val) {
  new = (NODE *)malloc(sizeof(NODE));
  new->key = val;
  new->degree = 0;
  new->mark = false;
  new->parent = NULL;
  new->child = NULL;
  new->visited = false;
  new->left_sibling = new;
  new->right_sibling = new;
  if (H->min == NULL) {
    H->min = new;
  } else {
    H->min->left_sibling->right_sibling = new;
    new->right_sibling = H->min;
    new->left_sibling = H->min->left_sibling;
    H->min->left_sibling = new;
    if (new->key < H->min->key) {
      H->min = new;
    }
  }
  (H->n)++;
}

// Find min node
NODE *find_min_node(FIB_HEAP *H) {
  if (H == NULL) {
    printf(" \n Fibonacci heap not yet created \n");
    return NULL;
  } else
    return H->min;
}

// Union operation
FIB_HEAP *unionHeap(FIB_HEAP *H1, FIB_HEAP *H2) {
  FIB_HEAP *Hnew;
  Hnew = make_fib_heap();
  Hnew->min = H1->min;

  NODE *temp1, *temp2;
  temp1 = Hnew->min->right_sibling;
  temp2 = H2->min->left_sibling;

  Hnew->min->right_sibling->left_sibling = H2->min->left_sibling;
  Hnew->min->right_sibling = H2->min;
  H2->min->left_sibling = Hnew->min;
  temp2->right_sibling = temp1;

  if ((H1->min == NULL) || (H2->min != NULL && H2->min->key < H1->min->key))
    Hnew->min = H2->min;
  Hnew->n = H1->n + H2->n;
  return Hnew;
}

// Calculate the degree
int cal_degree(int n) {
  int count = 0;
  while (n > 0) {
    n = n / 2;
    count++;
  }
  return count;
}

// Consolidate function
void consolidate(FIB_HEAP *H) {
  int degree, i, d;
  degree = cal_degree(H->n);
  NODE *A[degree], *x, *y, *z;
  for (i = 0; i <= degree; i++) {
    A[i] = NULL;
  }
  x = H->min;
  do {
    d = x->degree;
    while (A[d] != NULL) {
      y = A[d];
      if (x->key > y->key) {
        NODE *exchange_help;
        exchange_help = x;
        x = y;
        y = exchange_help;
      }
      if (y == H->min)
        H->min = x;
      fib_heap_link(H, y, x);
      if (y->right_sibling == x)
        H->min = x;
      A[d] = NULL;
      d++;
    }
    A[d] = x;
    x = x->right_sibling;
  } while (x != H->min);

  H->min = NULL;
  for (i = 0; i < degree; i++) {
    if (A[i] != NULL) {
      A[i]->left_sibling = A[i];
      A[i]->right_sibling = A[i];
      if (H->min == NULL) {
        H->min = A[i];
      } else {
        H->min->left_sibling->right_sibling = A[i];
        A[i]->right_sibling = H->min;
        A[i]->left_sibling = H->min->left_sibling;
        H->min->left_sibling = A[i];
        if (A[i]->key < H->min->key) {
          H->min = A[i];
        }
      }
      if (H->min == NULL) {
        H->min = A[i];
      } else if (A[i]->key < H->min->key) {
        H->min = A[i];
      }
    }
  }
}

// Linking
void fib_heap_link(FIB_HEAP *H, NODE *y, NODE *x) {
  y->right_sibling->left_sibling = y->left_sibling;
  y->left_sibling->right_sibling = y->right_sibling;

  if (x->right_sibling == x)
    H->min = x;

  y->left_sibling = y;
  y->right_sibling = y;
  y->parent = x;

  if (x->child == NULL) {
    x->child = y;
  }
  y->right_sibling = x->child;
  y->left_sibling = x->child->left_sibling;
  x->child->left_sibling->right_sibling = y;
  x->child->left_sibling = y;
  if ((y->key) < (x->child->key))
    x->child = y;

  (x->degree)++;
}

// Extract min
NODE *extract_min(FIB_HEAP *H) {
  if (H->min == NULL)
    printf("\n The heap is empty");
  else {
    NODE *temp = H->min;
    NODE *pntr;
    pntr = temp;
    NODE *x = NULL;
    if (temp->child != NULL) {
      x = temp->child;
      do {
        pntr = x->right_sibling;
        (H->min->left_sibling)->right_sibling = x;
        x->right_sibling = H->min;
        x->left_sibling = H->min->left_sibling;
        H->min->left_sibling = x;
        if (x->key < H->min->key)
          H->min = x;
        x->parent = NULL;
        x = pntr;
      } while (pntr != temp->child);
    }

    (temp->left_sibling)->right_sibling = temp->right_sibling;
    (temp->right_sibling)->left_sibling = temp->left_sibling;
    H->min = temp->right_sibling;

    if (temp == temp->right_sibling && temp->child == NULL)
      H->min = NULL;
    else {
      H->min = temp->right_sibling;
      consolidate(H);
    }
    H->n = H->n - 1;
    return temp;
  }
  return H->min;
}

void cut(FIB_HEAP *H, NODE *node_to_be_decrease, NODE *parent_node) {
  NODE *temp_parent_check;

  if (node_to_be_decrease == node_to_be_decrease->right_sibling)
    parent_node->child = NULL;

  node_to_be_decrease->left_sibling->right_sibling = node_to_be_decrease->right_sibling;
  node_to_be_decrease->right_sibling->left_sibling = node_to_be_decrease->left_sibling;
  if (node_to_be_decrease == parent_node->child)
    parent_node->child = node_to_be_decrease->right_sibling;
  (parent_node->degree)--;

  node_to_be_decrease->left_sibling = node_to_be_decrease;
  node_to_be_decrease->right_sibling = node_to_be_decrease;
  H->min->left_sibling->right_sibling = node_to_be_decrease;
  node_to_be_decrease->right_sibling = H->min;
  node_to_be_decrease->left_sibling = H->min->left_sibling;
  H->min->left_sibling = node_to_be_decrease;

  node_to_be_decrease->parent = NULL;
  node_to_be_decrease->mark = false;
}

void cascading_cut(FIB_HEAP *H, NODE *parent_node) {
  NODE *aux;
  aux = parent_node->parent;
  if (aux != NULL) {
    if (parent_node->mark == false) {
      parent_node->mark = true;
    } else {
      cut(H, parent_node, aux);
      cascading_cut(H, aux);
    }
  }
}

void decrease_key(FIB_HEAP *H, NODE *node_to_be_decrease, int new_key) {
  NODE *parent_node;
  if (H == NULL) {
    printf("\n FIbonacci heap not created ");
    return;
  }
  if (node_to_be_decrease == NULL) {
    printf("Node is not in the heap");
  }

  else {
    if (node_to_be_decrease->key < new_key) {
      printf("\n Invalid new key for decrease key operation \n ");
    } else {
      node_to_be_decrease->key = new_key;
      parent_node = node_to_be_decrease->parent;
      if ((parent_node != NULL) && (node_to_be_decrease->key < parent_node->key)) {
        printf("\n cut called");
        cut(H, node_to_be_decrease, parent_node);
        printf("\n cascading cut called");
        cascading_cut(H, parent_node);
      }
      if (node_to_be_decrease->key < H->min->key) {
        H->min = node_to_be_decrease;
      }
    }
  }
}

void *find_node(FIB_HEAP *H, NODE *n, int key, int new_key) {
  NODE *find_use = n;
  NODE *f = NULL;
  find_use->visited = true;
  if (find_use->key == key) {
    find_use->visited = false;
    f = find_use;
    decrease_key(H, f, new_key);
  }
  if (find_use->child != NULL) {
    find_node(H, find_use->child, key, new_key);
  }
  if ((find_use->right_sibling->visited != true)) {
    find_node(H, find_use->right_sibling, key, new_key);
  }

  find_use->visited = false;
}

FIB_HEAP *insertion_procedure() {
  FIB_HEAP *temp;
  int no_of_nodes, ele, i;
  NODE *new_node;
  temp = (FIB_HEAP *)malloc(sizeof(FIB_HEAP));
  temp = NULL;
  if (temp == NULL) {
    temp = make_fib_heap();
  }
  printf(" \n enter number of nodes to be insert = ");
  scanf("%d", &no_of_nodes);
  for (i = 1; i <= no_of_nodes; i++) {
    printf("\n node %d and its key value = ", i);
    scanf("%d", &ele);
    insertion(temp, new_node, ele);
  }
  return temp;
}
void Delete_Node(FIB_HEAP *H, int dec_key) {
  NODE *p = NULL;
  find_node(H, H->min, dec_key, -5000);
  p = extract_min(H);
  if (p != NULL)
    printf("\n Node deleted");
  else
    printf("\n Node not deleted:some error");
}

int main(int argc, char **argv) {
  NODE *new_node, *min_node, *extracted_min, *node_to_be_decrease, *find_use;
  FIB_HEAP *heap, *h1, *h2;
  int operation_no, new_key, dec_key, ele, i, no_of_nodes;
  heap = (FIB_HEAP *)malloc(sizeof(FIB_HEAP));
  heap = NULL;
  while (1) {
    printf(" \n Operations \n 1. Create Fibonacci heap \n 2. Insert nodes into fibonacci heap \n 3. Find min \n 4. Union \n 5. Extract min \n 6. Decrease key \n 7.Delete node \n 8. print heap \n 9. exit \n enter operation_no = ");
    scanf("%d", &operation_no);

    switch (operation_no) {
      case 1:
        heap = make_fib_heap();
        break;

      case 2:
        if (heap == NULL) {
          heap = make_fib_heap();
        }
        printf(" enter number of nodes to be insert = ");
        scanf("%d", &no_of_nodes);
        for (i = 1; i <= no_of_nodes; i++) {
          printf("\n node %d and its key value = ", i);
          scanf("%d", &ele);
          insertion(heap, new_node, ele);
        }
        break;

      case 3:
        min_node = find_min_node(heap);
        if (min_node == NULL)
          printf("No minimum value");
        else
          printf("\n min value = %d", min_node->key);
        break;

      case 4:
        if (heap == NULL) {
          printf("\n no FIbonacci heap created \n ");
          break;
        }
        h1 = insertion_procedure();
        heap = unionHeap(heap, h1);
        printf("Unified Heap:\n");
        print_heap(heap->min);
        break;

      case 5:
        if (heap == NULL)
          printf("Empty Fibonacci heap");
        else {
          extracted_min = extract_min(heap);
          printf("\n min value = %d", extracted_min->key);
          printf("\n Updated heap: \n");
          print_heap(heap->min);
        }
        break;

      case 6:
        if (heap == NULL)
          printf("Fibonacci heap is empty");
        else {
          printf(" \n node to be decreased = ");
          scanf("%d", &dec_key);
          printf(" \n enter the new key = ");
          scanf("%d", &new_key);
          find_use = heap->min;
          find_node(heap, find_use, dec_key, new_key);
          printf("\n Key decreased- Corresponding heap:\n");
          print_heap(heap->min);
        }
        break;
      case 7:
        if (heap == NULL)
          printf("Fibonacci heap is empty");
        else {
          printf(" \n Enter node key to be deleted = ");
          scanf("%d", &dec_key);
          Delete_Node(heap, dec_key);
          printf("\n Node Deleted- Corresponding heap:\n");
          print_heap(heap->min);
          break;
        }
      case 8:
        print_heap(heap->min);
        break;

      case 9:
        free(new_node);
        free(heap);
        exit(0);

      default:
        printf("Invalid choice ");
    }
  }
}