// Función recursiva
#include <stdio.h>
#include <math.h>

int func1(int n){
    if(n == 0){
        return n;
    }

    return n + func1(n-1);
}
/*int func2(int n){
    
    
}*/
int func3(int x){
    if(x == 0){
        return x;
    }
    int resto = x%10;
    int cant = (int)pow(10,(int)log10(x));
    x /= 10;
    printf("resto: %d\n",resto);
    x = (resto * cant) + x;
    printf("x: %d\n",x);
    return func3(x);
}

int main(int argc,char**argv)
{
    //int x = 5432;
    //printf("%d\n",x%10);
    int a = func3(5432);
    printf("%d\n",a);
    return 0;
}