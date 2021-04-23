#include "funciones.h"

// Reutilizamos el codigo del main de la tarea anterior.
int main(int argc, char const * argv[]){
    FILE * file;
    if (argc != 2) {
        fprintf(stderr, "Debe ingresar solamente un argumento.");        
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "El archivo no existe.");
        return 2;
    }
    print_sorted(file);
    fclose(file);
    return 0;
}
