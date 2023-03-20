#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item;
typedef struct Elemento{
    item dato;
    struct Elemento *siguiente;
}nodo; 

void imprimir(nodo **cabeza);
void insertarPrimero(nodo **cabeza, item entrada);
nodo *crearNodo(item x);


/*
Lista simple ligada
cabeza -> 1 -> 2 -> 3->Null
*/
int main(){

    nodo *cabeza;
    cabeza = NULL;
    
    for(int i = 0; i< 30; i++)
        insertarPrimero(&cabeza, i);

    imprimir(&cabeza);

    
    
    


    return 0;
}
/*
**********************
Autor : Eduardo Bernal
Fecha : 19/03/2023
Descp : Inserta un nodo al principio
        de la lista (por la cabeza)
**********************
*/
void insertarPrimero(nodo **cabeza, item entrada){
    nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo -> siguiente = *cabeza;
    *cabeza = nuevo;

}
/*
**********************
Autor : Eduardo Bernal
Fecha : 19/03/2023
Descp : Crea un nodo y regresa la referencia del objeto
**********************
*/
nodo *crearNodo(item x){
    nodo *a;
    a = (nodo*)malloc(sizeof(nodo));
    a -> dato = x;
    a -> siguiente = NULL;
    return a;
}
/*
**********************
Autor : Eduardo Bernal
Fecha : 19/03/2023
Descp : Imprime la lista enlazada
**********************
*/
void imprimir(nodo **cabeza){
	nodo *ptr;
	ptr=*cabeza;
	printf("Inicio");
	for(;ptr->siguiente;){
		printf("->%d,", ptr->dato);
		ptr=ptr->siguiente;
	}

	printf("\n");
}