#include "Funciones.h"

int main(){
    MaxHeap_t *heap = Crear_heap();
    int opcion;
    const char *archivo = "alertas.txt";
    int cantidad;
    char respuesta[4];
    
    srand(time(NULL));

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
                printf("\nCargando alertas desde el archivo%s\n", archivo);
                Insertar_alertas_archivo(heap, archivo);
                break;
            case 6:
                printf("\nIngrese cuantas alertas quiere generar: ");
                if(scanf("%d", &cantidad)  < 1){
                    printf("Debe ser un numero entero positivo.\n");
                    while(getchar() != '\n'); 
                    break;
                }
                while(getchar() != '\n');

                printf("\nGenerando %d alertas en el archivo: %s...\n", cantidad, archivo);
                Generar_alertas_archivo(cantidad, archivo);
                break;
            case 7:
                printf("\nSaliendo del Sistema de Triage.\n");

                while(getchar() != '\n');

                printf("Desea borrar el archivo (alertas.txt) si/no: ");
                if(fgets(respuesta, sizeof(respuesta), stdin) != NULL){
                    respuesta[strcspn(respuesta, "\n")] = 0;
                    if(strcmp(respuesta, "si") == 0 || strcmp(respuesta, "SI") == 0 || strcmp(respuesta, "Si") == 0) {
                        printf("Limpiando el archivo %s...\n", archivo);
                        FILE *borrar = fopen(archivo, "w");
                        if(borrar != NULL) {
                            fclose(borrar);
                            printf("El archivo ha sido vaciado con éxito.\n");
                        }else{
                            printf("Advertencia: No se pudo limpiar el archivo");
                        }
                    }else{
                        printf("El archivo %s se conservará.\n", archivo);
                    }
                }

                printf("Liberando memoria...\n");
                break;
            default:
                printf("\nOpción no reconocida. Intente de nuevo.\n");
                break;
        }
    }while(opcion != 7);

    Liberar_heap(heap);
    return 0;
}