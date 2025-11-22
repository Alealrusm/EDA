#include "Funciones.h"

int main(){
    MaxHeap_t *heap = Crear_heap();
    int opcion;

    do{
        Menu();
        if(scanf("%d", &opcion) != 1){
            printf("\nOpción invalida. Intente de nuevo.\n");
            opcion = 0; 
            while(getchar() != '\n'); 
        }

        switch(opcion){
            case 1:
                Insertar_alerta(heap);
                break;
            case 2:
                Alerta_critica(heap);
                break;
            case 3:
                Generar_reporte(heap); //Algoritmo Heap Sort (O(n log n))
                break;
            case 4:
                Mostrar_desastres();
                break;
            case 5:
                printf("\nSaliendo del Sistema de Triage. Liberando memoria...\n");
                break;
            default:
                printf("\nOpción no reconocida. Intente de nuevo.\n");
                break;
        }
    }while(opcion != 5);

    Liberar_heap(heap);
    return 0;
}