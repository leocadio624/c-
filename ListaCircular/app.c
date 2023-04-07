#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item;
typedef struct Elemento{
    item dato;
    struct Elemento *siguiente;
}nodo;
/*
**********************
Autor : Eduardo Bernal
Fecha : 07/04/2023
Descp : Crea un nodo
**********************
*/
nodo *crearNodo(item x){
    nodo *a;
    a = (nodo *)malloc(sizeof(nodo));
    a -> dato = x;
    a -> siguiente = a;
    return a;
}
/*
**********************
Autor : Eduardo Bernal
Fecha : 07/04/2023
Descp : Inserta un elemento en una lista circular
**********************
*/
void insertarCircular(nodo **lc, item entrada){
    nodo *nuevo;
    nuevo = crearNodo(entrada);

    if(*lc != NULL){
        nuevo -> siguiente = (*lc) -> siguiente;
        (*lc) -> siguiente = nuevo;
    }
    *lc = nuevo;

}

/*
**********************
Autor : Eduardo Bernal
Fecha : 22/03/2023
Descp : Recorre una lista circular
**********************
*/
void recorrer(nodo *lc){
    nodo *p;

    if(lc != NULL){

        printf("\n\tElementos de la lista circular\n");
        p = lc -> siguiente; /*Se recorre la lista a partir del primer nodo*/
        do {

            printf("%d ",p -> dato);
            p = p -> siguiente;


        }while(p != lc -> siguiente);
        printf("\n");
    }


}

/*
**********************
Autor : Eduardo Bernal
Fecha : 07/04/2023
Descp : Implementacion basica
de una lista circular
**********************
*/
int main(){

    
    nodo *lc;
    lc = NULL;

    insertarCircular(&lc, 55);
    insertarCircular(&lc, 56);
    insertarCircular(&lc, 57);

    recorrer(lc);
    


    return 0;
}