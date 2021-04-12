#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum fin_lectura
{
    FIN_DE_CAMPO,
    FIN_DE_LINEA,
    FIN_DE_ARCHIVO,
    CANTIDAD
};

enum fin_lectura leer_campo(char *destino, int cantidad, FILE *fp)
{   
    int n = 0; // Contador.
    enum fin_lectura fin;
    while (1) // Ciclo permanente, solo se sale bruscamnete (break u otros).
    {
        char c = fgetc(fp);
        if (c == ',')
        {
            fin = FIN_DE_CAMPO;
            break;
        }
        if (c == '\n')
        {
            fin = FIN_DE_LINEA;
            break;
        }
        if (c == EOF)
        {
            fin = FIN_DE_ARCHIVO;
            break;
        }
        if (n + 1 >= cantidad)
        {
            fin = CANTIDAD;
            break;
        }
        destino[n] = c;
        n += 1;
    }

    destino[n] = '\0';
    return fin;
}

int main(int argc, char **argv)
{   
    
    int x=0;
    if (argc < 2) // Controlar que ingrese el nombre del archivo.
    {
        printf("Se debe indicar el nombre del archivo\n");
        return 1;
    }

    char *nombre_archivo = argv[1]; // Guarda el nombre del archivo en el puntero nombre_archivo. 

    FILE *fp = fopen(nombre_archivo, "r"); //Abre el archivo en el *fp.
    if (fp == NULL) //Controla que se abra correctamente el archivo
    {
        perror("No se pudo abrir el archivo");
        return 1;
    }
    
    // Declaramos variables
    float suma_curso = 0.0; 
    int cantidad_alumnos = 0;
    enum fin_lectura fin;
    
    do
    {
        //char nombre[50]; //Creamos un arreglo de 50.
        char* nombre;
        int  n = 255;
        
        //printf("%d\n",*n);
        nombre=(char*) malloc(255*sizeof(char));
        
        fin = leer_campo(nombre, n, fp); // Llamamos a la funcion leer_campo y la almacenamos en fin.
        printf("%c",fin);
        while(fin == CANTIDAD){
            int x =1;
            x++;
            n = n*x;
            nombre = realloc(nombre,n*sizeof(char));
            fin = leer_campo(nombre, n, fp);
        }
        if (fin == FIN_DE_ARCHIVO)
        {
            // no hay nombre, es una última línea en blanco
            break;
        }

        float suma = 0.0;
        int cantidad = 0;
        char buff[10];
        do
        {
            fin = leer_campo(buff, 10, fp);
            // si fin == CANTIDAD significa que el buffer es muy pequeño
            float nota = atof(buff);
            suma += nota;
            cantidad += 1;

        } while (fin != FIN_DE_ARCHIVO && fin != FIN_DE_LINEA);

        float promedio = suma / cantidad;
        suma_curso += promedio;
        cantidad_alumnos += 1;
        if(promedio!=0)
            printf("\n%s: %.1lf\n", nombre, promedio);
        
    } while (fin != FIN_DE_ARCHIVO);

    printf("\nPromedio: %.1lf\n\n", suma_curso / cantidad_alumnos);

    fclose(fp);

    return 0;
}