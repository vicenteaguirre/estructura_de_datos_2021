#include "funciones.h"
void print_avg_from_csv(FILE* f) {
  char line[1001];
  float sum = 0;
  float sum_students = 0;
  int count = 0;
  int count_students = 0;
  char* field;
  char matriz[400][400];
  int i=0,j=0;
  fgets(line, 1000, f);
  while (fgets(line, 1000, f) != NULL) {
    field = strtok(line, ",");
    matriz[i][j]= *field;
    printf("%s: ", field);
    field = strtok(NULL, ",");
    sum = 0.0;
    count = 0;
    j=1;
    while (field != NULL) {
      sum += atof(field);
      count++;
      field = strtok(NULL, ",");
    }
    float PE = (sum / count);
    matriz[i][j]= (float)PE;
    printf("%f\n", sum / count);
    i++;
    j=0;
    count_students++;
    sum_students += sum / count;
  }
  for (i=0;i<=count_students;i++){
      printf("%c:",matriz[i][0]);
      printf("%d ",matriz[i][1]);
      printf("\n");
    }


  printf("---\nPromedio: %f\n", sum_students / count_students);
}