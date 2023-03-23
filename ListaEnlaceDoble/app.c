#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item;
typedef struct Elemento{
    item dato;
    struct Elemento *siguiente;
    struct Elemento *atras;
}nodo;


void insertarPrimero(nodo **cabeza, item entrada);
void recorrer(nodo *puntero);
nodo *crearNodo(item x);

int main(){

    nodo *cabeza;
    cabeza = NULL;

    for(int i = 0; i<= 10; i++)
        insertarPrimero(&cabeza, i);

    recorrer(cabeza);

    return 0;
}

/*
**********************
Autor : Eduardo Bernal
Fecha : 22/03/2023
Descp : Crea un nodo y regresa la referencia del objeto
**********************
*/
void insertarPrimero(nodo **cabeza, item entrada){

    nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo -> siguiente = *cabeza;
    nuevo -> atras = NULL;

    if( (*cabeza) != NULL)
        (*cabeza) -> atras = nuevo;
    
    *cabeza = nuevo;
    
}

/*
**********************
Autor : Eduardo Bernal
Fecha : 22/03/2023
Descp : Recorre una lista doblemente enlazada
**********************
*/
void recorrer(nodo *puntero){
    //int k = 0;
    printf("\n\tElementos de la lista\n");

    for(;puntero;){

        printf("%d ",puntero -> dato);
        puntero = puntero -> siguiente;
    }

    printf("\n");
}


/*
**********************
Autor : Eduardo Bernal
Fecha : 22/03/2023
Descp : Inserta un nodo en la primer posicion 
a la que apunta cabeza
**********************
*/
nodo *crearNodo(item x){
    nodo *a;
    a = (nodo*)malloc(sizeof(nodo));
    a -> dato = x;
    a -> atras = a -> siguiente = NULL;
    return a;
}