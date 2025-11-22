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
    printf("   SISTEMA DE TRIAGE DE DESASTRES NATURALES   \n");
    printf("==============================================\n");
    printf("1. Ingresar nueva alerta de desastre\n");
    printf("2. Procesar alerta de maxima prioridad\n");
    printf("3. Generar reporte ordenado por prioridad\n");
    printf("4. Saber que desastres naturales hay\n");
    printf("5. Ingresar archivo (alertas.txt) de alerta de desastre\n");
    printf("6. Crear archivo (alertas.txt) con alertas aleatorias\n");
    printf("7. Salir del sistema\n");
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
    printf("  Tipo de desastre:  %s\n", critica.desastre);
    printf("  Magnitud (Unidad):  %.2f %s\n", critica.magnitud, unidad);
    printf("  Ubicacion:  %s\n", critica.ubicacion);
    printf("  Puntaje de prioridad:  %d (max)\n", critica.prioridad);
    printf("  Orden de llegada:  %d\n", critica.orden_llegada);
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

    printf("\n==================================================================================================================================================================\n");
    printf("|                                                      REPORTE DE GESTION (ORDENADO POR PRIORIDAD: MAYOR A MENOR)                                                |\n");
    printf("==================================================================================================================================================================\n");
    printf("|      #       |        Desastre      |     Ubicacion   |             Magnitud (Unidad)          |          Afectados      |       Puntaje       | Orden Llegada |\n");
    printf("|--------------|----------------------|-----------------|----------------------------------------|-------------------------|---------------------|---------------|\n");

    for(int i = tamaño - 1; i >= 0; i--){ 
        unidad = Obtener_unidad(arr[i].desastre);
        sprintf(magnitud_con_unidad, "%.1f %s", arr[i].magnitud, unidad);

        printf("| %-12d | %-20s | %-15s | %-38s | %-23d | %-19d | %-13d |\n", 
        (tamaño - i), arr[i].desastre, arr[i].ubicacion, magnitud_con_unidad, arr[i].afectados, arr[i].prioridad, arr[i].orden_llegada);
    }
    printf("==================================================================================================================================================================\n");
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
    
    printf("\n=============================================================================================================================================================\n");
    printf("|                                CASOS DE DESASTRES NATURALES VALIDOS, NIVEL DE RIESGO Y VALORES DE PUNTUACIÓN BASE                                         |\n");
    printf("=============================================================================================================================================================\n");
    printf("|        Desastre      |         Magnitud (Unidad)      |                            Rangos de Magnitud -> Puntos Base (VALORES)                            |\n");
    printf("|----------------------|--------------------------------|----------------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < num_desastres; i++){
        const char *unidad = Obtener_unidad(desastres[i]);
        const char *rangos_puntos = Obtener_rangos(desastres[i]);
        
        printf("| %-20s | %-30s | %-97s |\n", desastres[i], unidad, rangos_puntos);
    }
    
    printf("|----------------------|--------------------------------|----------------------------------------------------------------------------------------------------\n");
    printf("NOTA: La Prioridad Total = Puntos Base * Poblacion Afectada.\n");
}

float random_float(float min, float max){ // generador de numeros aleatorios
    return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

int random_int(int min, int max){
    if (min == max) return min;
    return rand() % (max - min + 1) + min;
}

void Insertar_alertas_archivo(MaxHeap_t *m, const char *nombre_archivo){
    FILE *archivo = fopen(nombre_archivo, "r");
    if(archivo == NULL) return;

    char linea[512];
    int alertas_insertadas = 0;
    int linea_actual = 0;

    printf("\n--- Insertando Alertas desde '%s' ---\n", nombre_archivo);

    while(fgets(linea, sizeof(linea), archivo) != NULL){
        linea_actual++;
        linea[strcspn(linea, "\n")] = 0; //elimina salto de linea

        if(linea[0] == '\0') continue;  //ver si la linea esta vacia

        Alerta_t nueva; //los datos esperados son: ubicacion;desastre;magnitud;afectados
        char *token;
        char *resto_linea = linea;

        token = strsep(&resto_linea, ";"); //ubicacion
        if(token == NULL || strlen(token) >= 255){
            printf("Error en linea %d. Saltando.\n", linea_actual);
            continue;
        }
        strcpy(nueva.ubicacion, token);

        token = strsep(&resto_linea, ";"); //desastre
        if(token == NULL){
            printf("Error en linea %d. Saltando.\n", linea_actual);
            continue;
        }
        if(!Verificar_desastre(token)){//verificar el desastre
            printf("Error en Linea %d: El desastre '%s' no es un tipo valido. Saltando.\n", linea_actual, token);
            continue;
        }
        strcpy(nueva.desastre, token);

        token = strsep(&resto_linea, ";"); //magnitud
        if(token == NULL || sscanf(token, "%f", &nueva.magnitud) != 1){
            printf("Error en linea %d. Saltando.\n", linea_actual);
            continue;
        }

        token = strsep(&resto_linea, ";"); //afectados
        if(token == NULL || sscanf(token, "%d", &nueva.afectados) != 1){
            printf("Error en linea %d. Saltando.\n", linea_actual);
            continue;
        }

        Insertar(m, nueva);
        alertas_insertadas++;
    }
    fclose(archivo);
    printf("Proceso finalizado. Se insertaron %d alertas con exito.\n", alertas_insertadas);
}

void Generar_alertas_archivo(int num_ejemplos, const char *nombre_archivo){
    
    int num_desastres = sizeof(desastres) / sizeof(desastres[0]);
    
    const char *ubicaciones[] = {
        "Ciudad A", "Pueblo B", "Region C", "Zona D", "Norte E", 
        "Sur F", "Este G", "Oeste H", "Capital I", "Costera J"
    };
    int num_ubicaciones = sizeof(ubicaciones) / sizeof(ubicaciones[0]);

    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) return;
    
    srand(time(NULL));

    printf("\n--- Generando %d Alertas en '%s' ---\n", num_ejemplos, nombre_archivo);
    printf("Archivo de alertas masivas generado.\n");
    printf("Formato: Ubicacion;Desastre;Magnitud;Afectados\n");

    for (int i = 0; i < num_ejemplos; i++){
        char ubicacion[255];
        char desastre[255];
        float magnitud;
        int afectados;

        sprintf(ubicacion, "%s-%d", ubicaciones[random_int(0, num_ubicaciones - 1)], random_int(1, 999));

        strcpy(desastre, desastres[random_int(0, num_desastres - 1)]);

        if(strcmp(desastre, "Terremoto") == 0){
            magnitud = random_float(1.0, 10.0);
        }else if(strcmp(desastre, "Tsunami") == 0){
            magnitud = random_float(1.0, 15.0);
        }else if(strcmp(desastre, "Huracan") == 0 || strcmp(desastre, "Ciclon") == 0){
            magnitud = random_float(100.0, 300.0);
        }else if(strcmp(desastre, "Erupcion Volcanica") == 0){
            magnitud = random_int(1, 7);
        }else if(strcmp(desastre, "Sequia") == 0){
            magnitud = random_float(-3.0, 0.0);
        }else if(strcmp(desastre, "Incendio") == 0){
            magnitud = random_int(1, 10000);
        }else if(strcmp(desastre, "Tornado") == 0){
            magnitud = random_float(100.0, 400.0);
        }else if(strcmp(desastre, "Inundacion") == 0){
            magnitud = random_float(0.1, 5.0);
        }else if(strcmp(desastre, "Avalancha") == 0){
            magnitud = random_int(10, 10000);
        } else if(strcmp(desastre, "Vendaval") == 0){
            magnitud = random_float(50.0, 150.0);
        }

        if(random_int(1, 10) <= 9){ //numero de afectados 
            afectados = random_int(100, 50000);
        }else{ 
            afectados = random_int(50001, 5000000);
        }
        
        
        fprintf(archivo, "%s;%s;%.1f;%d\n", ubicacion, desastre, magnitud, afectados); //escribir al archivo en el formato correcto: Ubicacion;Desastre;Magnitud;Afectados
    }

    fclose(archivo);
    printf("Proceso finalizado. Se generaron %d alertas en '%s' con éxito.\n", num_ejemplos, nombre_archivo);
}