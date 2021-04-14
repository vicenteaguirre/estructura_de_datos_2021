#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumno{
    char * nombre;
    float nota;
}Alumno;
typedef struct nodo{
    Alumno alumno;
    struct Nodo * siguiente;
}Nodo;
typedef struct lista{
    struct Nodo * principal;
}Lista;

void print_sort(FILE * file); 
Nodo * crearNodo(Alumno * alumno);
void mostrar_alumnos(Nodo * ptr);