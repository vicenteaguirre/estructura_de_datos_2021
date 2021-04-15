#include "funciones.h"
Nodo * crearNodo(Alumno * alumno){
    Nodo * nodo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->alumno.nombre,alumno->nombre);
    nodo->alumno.nota = alumno->nota;
    nodo->siguiente = NULL;
    return nodo;
}
void mostrar_alumnos(Nodo * ptr){
    while(ptr != NULL){
        printf("%s : ",ptr->alumno.nombre);
        printf("%f\n",ptr->alumno.nota);
        ptr = ptr->siguiente;
    }
    printf("\n");
} 
void print_sort(FILE* f) {
    Nodo * lista = (Nodo *)malloc(sizeof(Nodo));
    Alumno * alumno = (Alumno *)malloc(sizeof(Alumno));
    char line[1001]; // Creamos un array donde se guardara la linea donde esta leyendo el archivo
    float sum = 0; //
    float sum_students = 0; //Suma las notas promedios de los estudiantes.
    int count = 0;
    int count_students = 0; //Cuenta la cantidad de estudiantes que hay en el archivo para calcular el promedio del curso
    char * field;
    fgets(line, 1000, f); //Lee la primera linea de f (los parametros del csv) y lo guarda en line.
    while (fgets(line, 1000, f) != NULL) { //En este while se lee cada linea (completa) y se guarda en line
        printf("HolaWhile");
        field = strtok(line, ","); //Para poder separar el nombre de las notas debemos usar el strtok
                                    //strtok(variable a la cual se realiza el strtok, "," signf que leera hasta obtener una coma.)
        alumno->nombre = field;//Imprime la variable field la cual tiene la linea leida hasta la coma, lo cual es el nombre del alumno
        printf("HolaNombre");
        //printf("\n\n%s\n\n",alumno1.nombre);
        field = strtok(NULL, ","); //Cuando se usa strtok queda el resto del string apuntado por un puntero, al llamar de nuevo a strtok(NULL, "delimiter"), este usara el string que quedo del strtok pasado.
        sum = 0.0; //Variable para ir sumando las notas
        count = 0; //Contador para calcular la cantidad de notas
        while (field != NULL) { //El ciclo terminara cuando se termine la linea guardada en line
        sum += atof(field); //aotf() convierte un string en float doble. Ademas esta se le suma a sum para calcular el promedio.
        count++; 
        field = strtok(NULL, ",");
        }
        //Nodo * nodo = (Nodo *)malloc(sizeof(Nodo));
        //printf("\n\n%3.1f\n\n",alumno1.nota_promedio);
        //printf("%f\n", sum / count); //Calcula el promedio
        count_students++; //Suma un estudiante
        sum_students += sum / count; //Suma el promedio de un estudiante
        crearNodo(alumno);
    }
    mostrar_alumnos(lista);
    printf("---\nPromedio: %f\n", sum_students / count_students);
    
    typedef struct persona{
        char nombress;
        int notass;
        
    }Persona;
    for (int i=0;i<count_students;i++){
        Persona i;
    }
    //Persona 1;
}