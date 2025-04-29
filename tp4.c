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
Nodo *CrearNodo(int idGenerado);
void InsertarNodo(Nodo **Start, Nodo *NodoInsertado);
// void EliminarNodo2(Nodo *nodoEliminado);
void *EliminarNodoPorID(Nodo **Start, int id);
Nodo * extraerNodoDeLista(Nodo **Start, int id);
void MostrarListas(Nodo **Start);

int main()
{
    Nodo *TareasPendientes = CrearListaVacia();
    Nodo *TareasRealizadas = CrearListaVacia();
    int bandera, idIngresado;
    int i = 0;

    printf("***** SISTEMA *****\n");
    printf("\n");
    printf("***** Carga de Tareas *****\n");

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
    


    printf("***** MARCAR TAREAS COMO REALIZADAS *****\n");
    printf("Ingrese el ID de la tarea que desea marcar como realizada: ");
    scanf("%d",&idIngresado);
    InsertarNodo(&TareasRealizadas,extraerNodoDeLista(&TareasPendientes,idIngresado));


    printf("********** TAREAS PENDIENTES ************\n");
    MostrarListas(&TareasPendientes);
    printf("\n");
    printf("********** TAREAS REALIZADAS ************\n");
    MostrarListas(&TareasRealizadas);
    printf("\n");
    
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
    free(Buff);
    NuevoNodo->T.Descripcion = DescripcionIngresada;

    int DuracionIngresada;
    printf("Ingrese la duracion de la tarea (10 - 100): ");
    scanf("%d", &DuracionIngresada);

    NuevoNodo->T.Duracion = DuracionIngresada;
    NuevoNodo->T.TareaID = idGenerado;

    NuevoNodo->Siguiente = NULL;
    return NuevoNodo;
    free(DescripcionIngresada);
}

void InsertarNodo(Nodo **Start, Nodo *NodoInsertado){
    NodoInsertado->Siguiente = *Start; //el nodo insertado apunto a donde apunta el comienzo de la lista, osea el 1er nodo
    *Start = NodoInsertado; // el comienzo de la lista apunto al nodo insertado
}

void *EliminarNodoPorID(Nodo **Start, int id){ //inicio de la lista, puntero doble
    Nodo ** aux = Start;
    while (aux != NULL && (*aux)->T.TareaID != id)
    {
        aux = &(*aux)->Siguiente;
    }

    if (*aux)
    {
        Nodo * temp = aux;
        *aux = (*aux)->Siguiente;
    }
    return NULL;
}

Nodo * extraerNodoDeLista(Nodo **Start, int id){
    Nodo *aux = *Start;
    Nodo *nodoExtraido = (Nodo *) malloc (sizeof(Nodo));

    while (aux && aux->T.TareaID != id)
    {
        aux = aux->Siguiente;
    }

    if (aux == NULL)
    {
        printf("No se encontro la tarea con el id solicitado");
        return NULL;
    }
    nodoExtraido->T.Duracion = aux->T.Duracion;
    nodoExtraido->T.TareaID = aux->T.TareaID;
    nodoExtraido->T.Descripcion = (char *)malloc (strlen(aux->T.Descripcion) + 1 *sizeof(char *));
    strcpy(nodoExtraido->T.Descripcion, aux->T.Descripcion);

    EliminarNodoPorID(Start,id);
    return nodoExtraido;
}

void MostrarListas(Nodo **Start){
    Nodo *aux = *Start;
    while (aux != NULL)
    {
        printf("\n");
        printf("Tarea ID: %d\n", aux->T.TareaID);
        printf("Descripcion: %s\n", aux->T.Descripcion);
        printf("Duracion: %d\n", aux->T.Duracion);
        printf("-------");
        aux = aux->Siguiente;
    }
    
}
// void EliminarNodo2(Nodo *nodoEliminado){
//     if (nodoEliminado)
//     {
//         free(nodoEliminado);
//     }
// }