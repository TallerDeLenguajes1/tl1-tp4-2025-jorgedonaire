#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea
{
    int TareaID; //numero autoincremental comenzando en 1000
    char *Descripcion;
    int Duracion; //entre 10 y 100
}Tarea;

typedef struct Nodo
{
    Tarea T;
    Nodo *Siguiente;
}Nodo;

Nodo *CrearListaVacia();
Nodo *CrearNodo();

int main()
{
    Nodo *Start;
    Start = CrearListaVacia();
    

    return 0;
}

Nodo *CrearListaVacia(){
    return NULL;
}

Nodo *CrearNodo(int idGenerado){
    Nodo *NuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    char *Buff;
    char *DescripcionIngresada;
    Buff = (char *) malloc(200*sizeof(char));
    printf("Ingrese la descripcion de la tarea: ");
    gets(Buff);

    DescripcionIngresada = (char *) malloc(strlen(Buff)+1 * sizeof(char));
    strcpy(DescripcionIngresada,Buff);

    NuevoNodo->T.Descripcion = DescripcionIngresada;

    int DuracionIngresada;
    printf("Ingrese la duracion de la tarea (10 - 100): ");
    scanf("%d", &DuracionIngresada);

    NuevoNodo->T.Duracion = DuracionIngresada;
    NuevoNodo->T.TareaID = idGenerado;
}