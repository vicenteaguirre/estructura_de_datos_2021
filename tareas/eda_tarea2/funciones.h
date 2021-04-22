#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdalign.h>

int compara(const void *p,const void *q);
void copiararrays(float *a,float *b, int size);
void swap(char** nombres,float * original,int eje_i,int eje_j);
int buscar_swapear(float * original,float * ordenado, int size,char** nombres);
void print_sorted(FILE * f);