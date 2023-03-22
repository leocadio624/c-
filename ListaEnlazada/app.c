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
void imprimir2(nodo *cabeza);
nodo *localizar(nodo *cabeza, item destino);
nodo *buscarPosicion(nodo *cabeza, item posicion);
void eliminarNodo(nodo **cabeza, item entrada);

/*
Lista simple ligada
cabeza -> 1 -> 2 -> 3->Null
*/
int main(){

    nodo *cabeza, *ultimo;
    cabeza = NULL;
    
    nodo *puntero = NULL;
    
    for(int i = 0; i<= 10; i++)
        insertarPrimero(&cabeza, i);
    
    
    insertarFinal(&cabeza, 555);
    insertarFinal(&cabeza, 556);
    imprimir2(cabeza);



    int nodo_buscado = 5;
    puntero = localizar(cabeza, nodo_buscado);
    printf("\nBuscar por valor: %d\n", nodo_buscado);
    if(puntero == NULL)
        printf("No se encontro el valor en la lista\n");
    else
        printf("Valor de nodo->dato: %d\n", puntero->dato);
    

    printf("\nBuscar por posicion: %d\n", nodo_buscado);
    puntero = buscarPosicion(cabeza, nodo_buscado);
    if(puntero == NULL)
        printf("No se encontro el valor en la lista\n");
    else
        printf("Valor de nodo->dato: %d\n", puntero->dato);

    printf("\nElimina por valor: %d\n", nodo_buscado);
    eliminarNodo(&cabeza, nodo_buscado);
    eliminarNodo(&cabeza, 0);
    
    imprimir2(cabeza);
    
    

    
    
    
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
pasando el puntero cabeza por valor
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
/*
**********************
Autor : Eduardo Bernal
Fecha : 19/03/2023
Descp : Otra forma de imprimis lista con
ciclo while
**********************
*/
void imprimir2(nodo *cabeza){

	printf("\n\t\t Lista ordenada \n");
    while(cabeza != NULL){
        printf(" %d", cabeza->dato);
        cabeza = cabeza -> siguiente;
    }

	printf("\n");
}
/*
**********************
Autor : Eduardo Bernal
Fecha : 19/03/2023
Descp : Localiza un nodo por su valor,
retorna un puntero de nodo localizado
**********************
*/
nodo *localizar(nodo *cabeza, item destino){
    nodo *indice;
    for(indice = cabeza; indice != NULL; indice = indice -> siguiente)
        if(indice -> dato == destino)
            return indice;
    return NULL;

}
/*
**********************
Autor : Eduardo Bernal
Fecha : 21/03/2023
Descp : Localiza un nodo por su indice
en la lista, retorna un puntero a dicho nodo
**********************
*/
nodo *buscarPosicion(nodo *cabeza, item posicion){

    nodo *indice;
    if(posicion < 1) return NULL;

    indice = cabeza;
    for(item i=1; (i < posicion) && (indice != NULL); i++)
        indice = indice -> siguiente;

    return indice;

}

void eliminarNodo(nodo **cabeza, item entrada){

    nodo *actual, *anterior;
    int encontrado = 0;

    actual = *cabeza, anterior = NULL;

    while((actual != NULL) && (!encontrado)){

        encontrado = (actual -> dato == entrada);

        if(!encontrado){
            anterior = actual;
            actual = actual -> siguiente;
        }

    }

    if(actual != NULL){
        if(actual == *cabeza)
            *cabeza = actual -> siguiente;
        else
            anterior -> siguiente = actual ->siguiente;

        free(actual);
    }

}

