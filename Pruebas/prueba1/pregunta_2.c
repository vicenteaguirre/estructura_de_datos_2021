#include "pregunta_2.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int* leer_archivo_numero(char* filename) { 
    FILE * archivo = fopen(filename ,"r");
    char * linea;
    int numero;
    int * numeros = (int*) malloc(64*sizeof(int*));
    int cont = 0;
    //fscanf(archivo,"%d",&numero);
    //printf("%d\n",numeros[cont]);
    //cont++;



/*
    cont= 0;
    for(int i; i<4;i++){
        printf("%d\n",numeros[cont]);
    }
    //printf("%s\n%s\n",numeros[0],numeros[1]);
*/
    return numeros; //Esta bien no cambiar
    }