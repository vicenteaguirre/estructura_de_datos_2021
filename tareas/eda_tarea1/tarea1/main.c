#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef struct {
    // Buffer con el contenido. Siempre está terminado en \0
    char* contenido;
    unsigned long capacidad;
} String;

String iniciar_string() {
    const unsigned capacidad_inicial = 16;

    String resultado = {
        .contenido = calloc(capacidad_inicial, sizeof(char)),
        .capacidad = capacidad_inicial
    };
    
    return resultado;
}

// Agrega el nuevo contenido al final del string existente.
void agregar_string(String *s, const char *texto, int cantidad) {
    unsigned long longitud = strlen(s->contenido);

    // si no hay capacidad suficiente, agrandar el buffer
    if (longitud + cantidad >= s->capacidad) {
        // +1 para reservar también para el byte nulo.
        // Se puede usar una estrategia de redimensionado distinta, por ejemplo
        // aproximando a la potencia de 2 inmediatamente superior.
        unsigned long nueva_capacidad = longitud + cantidad + 1;
        s->contenido = realloc(s->contenido, nueva_capacidad * sizeof(char));
        s->capacidad = nueva_capacidad;
    }

    s->contenido = strncat(s->contenido, texto, cantidad);
}

void limpiar_string(String *s) {  
    strcpy(s->contenido, "");
}

void liberar_string(String *s) {
    free(s->contenido);
    s->contenido = NULL;
    s->capacidad = 0;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

enum fin_lectura
{
    FIN_DE_CAMPO,
    FIN_DE_LINEA,
    FIN_DE_ARCHIVO
};

enum fin_lectura leer_campo(String *destino, FILE *fp)
{   
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

        char str[] = { c };
        agregar_string(destino, str, 1);
    }

    return fin;
}

int main(int argc, char **argv)
{   
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
    
    float suma_curso = 0.0; 
    int cantidad_alumnos = 0;
    enum fin_lectura fin;
    String nombre = iniciar_string();        
    String texto_nota = iniciar_string();

    do
    {    
        fin = leer_campo(&nombre, fp);

        if (fin == FIN_DE_ARCHIVO)
        {
            // no hay nombre, es una última línea en blanco
            break;
        }

        float suma = 0.0;
        int cantidad = 0;
        do
        {
            fin = leer_campo(&texto_nota, fp);
            float nota = atof(texto_nota.contenido);
            suma += nota;
            cantidad += 1;
            limpiar_string(&texto_nota);
        } while (fin != FIN_DE_ARCHIVO && fin != FIN_DE_LINEA);

        float promedio = suma / cantidad;
        suma_curso += promedio;
        cantidad_alumnos += 1;

        if(promedio != 0) 
        {
            printf("%s: %.1lf\n", nombre.contenido, promedio);
        }
            
        limpiar_string(&nombre);

    } while (fin != FIN_DE_ARCHIVO);

    printf("\nPromedio: %.1lf\n\n", suma_curso / cantidad_alumnos);

    fclose(fp);
    liberar_string(&nombre);
    liberar_string(&texto_nota);

    return 0;
}