#include "funciones.h"

void print_sorted(FILE * f){
    /* Variables y Arreglos */

    //Lectura
    char line[1001]; // Creamos un array donde se guardara la linea donde esta leyendo el archivo
    char * field;

    // Arreglos
    char * * nombres;
    float * notas;
    
    // Promedio del alumno
    float sum = 0; //Suma las notas del alumno
    int cant_notas = 0; //Cantidad de nota por alumno

    // Promedio del curso
    int count_students = 0; //Cuenta la cantidad de estudiantes que hay en el archivo para calcular el promedio del curso
    float sum_students = 0; //Suma las notas promedios de los estudiantes.
    
    // Contadores
    int cant_alumnos; // Cantidad de alumnos en total.
    int cont = 0; // Para manejar los index de los areglos


    /* Codigos */

    // Cuenta la cantidad de alumnos en total
    fgets(line, 1000, f);
    while(fgets(line, 1000, f) != NULL)
        cant_alumnos++;
    rewind(f); // Vuelve al inicio del archivo

    // Asignar memoria sabiendo la cantidad de cant_alumnos
    nombres = (char* *) malloc(cant_alumnos*sizeof(char *));
    notas = (float *) malloc(cant_alumnos*sizeof(float));

    // Guarda los nombres y notas en los arreglos
    fgets(line, 1000, f); //Lee la primera linea de f (los parametros del csv) y lo guarda en line.
    while (fgets(line, 1000, f) != NULL) { //En este while se lee cada linea (completa) y se guarda en line
        field = strtok(line, ",");
        int cant_c = strlen(field);
        nombres[cont] = (char *) malloc(cant_c*sizeof(char));
        strcpy(nombres[cont],field);
        field = strtok(NULL, ",");
        sum = 0.0; //Variable para ir sumando las notas
        cant_notas = 0; //Contador para calcular la cantidad de notas
        while (field != NULL) { //El ciclo terminara cuando se termine la linea guardada en line
            sum += atof(field); //aotf() convierte un string en float doble. Ademas esta se le suma a sum para calcular el promedio.
            cant_notas++; 
            field = strtok(NULL, ",");      
        }
        notas[cont] = *(float *)malloc(10*sizeof(float));
        notas[cont] = sum/cant_notas;
        sum_students += sum / cant_notas; //Suma el promedio de un estudiante
        cont+=1; // avanza en el arreglo una posicion para guardar otro alumno
    }


    /* Ordenamiento */

    // Hacemos una copia del arreglo notas
    float notas_copia[cant_alumnos];
    copiararrays(notas,notas_copia,cant_alumnos);
    
    // Ordenamos copia del arreglo notas
    qsort (notas_copia,cant_alumnos,sizeof(float),compara);

    // Generamos los cambios en los arreglos originales (nombres y notas)
    buscar_swapear(notas,notas_copia,cant_alumnos,nombres);


    /* Mostramos por pantalla los alumnos con sus notas (ordenado) y el promedio final. */
    for(int i = 0; i<cant_alumnos;i++){
        printf("%s: %.1f\n",nombres[i],notas[i]);
    }
    printf("----------\nPromedio: %1.1f\n", sum_students / cant_alumnos);
}
