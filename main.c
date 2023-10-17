#include <stdio.h>
#include <stdlib.h>


typedef struct nodoArbol
{
    int dato;
    struct nodoArbol* derec;
    struct nodoArbol* izq;


} nodoArbol;

typedef struct {
     int legajo;
     char nombre[20]; 
     int edad; 
} persona;

nodoArbol* crearArbol (int infor);
nodoArbol* insertarDato (nodoArbol* arbol,int dato);
int cantHojas (nodoArbol* arbol);
void mostrarArbol(nodoArbol* arbol);
int cantGradoUno (nodoArbol* arbol);
int buscarDatoArbol(nodoArbol* arbol, int dato);
void mostrarMenorAMayor(nodoArbol* arbol);

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

    int cantidadGrado1 = cantGradoUno(arbol);
    printf("\nCANT GRADO 1: %i", cantidadGrado1);

    int datoBuscar;
    printf("Ingrese el dato a buscar: ");
    scanf("%i",&datoBuscar);

    int flagDato = buscarDatoArbol(arbol, datoBuscar);
    if(flagDato)
    {
        printf("\nSI ESTA EL DATO");
    }else
    {
        printf("\nNOOOOOO ESTA EL DATO");
    }
    
    
    
    
    
    

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


int cantGradoUno (nodoArbol* arbol)
{
    int cant=0;

    if(arbol->derec != NULL)
    {
        cant++;
    }

    if(arbol->izq != NULL)
    {
        cant++;
    }


return cant;
}


int buscarDatoArbol(nodoArbol* arbol, int dato)
{
    int flag;

    if(arbol!=NULL)
    {
        if(dato== arbol->dato)
        {
            flag=1;
        }else if (dato > arbol->dato)
        {
            flag= buscarDatoArbol(arbol->derec, dato);
        }else
        {
            flag= buscarDatoArbol(arbol->izq, dato);
        }

    }


return flag;
}

