#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElementoLista{
    char * nombre;
    float * nota;
    struct ElementoLista * siguiente;
}Elemento;

typedef struct lista{
    Elemento * inicio;
    Elemento * fin;
    int cont;
}Lista;

void inicializacion (Lista *lista);

// inserción en una lista vacía 
int ins_en_lista_vacia (Lista * lista, char * dato);

// inserción al inicio de la lista 
int ins_inicio_lista (Lista * lista,char * dato);

//inserción al final de la lista 
int ins_fin_lista (Lista *lista, Elemento *actual, char *dato);

// insercion en la posicion solicitada 
int ins_lista (Lista *lista, char *dato,int pos);

// eliminación al inicio de la lista 
int sup_inicio (Lista *lista);

// eliminar un elemento después de la posición solicitada
int sup_en_lista (Lista *lista, int pos);



void print_sort(FILE * file); 
