#include "Estructuras.h"

const char *Obtener_unidad(const char *tipo_desastre);
const char *Obtener_rangos(const char *tipo_desastre);
void Menu();

int Verificar_desastre(const char *tipo_desastre);
void Insertar_alerta(MaxHeap_t *m);

void Alerta_critica(MaxHeap_t *m);

void Heapify_down_temporal(Alerta_t *arr, int tamaño, int indice);
void HeapSort_reporte(Alerta_t *alerta, int tamaño);
Alerta_t *Copiar_alertas(MaxHeap_t *m, int *alertas);
void Imprimir_alertas(Alerta_t *arr, int tamaño);
void Generar_reporte(MaxHeap_t *m);

void Mostrar_desastres();

void Insertar_alertas_archivo(MaxHeap_t *m, const char *nombre_archivo);
void Generar_alertas_archivo(int num_ejemplos, const char *nombre_archivo);