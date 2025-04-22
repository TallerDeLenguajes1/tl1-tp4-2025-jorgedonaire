#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea
{
    int TareaID; //numero autoincremental comenzando en 1000
    char *Descripcion;
    int Duracion; //entre 10 y 100
}typedef Tarea;

typedef struct Nodo Nodo;
struct Nodo
{
    Tarea T;
    Nodo *Siguiente;
};

Nodo *CrearListaVacia();
Nodo *CrearNodo();
void InsertarNodo(Nodo **Start, Nodo *NodoInsertado);

int main()
{
    Nodo *TareasPendientes = CrearListaVacia();
    int bandera;
    int i = 0;

    do
    {
        Nodo * NuevaTarea = CrearNodo(1000 + i);
        InsertarNodo(&TareasPendientes, NuevaTarea);
        i++;
        printf("1. Ingresar nueva tarea. \n");
        printf("0. Finalizar carga.\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &bandera);
    } while (bandera != 0);
    
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
    fflush(stdin);
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

    NuevoNodo->Siguiente = NULL;
    return NuevoNodo;
}

void InsertarNodo(Nodo **Start, Nodo *NodoInsertado){
    NodoInsertado->Siguiente = *Start; //el nodo insertado apunto a donde apunta el comienzo de la lista, osea el 1er nodo
    *Start = NodoInsertado; // el comienzo de la lista apunto al nodo insertado
}