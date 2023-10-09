#include <stdio.h>
#include <stdlib.h>


typedef struct nodoArbol
{
    int dato;
    struct nodoArbol* derec;
    struct nodoArbol* izq;


} nodoArbol;

nodoArbol* crearArbol (int infor);
nodoArbol* insertarDato (nodoArbol* arbol,int dato);
int cantHojas (nodoArbol* arbol);
void mostrarArbol(nodoArbol* arbol);

int main()
{
    nodoArbol* arbol=NULL;

    arbol= insertarDato(arbol,8);
    arbol= insertarDato(arbol,3);
    arbol= insertarDato(arbol,10);
    arbol= insertarDato(arbol,14);
    arbol= insertarDato(arbol,6);
    arbol= insertarDato(arbol,4);
    arbol= insertarDato(arbol,1);
    arbol= insertarDato(arbol,13);
    arbol= insertarDato(arbol,7);

    mostrarArbol(arbol);


    int cantidadHojas= cantHojas(arbol);
    printf("\nCANT HOJAS: %i", cantidadHojas);


    return 0;
}

nodoArbol* crearArbol (int infor)
{
    nodoArbol* aux= (nodoArbol*)malloc(sizeof (nodoArbol));
    aux->derec=NULL;
    aux->izq=NULL;
    aux->dato=infor;


    return aux;
}


nodoArbol* insertarDato (nodoArbol* arbol,int dato)
{

    if(arbol==NULL)
    {
        arbol= crearArbol(dato);
    }
    else
    {
        if(dato>arbol->dato)
            arbol->derec=insertarDato(arbol->derec, dato);
        else
            arbol->izq= insertarDato(arbol->izq, dato);
    }
    return arbol;
}

int cantHojas (nodoArbol* arbol)
{
    int i=0;

    if(arbol!=NULL)
    {
        if(arbol->izq==NULL && arbol->derec==NULL)
        {
            i=1;
        }
        else
        {
            i=i+cantHojas(arbol->izq);
            i=i+cantHojas(arbol->derec);
        }
    }

    return i ;
}

void mostrarArbol(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        printf("%d - ", arbol->dato);
        mostrarArbol(arbol->izq);
        mostrarArbol(arbol->derec);
    }
}
