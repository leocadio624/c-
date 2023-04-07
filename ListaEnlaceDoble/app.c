#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item;
typedef struct Elemento{
    item dato;
    struct Elemento *siguiente;
    struct Elemento *atras;
}nodo;


void insertarPosicion(nodo **cabeza, item buscado, item entrada);
void insertarPrimero(nodo **cabeza, item entrada);
void recorrer(nodo *puntero);
nodo *crearNodo(item x);

int main(){

    nodo *cabeza;
    cabeza = NULL;

    for(int i = 0; i<= 5; i++){
        insertarPrimero(&cabeza, i);
    }
    recorrer(cabeza);

    insertarPosicion(&cabeza, 5, 555);
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
void insertarPosicion(nodo **cabeza, item buscado, item entrada){

    nodo *anterior, *actual;
    nodo *nuevo;

    int encontrado = 0;
    anterior = actual = *cabeza;


    while((actual != NULL) && (!encontrado)){
        encontrado = (actual -> dato == buscado);

        if(!encontrado){
            anterior = actual;
            actual = actual -> siguiente;
        }

    }

    if(encontrado){
        printf("Insertando nodo: %d\n", entrada);
        nuevo = crearNodo(entrada);
        nuevo -> siguiente = anterior -> siguiente;

        if(anterior -> siguiente != NULL)
            anterior -> siguiente -> atras = nuevo;

        anterior -> siguiente = nuevo;
        nuevo -> atras = anterior;


    }else{
        printf("No se encontro el nodo\n");
    }

    /*
    while((puntero -> siguiente != NULL) && (puntero -> dato != buscado)){

        anterior = puntero;
        puntero = puntero -> siguiente;

    }
    printf("%d\n", anterior -> dato);
    */

    /*
    if(encontrado == NULL){
        printf("Encontrado es null\n");
    }
    */

    
    


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