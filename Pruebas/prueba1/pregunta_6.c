#include "pregunta_6.h"

#include <stdlib.h>
//void liberar(char** nombres, int* numeros, int numero_elementos)
void liberar(char** nombres, int numero_elementos) {

    free(nombres);
    //free(numeros);
}