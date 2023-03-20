#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int item;
typedef struct Elemento{
    item dato;
    struct Elemento *siguiente;
}nodo; 

void insertarPrimero(nodo **cabeza, item entrada);
void insertarFinal(nodo **cabeza, item entrada);
nodo *crearNodo(item x);
void imprimir(nodo *cabeza);


/*
Lista simple ligada
cabeza -> 1 -> 2 -> 3->Null
*/
int main(){

    nodo *cabeza, *ultimo;
    cabeza = NULL;
    
    
    for(int i = 0; i<= 5; i++)
        insertarPrimero(&cabeza, i);
    

    
    insertarFinal(&cabeza, 555);
    insertarFinal(&cabeza, 556);
    
    
    
    

    imprimir(cabeza);
    
    //printf("%p\n", cabeza->siguiente);
    
    

    
    


    /*
    ultimo = cabeza;
    for(; ultimo -> siguiente;){
        ultimo = ultimo -> siguiente;
        printf("\n %d \n", ultimo-> dato);
    }
    */


    
    

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
Descp : Inserta un nodo al principio
        de la lista (por la cabeza)
**********************
*/
void insertarFinal(nodo **cabeza, item entrada){
    nodo *ultimo;
    ultimo = *cabeza;

    if(ultimo == NULL){
        *cabeza = crearNodo(entrada);
    }else{

        for(; ultimo -> siguiente; ){
            ultimo = ultimo -> siguiente;
        }

        ultimo -> siguiente = crearNodo(entrada);
        
    }


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
void imprimir(nodo *cabeza){

	int k;
	printf("\n\t\t Lista ordenada \n");
	for(k=0; cabeza; cabeza = cabeza -> siguiente){
		printf(" %d", cabeza->dato);
	}
    
    

	printf("\n");
}