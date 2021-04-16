#include "pregunta_1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char * * leer_archivo_texto(char* filename) { 
    FILE * archivo = fopen(filename ,"r");
    char * linea;
    char * * nombres = (char* *) malloc(255*sizeof(char *));
    int cont = 0;
    while(fgets(linea, 1000, archivo)!=NULL){
        strtok(linea,"\n");
        int cant_c = strlen(linea);
        nombres[cont] = (char *) malloc(cant_c*sizeof(char));
        strcpy(nombres[cont],linea);
        cont+=1;
    } // Deberia imprimir Felipe
    return nombres; //Esta bien no cambiar
}