#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

int compara(const void *p,const void *q){
    int x,y;
    x= *(int*)p;
    y= *(int*)q;
    if (x<y)
        return -1;
    if (x==y)
        return 0;
    else 
        return 1;
}

void copiararrays(float *a,float *b, int size){
    for (int i =0;i<=size;i++){
        b[i]=a[i];
    }
    
}
void swap(char** nombres,int eje_i,int eje_j){
    char aux[1000];
    *aux=*nombres[eje_j]; //indice "Danilo"
    *nombres[eje_j] = *nombres[eje_i];
    *nombres[eje_i] = *aux;
    return;
}
int buscar_swapear(float * original,float * ordenado, int size,char** nombres  ){
    for (int i=0;i<= size ;i++){
        for (int j=0;j<= size ;j++){
            if (original[i]==ordenado[j]) //para nombre i se busca la nota respecto a j
                swap(nombres,i,j);
    
        }
    }
    return 0;
}
/*int main(void){ 
    float arreglo[]= {1, 53.3, 40.5, 700.1, 2.3, 42.6, 84.15};
    int largo=sizeof(arreglo)/sizeof(float);
    float arreglo1[largo];
    
    copiararrays(arreglo,arreglo1,largo);
    
    qsort (arreglo1,largo,sizeof(float),compara);
    int i;
    for (i=0;i<largo;i++){
        printf("%.2f  ",arreglo1[i]);
    }*/




