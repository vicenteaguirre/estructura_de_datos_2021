#include "func2.h"
#include "ejemploqsort.c"
void funcion(FILE * f){
    char line[1001]; // Creamos un array donde se guardara la linea donde esta leyendo el archivo
    float sum = 0; //
    float sum_students = 0; //Suma las notas promedios de los estudiantes.
    int count = 0;
    int count_students = 0; //Cuenta la cantidad de estudiantes que hay en el archivo para calcular el promedio del curso
    char * field;
    char * * nombres = (char* *) malloc(255*sizeof(char *));
    float * notas = (float *) malloc(255*sizeof(float));
    int cont = 0;
    float promedio;

    fgets(line, 1000, f); //Lee la primera linea de f (los parametros del csv) y lo guarda en line.
    while (fgets(line, 1000, f) != NULL) { //En este while se lee cada linea (completa) y se guarda en line
        field = strtok(line, ","); //Para poder separar el nombre de las notas debemos usar el strtok
                                    //strtok(variable a la cual se realiza el strtok, "," signf que leera hasta obtener una coma.)
        int cant_c = strlen(field);
        nombres[cont] = (char *) malloc(cant_c*sizeof(char));
        strcpy(nombres[cont],field);
        field = strtok(NULL, ",");
        sum = 0.0; //Variable para ir sumando las notas
        count = 0; //Contador para calcular la cantidad de notas
        while (field != NULL) { //El ciclo terminara cuando se termine la linea guardada en line
            sum += atof(field); //aotf() convierte un string en float doble. Ademas esta se le suma a sum para calcular el promedio.
            count++; 
            field = strtok(NULL, ",");      
        }
        notas[cont] = *(float *)malloc(10*sizeof(float));
        notas[cont] = sum/count;
        count_students++; //Suma un estudiante
        sum_students += sum / count; //Suma el promedio de un estudiante
        cont+=1;
    }
    /*for(int i = 0; i<count_students;i++){
        printf("%s: %f\n",nombres[i],notas[i]);
    }
*/
    int largo=sizeof(notas)/sizeof(float);
    float notas_copia[largo];

    printf("Aqui comienza el ordenamiento\n");
    
    printf("Esta es la copia no ordenada\n");
    copiararrays(notas,notas_copia,largo);
    for (int i=0;i<=largo;i++){
        printf("%.2f  ",notas_copia[i]);
    }
    qsort (notas_copia,largo+1,sizeof(float),compara);
    printf("\nEsta es la copia ordenada\n");
    for (int i=0;i<=largo;i++){
        printf("%.2f  ",notas_copia[i]);
    }
    buscar_swapear(notas,notas_copia,largo+1,nombres);
    


    //buscar_swapear();
    printf("\n-----------------\n");
    /* Ahora ordenar los arreglos */




    
    for(int i = 0; i<=largo;i++){
        printf("%s: %f\n",nombres[i],notas[i]);
    }
    printf("---\nPromedio: %1.1f\n", sum_students / count_students);
}

/*
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 */
    /* create temp arrays */
    //int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    /*for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 */
    /* Merge the temp arrays back into arr[l..r]*/
    /* 
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 */
    /* Copy the remaining elements of L[], if there
    are any */
    /* 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 */
    /* Copy the remaining elements of R[], if there
    are any */
    /* 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 */
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
/* 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}*/
 /* */
/* UTILITY FUNCTIONS */
/* Function to print an array */
/* 
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 */
/* Driver code */
/* 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
} */