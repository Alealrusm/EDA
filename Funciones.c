#include "Funciones.h"

const char *Obtener_unidad(const char *tipo_desastre){
    if (strcmp(tipo_desastre, "Terremoto") == 0) return "Richter";
    if (strcmp(tipo_desastre, "Tsunami") == 0) return "metros (Altura ola)";
    if (strcmp(tipo_desastre, "Huracan") == 0 || strcmp(tipo_desastre, "Ciclon") == 0) return "km/h (Viento)";
    if (strcmp(tipo_desastre, "Erupcion Volcanica") == 0) return "VEI (Indice explosividad)";
    if (strcmp(tipo_desastre, "Sequia") == 0) return "SPI (Indice de precipitacion)";
    if (strcmp(tipo_desastre, "Incendio") == 0) return "ha (Hectareas afectadas)";
    if (strcmp(tipo_desastre, "Tornado") == 0) return "km/h (Viento)";
    if (strcmp(tipo_desastre, "Inundacion") == 0) return "metros (Profundidad)";
    if (strcmp(tipo_desastre, "Avalancha") == 0) return "m^3 (Volumen)";
    if (strcmp(tipo_desastre, "Vendaval") == 0) return "km/h (Viento)";
    return "N/A";
}
const char *Obtener_nivel(const char *tipo_desastre){
    if(strcmp(tipo_desastre, "Tsunami") == 0) return "Nivel I (Critico)";
    if(strcmp(tipo_desastre, "Erupcion Volcanica") == 0) return "Nivel I (Critico)";
    if(strcmp(tipo_desastre, "Terremoto") == 0) return "Nivel I (Critico)"; 
    if(strcmp(tipo_desastre, "Huracan") == 0 || strcmp(tipo_desastre, "Ciclon") == 0) return "Nivel II (Alto)";
    if(strcmp(tipo_desastre, "Tornado") == 0) return "Nivel II (Alto)";
    if(strcmp(tipo_desastre, "Inundacion") == 0) return "Nivel II (Alto)";
    if(strcmp(tipo_desastre, "Incendio") == 0) return "Nivel III (Medio)";
    if(strcmp(tipo_desastre, "Avalancha") == 0) return "Nivel III (Medio)";
    if(strcmp(tipo_desastre, "Sequia") == 0) return "Nivel III (Medio)";
    if(strcmp(tipo_desastre, "Vendaval") == 0) return "Nivel IV (Bajo)";
    return "N/A";
}
const char *Obtener_rangos(const char *tipo_desastre){
    static char rangos[250]; 
    rangos[0] = '\0'; 

    if(strcmp(tipo_desastre, "Terremoto") == 0){
        sprintf(rangos, "  1-4: 1.8 Puntos     |  4-7: 2.5 Puntos      |  7-9: 6.0 Puntos        |  9+: 10.0 Puntos     ");
    }
    if(strcmp(tipo_desastre, "Tsunami") == 0){
        sprintf(rangos, "  1-2: 1.5 Puntos     |  2-5: 4.0 Puntos      |  5-10: 8.0 Puntos       |  10+: 9.5 Puntos     ");
    }
    if(strcmp(tipo_desastre, "Huracan") == 0 || strcmp(tipo_desastre, "Ciclon") == 0){
        sprintf(rangos, "  119-152: 1.2 Puntos |  152-208: 3.0 Puntos  |  208-251: 6.5 Puntos    |  251+: 9.0 Puntos    ");
    }
    if(strcmp(tipo_desastre, "Erupcion Volcanica") == 0){
        sprintf(rangos, "  1-2: 2.0 Puntos     |  3: 4.5 Puntos        |  4-5: 7.5 Puntos        |  6+: 9.8 Puntos      ");
    }
    if(strcmp(tipo_desastre, "Sequia") == 0){
        sprintf(rangos, " <-1: 1.0 Puntos      |  -1 a -1.5: 3.5 Puntos|  -1.5 a -2: 7.0 Puntos  |  >-2: 8.5 Puntos     ");
    }
    if(strcmp(tipo_desastre, "Incendio") == 0){
        sprintf(rangos, "  0-100: 2.6 Puntos   |  100-1000: 3.2 Puntos |  1000-10000: 6.8 Puntos |  10000+: 8.8 Puntos  ");
    }
    if(strcmp(tipo_desastre, "Tornado") == 0){
        sprintf(rangos, "  105-178: 1.3 Puntos |  178-265: 2.5 Puntos  |  265-323: 5.5 Puntos    |  323+: 8.2 Puntos    ");
    }
    if(strcmp(tipo_desastre, "Inundacion") == 0){
        sprintf(rangos, "  0-1m: 1.8 Puntos    |  1-2.5m: 2.2 Puntos   |  2.5-4m: 4.8 Puntos     |  4+m: 7.5 Puntos     ");
    }
    if(strcmp(tipo_desastre, "Avalancha") == 0){
        sprintf(rangos, "  0-100: 1.5 Puntos   |  100-1000: 2.0 Puntos |  1000-10000: 5.0 Puntos |  10000+: 7.8 Puntos  ");
    }
    if(strcmp(tipo_desastre, "Vendaval") == 0){
        sprintf(rangos, "  50-70: 0.4 Puntos   |  70-100: 1.8 Puntos   |  100-130: 4.2 Puntos    |  130+: 6.2 Puntos    ");
    }
    return rangos;
}
const char *desastres[] = {
        "Terremoto", "Tsunami", "Huracan", "Ciclon", "Erupcion Volcanica", 
        "Sequia", "Incendio", "Tornado", "Inundacion", "Avalancha", "Vendaval"
};

void Menu(){
    printf("\n==============================================\n");
    printf("     SISTEMA DE TRIAGE DE DESASTRES NATURALES\n");
    printf("==============================================\n");
    printf("1. Ingresar nueva alerta de desastre\n");
    printf("2. Procesar alerta de maxima prioridad\n");
    printf("3. Generar reporte ordenado por prioridad\n");
    printf("4. Saber que desastres naturales hay\n");
    printf("5. Salir del sistema\n");
    printf("Ingrese su opcion: ");
}

int Verificar_desastre(const char *tipo_desastre){
    int num_desastres = sizeof(desastres) / sizeof(desastres[0]);

    for(int i = 0; i < num_desastres; i++){
        if (strcmp(tipo_desastre, desastres[i]) == 0){
            return 1;
        }
    }
    return 0;
}

void Insertar_alerta(MaxHeap_t *m){
    Alerta_t nueva;
    const char *unidad;

    printf("\n--- Ingreso de Nueva Alerta ---\n");
    while(getchar() != '\n'); 
    printf("Ingrese la ubicacion: ");

    if(fgets(nueva.ubicacion, 50, stdin) == NULL) return;
    nueva.ubicacion[strcspn(nueva.ubicacion, "\n")] = 0;

    do{
        printf("Tipo de desastre: ");
        if(fgets(nueva.desastre, 255, stdin) == NULL) return; 
        nueva.desastre[strcspn(nueva.desastre, "\n")] = 0;
        
        if(Verificar_desastre(nueva.desastre)){
            unidad = Obtener_unidad(nueva.desastre);
            break; 
        }else{
            printf("Error: El desastre '%s' no es un tipo válido.\n", nueva.desastre);
            printf("Consulte la Opción 4 para ver la lista de desastres aceptados.\n");
            return;
        }
    }while (1);

    printf("Magnitud del desastre en %s: ", unidad);
    if(scanf("%f", &nueva.magnitud) != 1){
        printf("Error de lectura de magnitud.\n");
        while(getchar() != '\n'); 
        return;
    }

    printf("Poblacion afectada (estimada): ");
    if(scanf("%d", &nueva.afectados) != 1){
        printf("Error de lectura de poblacion.\n");
        while(getchar() != '\n'); 
        return;
    }

    Insertar(m, nueva);
    printf("\nAlerta de %s en %s ingresada con exito.\n", nueva.desastre, nueva.ubicacion);
}

void Alerta_critica(MaxHeap_t *m){
    if(m->tamaño == 0){
        printf("\nNo hay alertas\n");
        return;
    };

    Alerta_t critica = Extraer(m);
    const char *unidad = Obtener_unidad(critica.desastre);

    printf("\n==============================================\n");
    printf("      ALERTA DE MAXIMA PRIORIDAD EXTRAIDA   \n");
    printf("==============================================\n");
    printf("  Tipo de desastre: %s\n", critica.desastre);
    printf("  Magnitud (Unidad): %.2f %s\n", critica.magnitud, unidad);
    printf("  Ubicacion:        %s\n", critica.ubicacion);
    printf("  Puntaje de prioridad: %d (max)\n", critica.prioridad);
    printf("  Orden de llegada:   %d\n", critica.orden_llegada);
    printf("==============================================\n");
}

void Heapify_down_temporal(Alerta_t *arr, int tamaño, int indice){ //puede ordenar el arr de las alertas, sirve para el reporte 
    int maximo = indice;
    int derecha = 2 * indice + 1;
    int izquierda = 2 * indice + 2;

    if(izquierda < tamaño && Mayor(arr[izquierda], arr[maximo])){
        maximo = izquierda;
    }
    if(derecha < tamaño && Mayor(arr[derecha], arr[maximo])){
        maximo = derecha;
    }
    if(maximo != indice){
        Cambiar(&arr[indice], &arr[maximo]);
        Heapify_down_temporal(arr, tamaño, maximo);
    }
}

void HeapSort_reporte(Alerta_t *alerta, int tamaño){
    for(int i = (tamaño / 2) - 1; i >= 0; i--){ //construir el HeapSort
        Heapify_down_temporal(alerta, tamaño, i);
    }
    for(int i = tamaño - 1; i > 0; i--){ //ordena de menor a mayor
        Cambiar(&alerta[0], &alerta[i]);
        Heapify_down_temporal(alerta, i, 0);
    }
}

Alerta_t *Copiar_alertas(MaxHeap_t *m, int *alertas){
    *alertas = m->tamaño;
    if(*alertas == 0) return NULL;

    Alerta_t *copia = (Alerta_t *)malloc(sizeof(Alerta_t) * (*alertas));
    memcpy(copia, m->alerta, sizeof(Alerta_t) * (*alertas));

    return copia;

}

void Imprimir_alertas(Alerta_t *arr, int tamaño){
    char magnitud_con_unidad[25]; 
    const char *unidad;

    printf("\n===================================================================================================================\n");
    printf("|                              REPORTE DE GESTION (ORDENADO POR PRIORIDAD: MAYOR A MENOR)                         |\n");
    printf("===================================================================================================================\n");
    printf("|  #  | Desastre       | Ubicacion       | Magnitud (Unidad) |     Afectados     |       Puntaje       | Orden L. |\n");
    printf("|-----|----------------|-----------------|-------------------|-------------------|---------------------|----------|\n");

    for(int i = tamaño - 1; i >= 0; i--){ 
        unidad = Obtener_unidad(arr[i].desastre);
        sprintf(magnitud_con_unidad, "%.1f %s", arr[i].magnitud, unidad);

        printf("| %-3d | %-14s | %-15s | %-17s | %-17d | %-19d | %-8d |\n", 
        (tamaño - i), arr[i].desastre, arr[i].ubicacion, magnitud_con_unidad, arr[i].afectados, arr[i].prioridad, arr[i].orden_llegada);
    }
    printf("===================================================================================================================\n");
}

void Generar_reporte(MaxHeap_t *m){
    if(m->tamaño == 0){ 
        printf("\nNo hay alertas\n");
        return;
    }

        int alertas;
    Alerta_t *copia = Copiar_alertas(m, &alertas);

    if(copia){
        HeapSort_reporte(copia, alertas); 
        Imprimir_alertas(copia, alertas);
        
        free(copia); 
    }
}

void Mostrar_desastres(){
    
    int num_desastres = sizeof(desastres) / sizeof(desastres[0]);
    
    printf("\n==================================================================================================================================================================================\n");
    printf("|                                              CASOS DE DESASTRES NATURALES VALIDOS, NIVEL DE RIESGO Y VALORES DE PUNTUACIÓN BASE                                                |\n");
    printf("==================================================================================================================================================================================\n");
    printf("|        DESASTRE      |   NIVEL DE RIESGO  |       UNIDAD DE MAGNITUD       |                            Rangos de Magnitud -> Puntos Base (VALORES)                            |\n");
    printf("|----------------------|--------------------|--------------------------------|----------------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < num_desastres; i++){
        const char *unidad = Obtener_unidad(desastres[i]);
        const char *nivel = Obtener_nivel(desastres[i]); 
        const char *rangos_puntos = Obtener_rangos(desastres[i]);
        
        printf("| %-20s | %-18s | %-30s | %-97s |\n", desastres[i], nivel, unidad, rangos_puntos);
    }
    
    printf("|----------------------|--------------------|--------------------------------|----------------------------------------------------------------------------------------------------\n");
    printf("NOTA: La Prioridad Total = Puntos Base * Poblacion Afectada.\n");
}