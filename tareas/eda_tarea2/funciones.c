#include "funciones.h"
void print_sort(FILE* f) {
  char line[1001]; // Creamos un array donde se guardara la linea donde esta leyendo el archivo
  float sum = 0; //
  float sum_students = 0; //Suam las notas promedios de los estudiantes.
  int count = 0;
  int count_students = 0; //Cuenta la cantidad de estudiantes que hay en el archivo para calcular el promedio del curso
  char * field;
  fgets(line, 1000, f); //Lee la primera linea de f (los parametros del csv) y lo guarda en line.
  while (fgets(line, 1000, f) != NULL) { //En este while se lee cada linea (completa) y se guarda en line
    field = strtok(line, ","); //Para poder separar el nombre de las notas debemos usar el strtok
                               //strtok(variable a la cual se realiza el strtok, "," signf que leera hasta obtener una coma.)
    printf("%s: ", field); //Imprime la variable field la cual tiene la linea leida hasta la coma, lo cual es el nombre del alumno
    field = strtok(NULL, ","); //Cuando se usa strtok queda el resto del string apuntado por un puntero, al llamar de nuevo a strtok(NULL, "delimiter"), este usara el string que quedo del strtok pasado.
    sum = 0.0; //Variable para ir sumando las notas
    count = 0; //Contador para calcular la cantidad de notas
    while (field != NULL) { //El ciclo terminara cuando se termine la linea guardada en line
      sum += atof(field); //aotf() convierte un string en float doble. Ademas esta se le suma a sum para calcular el promedio.
      count++; 
      field = strtok(NULL, ",");
    }
    printf("%f\n", sum / count); //Calcula el promedio
    count_students++; //Suma un estudiante
    sum_students += sum / count; //Suma el promedio de un estudiante
  }
  printf("---\nPromedio: %f\n", sum_students / count_students);
}