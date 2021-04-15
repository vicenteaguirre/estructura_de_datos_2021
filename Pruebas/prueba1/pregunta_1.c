#include "pregunta_1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char * * leer_archivo_texto(char* filename) { 
    FILE * archivo = fopen(filename ,"r");
    char * linea;
    char * * nombres = (char* *) malloc(255*sizeof(char* *));
    int cont = 0;
    while(fgets(linea, 1000, archivo)!=NULL){
        strtok(linea,"\n");
        printf("Valor de linea: %s\n",linea);
        nombres[cont] = linea;
        printf("Valor de nombre: %s\n",*(nombres+cont));
        printf("\n");
        cont+=1;
    }
    cont = 1;
    printf("Valor de nombre: %s\n",*(nombres+cont)); // Deberia imprimir Felipe
    return nombres; //Esta bien no cambiar
}