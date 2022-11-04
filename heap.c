#include <stdlib.h>
#include <stdio.h>

void insert(int a[], int x, int *n){
    *n = *n + 1;
    a[*n]=x;
    for(int j=*n; j>1 && a[j]<a[j/2]; j= j/2)
      { // intercambiamos con el padre
        int t=a[j];
        a[j]=a[j/2];
        a[j/2]=t;
      }
}

int extract_min(int a[], int *n){
    int m=a[1]; // # La variable m lleva el m�ximo
    a[1]=a[(*n)--]; // # Movemos el �ltimo a la ra�z y achicamos el heap
    int j=1;
    while(2*j<=(*n)) //# mientras tenga alg�n hijo
    {
        int k=2*j; //# el hijo izquierdo
        if(k+1<=(*n) && a[k+1]<a[k])
            k=k+1;  //# el hijo derecho es el mayor
        if(a[j]<a[k])
            break;  //# es mayor que ambos hijos
        int t=a[j];  
        a[j]=a[k];
        a[k]=t;  
        j=k;   //# lo intercambiamos con el mayor hijo
    }
    return m;
}

int main(){
    int a[10], n=0;
    for(int i =1; i< 10; i++){
        insert(a, i, &n);
    }

    for(int i = 1; i< 10; i++){
        printf("%i\n",extract_min(a,&n));
    }
}

