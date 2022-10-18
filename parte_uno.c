#include <stdlib.h>
#include <stdio.h>

#include "utils.c"



int main(int argc, char *argv[]){
    double *d = distanciasInt(30);
    double *p = previos(30);
    
    destruirDistanciasDouble(d);
    destruirPrevios(p);
}