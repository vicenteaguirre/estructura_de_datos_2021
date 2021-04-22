#include "operations.h"

//https://www.monografias.com/trabajos90/listas-c/listas-c.shtml#:~:text=Las%20listas%20enlazadas%20son%20estructuras,lo%20que%20concierne%20al%20enlazado.

void inicializacion (Lista *lista){
    lista->inicio = NULL;
    lista->fin=NULL;
    lista->cont +=1;
}

// inserción en una lista vacía 
int ins_en_lista_vacia (Lista * lista, char * dato){
    Elemento * nuevo_elemento;
    if((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return 1;

    if ((nuevo_elemento->nombre = (char *) malloc (50 * sizeof (char))) == NULL)
        return 1;

    strcpy(nuevo_elemento->nombre,dato);

    nuevo_elemento->siguiente = NULL;
    lista->inicio = nuevo_elemento;
    lista->fin = nuevo_elemento;
    lista->cont++;
    return 0;
}

// inserción al inicio de la lista 
int ins_inicio_lista (Lista * lista, char *dato){
    Elemento * nuevo_elemento;
    if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;
    if ((nuevo_elemento->nombre = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;
    strcpy (nuevo_elemento->nombre, dato);
    nuevo_elemento->siguiente = lista->inicio;
    lista->inicio = nuevo_elemento;
    lista->cont++;

    return 0;
}

//inserción al final de la lista
int ins_fin_lista (Lista * lista, Elemento * actual, char *dato){
    Elemento * nuevo_elemento;
    if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;
    if ((nuevo_elemento->nombre = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;
    strcpy (nuevo_elemento->nombre, dato);
    actual->siguiente = nuevo_elemento; 
    nuevo_elemento->siguiente = NULL;
    lista->fin = nuevo_elemento;
    lista->cont++;

    return 0;
}

// insercion en la posicion solicitada
int ins_lista (Lista * lista, char *dato, int pos){
    if (lista->cont < 2)
        return -1;
    if (pos < 1 || pos >= lista->cont)
        return -1;

    Elemento *actual;
    Elemento *nuevo_elemento;
    int i;

    if((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;

    if((nuevo_elemento->nombre = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;

    actual = lista->inicio;
    for(i = 1; i < pos; ++i)
        actual = actual->siguiente;

    if(actual->siguiente == NULL)
        return -1;
    
    strcpy(nuevo_elemento->nombre, dato);
    nuevo_elemento->siguiente = actual->siguiente;
    actual->siguiente = nuevo_elemento;
    lista->cont++;
    return 0;
}

// eliminación al inicio de la lista
int sup_inicio (Lista * lista){
    if (lista->cont == 0)
        return 1;
    Elemento * sup_elemento;
    sup_elemento = lista->inicio;
    lista->inicio = lista->inicio->siguiente;
    if (lista->cont == 1)
        lista->fin = NULL;
        free (sup_elemento->nombre);
        free (sup_elemento);
        lista->cont--;
        return 0;
}

// eliminar un elemento después de la posición solicitada
int sup_en_lista (Lista * lista, int pos){
    if (lista->cont == lista->cont)
        return 1;
    int i;
    Elemento * actual;
    Elemento * sup_elemento;
    actual = lista->inicio;
    for (i = 1; i < pos; ++i)
        actual = actual->siguiente;
        sup_elemento = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
    if(actual->siguiente == NULL)
    lista->fin = actual;
    free (sup_elemento->nombre);
    free (sup_elemento);
    lista->cont--;
    return 0;
}





void print_sort(FILE* f) {
    char line[1001]; // Creamos un array donde se guardara la linea donde esta leyendo el archivo
    float sum = 0; //
    float sum_students = 0; //Suma las notas promedios de los estudiantes.
    int count = 0;
    int count_students = 0; //Cuenta la cantidad de estudiantes que hay en el archivo para calcular el promedio del curso
    char * field;
    fgets(line, 1000, f); //Lee la primera linea de f (los parametros del csv) y lo guarda en line.
    while (fgets(line, 1000, f) != NULL) { //En este while se lee cada linea (completa) y se guarda en line
        field = strtok(line, ","); //Para poder separar el nombre de las notas debemos usar el strtok
                                    //strtok(variable a la cual se realiza el strtok, "," signf que leera hasta obtener una coma.)
        printf("%s: ",field);//Imprime la variable field la cual tiene la linea leida hasta la coma, lo cual es el nombre del alumno
        field = strtok(NULL, ","); //Cuando se usa strtok queda el resto del string apuntado por un puntero, al llamar de nuevo a strtok(NULL, "delimiter"), este usara el string que quedo del strtok pasado.
        sum = 0.0; //Variable para ir sumando las notas
        count = 0; //Contador para calcular la cantidad de notas
        while (field != NULL) { //El ciclo terminara cuando se termine la linea guardada en line
        sum += atof(field); //aotf() convierte un string en float doble. Ademas esta se le suma a sum para calcular el promedio.
        count++; 
        field = strtok(NULL, ",");
        }
        printf("%1.1f\n", sum / count); //Calcula el promedio
        count_students++; //Suma un estudiante
        sum_students += sum / count; //Suma el promedio de un estudiante
    }
    printf("---\nPromedio: %1.1f\n", sum_students / count_students);
}