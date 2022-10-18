#include <stdlib.h>
#include <stdio.h>

#include "utils.c"



void test(int expected, int got, int ntest){
    
    if(expected != got){
        fprintf(stdout, "Expected %i, got %i\n", expected, got);
    }else{
        fprintf(stdout, "Test numero %i pasado\n", ntest);
    }
}
// arr es memoria dinamica
int extractMin(int **arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 2; j++){
        }
    }
    return 1;
}

int main(int argc, char *argv[]){
    int *d = distanciasInt(30);
    int *p = previos(30);
      
    //leer el archivo de input
    //FILE *in = fopen(argv[1], "r");

    NodoA1  arr[5];
    crearGrafoDeJuguete(5,arr);
    test(1, arr[0].valor, 1);
    test(2, arr[1].valor, 2);
    test(3, arr[2].valor, 3);
    test(4, arr[3].valor, 4); 
    test(5, arr[4].valor, 5);

    destruirGrafoDeJuguete(arr, 5);
    destruirDistanciasInt(d);
    destruirPrevios(p);
}