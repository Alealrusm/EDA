#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alerta{ //estructura que represesenta una alerta de desastre con la prioridad
    char ubicacion[255];
    char desastre[255];
    float magnitud;
    int afectados;

    int orden_llegada;
    int prioridad;
}Alerta_t;

typedef struct MaxHeap{ //para la cola de prioridad
    Alerta_t *alerta;
    int capacidad;
    int tamaño;
    int contador; //contador para el orden_llegada
}MaxHeap_t;

typedef struct Desastre{ //el catalogo de desastre y sus factores base 
    char nombre[255];
    int factor; //factor para calcular la prioridad
}Desastre_t;

MaxHeap_t *Crear_heap();
void Liberar_heap(MaxHeap_t *m);
void Cambiar(Alerta_t *a, Alerta_t *b);
int Mayor(Alerta_t a, Alerta_t b);

int Calcular_prioridad(const char *tipo_desastre, float magnitud, int poblacion);

void Heapify_up(MaxHeap_t *m, int indice);
void Heapify_down(MaxHeap_t *m, int indice);
void Insertar(MaxHeap_t *m, Alerta_t nueva_alerta);
Alerta_t Extraer(MaxHeap_t *m);

#endif