#include<stdio.h>


void cargar(int *a, int *b){
    *a = 100;
    *b = 200;

    int *puntero = &(*a);
    printf("%p\n", puntero);
    //*a += 1;
    //printf("%d\n", *a);
    //printf("%d\n", *b);
    

}
void paso(int **puntero){

    //printf("%p\n", *puntero);
    //printf("%d\n", **puntero);

    int aux = **puntero + 1;
    printf("%d\n", aux);
    

}


int main(){
    
    int a=1, b=0;

    int *puntero = &a;

    
    printf("%d\n", *puntero);
    printf("%p\n", puntero);
    printf("%p\n", &a);

    paso(&puntero);

    /*
    */

    
    /*
    printf("%i %i\n", a, b);
    printf("%p\n", &a);
    cargar(&a, &b);
    printf("%i %i\n", a, b);
    */
    
    
    

    return 0;


}
