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
}

int main(int argc, char *argv[]){
    int *d = distanciasInt(30);
    int *p = previos(30);
    
    //leer el archivo de input
    //FILE *in = fopen(argv[1], "r");

    int arr[5][2];
    crearGrafoDeJuguete(3,arr);
    
    test(1, arr[0][0], 1);
    test(2, arr[0][1], 2);
    test(2, arr[1][0], 3);
    test(3, arr[1][1], 4); 
    test(3, arr[2][0], 5);
    test(4, arr[2][1], 6);
    destruirDistanciasInt(d);
    destruirPrevios(p);
}