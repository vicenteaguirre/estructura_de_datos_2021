#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElementoLista{
    char * nombre;
    struct ElementoLista * siguiente;
}Elemento;

typedef struct lista{
    Elemento * inicio;
    Elemento * fin;
    int cont;
}Lista;

void inicializacion (Lista *lista);

int ins_en_lista_vacia (Lista * lista, char * dato);

int ins_inicio_lista (Lista * lista,char * dato);

int ins_fin_lista (Lista *lista, Elemento *actual, char *dato);

int ins_lista (Lista *lista, char *dato,int pos);

void print_sort(FILE* f);








void print_sort(FILE * file); 
